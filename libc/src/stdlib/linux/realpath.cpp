//===-- Implementation of realpath ----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/stdlib/realpath.h"
#include "hdr/func/free.h"
#include "hdr/func/malloc.h"
#include "hdr/unistd_macros.h"
#include "src/__support/CPP/optional.h"
#include "src/__support/CPP/string_view.h"
#include "src/__support/OSUtil/filesystem.h"
#include "src/__support/char_vector.h"
#include "src/__support/common.h"
#include "src/__support/error_or.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/__support/sso_buffer.h"
#include "src/string/memory_utils/inline_memcpy.h"
#include "src/string/memory_utils/inline_memmove.h"
#include "src/string/string_length.h"
#include <linux/limits.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {

namespace {

// A buffer for path strings.
//
// Unlikely to have paths with length greater than 256 bytes,
// so use SSOBuffer, which starts on the stack and spills
// to the heap when necessary.
//
// We don't use static buffers of size PATH_MAX,
// since some systems allow dynamic sizing for the maximum path length.
// Futher, there is no restriction that the maximum length on a system
// is a reasonable size.
using PathBuffer = SSOBuffer<512>;

// Maximum number of symlinks to follow when resolving a path.
// TODO: look this up.
constexpr size_t kMaxSymlinkFollows = 40;

struct Success {};
using MaybeError = ErrorOr<Success>;

constexpr char kPathSep = '/';

LIBC_INLINE bool is_absolute_path(cpp::string_view path) {
  return path.starts_with(kPathSep);
}

// Builder for canonical paths.
//
// The path held by this class is always:
// - Absolute (starts at the filesystem root).
// - Devoid of symlinks.
// - Without a trailing '/'.
// - Null terminated.
// - Shorter than the provided `path_max`.
class CanonicalPath {
  size_t size_ = 0;
  size_t path_max_;
  PathBuffer buf_;

public:
  CanonicalPath(size_t path_max) : path_max_(path_max) {
    set_to_filesystem_root();
  }

  cpp::string_view view() const { return cpp::string_view(buf_.data(), size_); }
  size_t size() const { return size_; }

  ErrorOr<char *> release() {
    char *res = buf_.release();
    size_ = 0;
    if (res == nullptr)
      return Error(ENOMEM);
    return res;
  }

  // Adds a path component.
  // The component must be non-empty and devoid of `/` separators.
  //
  // For example, `push_component("component")` mutates PathBuilder
  // so that `/path/to/dir` -> `/path/to/dir/component`.
  MaybeError push_component(cpp::string_view component) {
    // need to add a separator if we're not pointing at the root.
    bool needs_sep = size_ > 1;

    // +1 to account for null-terminator.
    size_t required_capacity = size_ + component.size() + needs_sep + 1;

    if (required_capacity > path_max_)
      return Error(ENAMETOOLONG);

    if (!buf_.reserve(required_capacity))
      return Error(ENOMEM);

    if (needs_sep) {
      buf_[size_] = kPathSep;
      size_++;
    }

    inline_memcpy(&buf_[size_], component.data(), component.size());
    size_ += component.size();

    null_terminate();
    return Success{};
  }

  void pop_component() {
    size_t idx = view().find_last_of(kPathSep);
    if (idx == 0 || idx == cpp::string_view::npos) {
      set_to_filesystem_root();
      return;
    }

    size_ = idx;
    null_terminate();
  }

  void set_to_filesystem_root() {
    static_assert(PathBuffer::kInitialSize >= 2);
    buf_[0] = kPathSep;
    size_ = 1;
    null_terminate();
  }

  MaybeError set_to_cwd() {
    ErrorOr<int> res = internal::getcwd(buf_.data(), buf_.capacity());
    while (!res && res.error() == ERANGE) {
      if (buf_.capacity() > path_max_)
        return Error(ENAMETOOLONG);

      if (!buf_.reserve(2 * buf_.capacity()))
        return Error(ENOMEM);

      res = internal::getcwd(buf_.data(), buf_.capacity());
    }

    if (!res)
      return Error(res.error());

    size_ = internal::string_length(buf_.data());
    return Success{};
  }

  const char *c_str() const { return buf_.data(); }

private:
  void null_terminate() { buf_[size_] = '\0'; }
};

class PathComponentStack {
  size_t start_ = 0;
  size_t end_ = 0;
  const size_t path_max_;
  PathBuffer buf_;

  cpp::string_view active_data() {
    return cpp::string_view(buf_.data(), end_).substr(start_);
  }

public:
  PathComponentStack(size_t path_max) : path_max_(path_max) {}

  // Returned exactly to your original, clean design.
  cpp::string_view pop() {
    cpp::string_view active = active_data();
    size_t slash_idx = active.find_first_of(kPathSep);

    if (slash_idx == cpp::string_view::npos) {
      start_ = end_;
    } else {
      start_ += slash_idx + 1;
    }

    return active.substr(0, slash_idx);
  }

  bool empty() const { return start_ == end_; }

  MaybeError push_components(const cpp::string_view path) {
    if (path.empty())
      return Success{};

    cpp::string_view active = active_data();
    bool requires_sep = !path.ends_with(kPathSep) && !active.empty() &&
                        !active.starts_with(kPathSep);

    // FIX 3: If pushing a path with a trailing slash onto an empty stack,
    // append a virtual "." to trigger the directory check in the resolve loop.
    bool add_dot = path.ends_with(kPathSep) && active.empty();

    size_t sep_size = (requires_sep ? 1 : 0);
    size_t dot_size = (add_dot ? 1 : 0);
    size_t new_size = path.size() + sep_size + dot_size + active.size();

    if (new_size > path_max_)
      return Error(ENAMETOOLONG);

    if (!buf_.reserve(new_size))
      return Error(ENOMEM);

    active = active_data(); // Re-validate view

    inline_memmove(&buf_[path.size() + sep_size + dot_size], active.data(),
                   active.size());
    inline_memcpy(buf_.data(), path.data(), path.size());

    if (add_dot) {
      buf_[path.size()] = '.';
    }

    if (requires_sep) {
      buf_[path.size() + dot_size] = kPathSep;
    }

    start_ = 0;
    end_ = new_size;

    return Success{};
  }
};

class ReadlinkBuffer {
  size_t path_max_;
  PathBuffer buf_;

public:
  ReadlinkBuffer(size_t path_max) : path_max_(path_max) {}

  ErrorOr<cpp::string_view> readlink(const char *link) {
    ErrorOr<ssize_t> size =
        internal::readlink(link, buf_.data(), buf_.capacity());

    while (size.has_value() && static_cast<size_t>(*size) == buf_.capacity()) {
      if (buf_.capacity() > path_max_)
        return Error(ENAMETOOLONG);

      if (!buf_.reserve(2 * buf_.capacity()))
        return Error(ENOMEM);

      size = internal::readlink(link, buf_.data(), buf_.capacity());
    }

    if (!size)
      return Error(size.error());

    return cpp::string_view(buf_.data(), static_cast<size_t>(*size));
  }
};

MaybeError resolve(CanonicalPath &builder,
                   PathComponentStack &unresolved_components,
                   ReadlinkBuffer &readlink_buffer) {
  size_t symlinks_followed = 0;

  while (!unresolved_components.empty()) {
    cpp::string_view component = unresolved_components.pop();

    // "//" and "/./" are both treated as the current directory.
    if (component.empty() || component == ".")
      continue;

    // ".." moves towards the root by one directory.
    if (component == "..") {
      builder.pop_component();
      continue;
    }

    MaybeError res = builder.push_component(component);
    if (!res)
      return res;

    struct stat st;
    ErrorOr<int> lstat_res = internal::lstat(builder.c_str(), &st);
    if (!lstat_res)
      return Error(lstat_res.error());

    if (S_ISLNK(st.st_mode)) {
      if (symlinks_followed >= kMaxSymlinkFollows)
        return Error(ELOOP);
      symlinks_followed++;

      ErrorOr<cpp::string_view> target =
          readlink_buffer.readlink(builder.c_str());
      if (!target)
        return Error(target.error());

      if (is_absolute_path(*target)) {
        builder.set_to_filesystem_root();
      } else {
        // If link points to a relative path,
        // pop the symlink and continue relative to the link.
        builder.pop_component();
      }

      MaybeError push_res = unresolved_components.push_components(*target);
      if (!push_res)
        return push_res;

      continue;
    }

    if (!unresolved_components.empty() && !S_ISDIR(st.st_mode))
      return Error(ENOTDIR);
  }

  return Success{};
}

ErrorOr<char *> realpath_impl(const char *__restrict path_c_str,
                              char *__restrict resolved) {
  if (path_c_str == nullptr)
    return Error(EINVAL);

  cpp::string_view path(path_c_str);
  if (path.empty())
    return Error(ENOENT);

  const size_t path_max = PATH_MAX;

  CanonicalPath resolved_builder(path_max);
  if (!is_absolute_path(path)) {
    auto res = resolved_builder.set_to_cwd();
    if (!res)
      return Error(res.error());
  }

  PathComponentStack unresolved_components(path_max);
  auto res = unresolved_components.push_components(path);
  if (!res)
    return Error(res.error());

  ReadlinkBuffer readlink_buffer(path_max);

  res = resolve(resolved_builder, unresolved_components, readlink_buffer);
  if (!res)
    return Error(res.error());

  // If `resolved` was nullptr, just return the allocated string.
  if (resolved == nullptr) {
    return resolved_builder.release();
  }

  // Otherwise, copy into resolved.
  inline_memcpy(resolved, resolved_builder.c_str(),
                resolved_builder.size() + 1);
  return resolved;
}

} // namespace

LLVM_LIBC_FUNCTION(char *, realpath,
                   (const char *__restrict path, char *__restrict resolved)) {
  ErrorOr<char *> res = realpath_impl(path, resolved);
  if (!res) {
    libc_errno = res.error();
    return nullptr;
  }
  return res.value();
}

} // namespace LIBC_NAMESPACE_DECL

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
#include "src/__support/CPP/string_view.h"
#include "src/__support/OSUtil/filesystem.h"
#include "src/__support/common.h"
#include "src/__support/error_or.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/__support/macros/sanitizer.h"
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

// Builder for the resolved path.
//
// The path held by this class is always:
// - Absolute (starts at the filesystem root).
// - Devoid of symlinks.
// - Without a trailing '/'.
// - Null terminated.
// - Shorter than the provided `path_max`.
class ResolvedPath {
  size_t size_ = 0;
  size_t path_max_;
  char *user_buf_;
  PathBuffer buf_;

public:
  ResolvedPath(char *resolved, size_t path_max)
      : path_max_(path_max), user_buf_(resolved) {
    set_to_filesystem_root();
  }

  cpp::string_view view() const { return cpp::string_view(data(), size_); }
  size_t size() const { return size_; }

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

    if (!reserve(required_capacity))
      return Error(ENOMEM);

    if (needs_sep) {
      data()[size_] = kPathSep;
      size_++;
    }

    inline_memcpy(data() + size_, component.data(), component.size());
    size_ += component.size();

    null_terminate();
    return Success{};
  }

  // Pops a path component.
  //
  // For example, may mutate `/path/to/component` -> `/path/to`.
  // If the path is at filesystem root, this is a no-op.
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
    data()[0] = kPathSep;
    size_ = 1;
    null_terminate();
  }

  MaybeError set_to_cwd() {
    ErrorOr<int> res = internal::getcwd(data(), capacity());
    while (!res && res.error() == ERANGE) {
      if (capacity() >= path_max_)
        return Error(ENAMETOOLONG);

      if (!reserve(2 * capacity()))
        return Error(ENOMEM);

      res = internal::getcwd(data(), capacity());
    }

    if (!res)
      return Error(res.error());
    
    size_t bytes_written = static_cast<size_t>(*res);
    MSAN_UNPOISON(data(), bytes_written);
    size_ = bytes_written - 1;
    return Success{};
  }

  const char *c_str() const {
    // We maintain that the internal buffer is null-terminated,
    // so safe to return as-is.
    return data();
  }

  ErrorOr<char *> release() {
    size_ = 0;

    if (user_buf_ != nullptr) {
      char *res = user_buf_;
      user_buf_ = nullptr;
      return res;
    }

    char *res = buf_.release();
    if (res == nullptr)
      return Error(ENOMEM);

    return res;
  }

private:
  void null_terminate() { data()[size_] = '\0'; }

  size_t capacity() const {
    return user_buf_ != nullptr ? path_max_ : buf_.capacity();
  }

  char *data() const { return user_buf_ != nullptr ? user_buf_ : buf_.data(); }

  bool reserve(size_t size) {
    if (user_buf_ != nullptr)
      return size <= path_max_;

    return buf_.reserve(size);
  }
};

// Path that has yet to be resolved.
//
// This is just a normal POSIX path,
// but with accessors that allow prepending_path and
// Used to track unprocessed components of a user's `realpath` query.
class PendingPath {
  // buf_ stores the components that need to be processed.
  // It's represented just as a normal POSIX path.
  //
  // "popping" from the stack advances start_ past a path component.
  // "pushing" to the stack prepends the path with new components.
  PathBuffer buf_;

  // Path components is stored in buf_[start_ ... buf_.capacity() - 1].
  size_t start_;

  const size_t path_max_;

  cpp::string_view active_path() const {
    return cpp::string_view(buf_.data() + start_, buf_.capacity() - start_);
  }

public:
  PendingPath(size_t path_max) : start_(buf_.capacity()), path_max_(path_max) {}

  // Yields the next path component,
  // starting from the components closest to root.
  cpp::string_view next_component() {
    cpp::string_view path = active_path();

    size_t start_idx = path.find_first_not_of(kPathSep);
    if (start_idx == cpp::string_view::npos) {
      start_ += path.size();
      return "";
    }

    size_t end_idx = path.find_first_of(kPathSep, start_idx);
    if (end_idx == cpp::string_view::npos) {
      end_idx = path.size();
    }

    start_ += end_idx;
    return path.substr(start_idx, end_idx - start_idx);
  }

  bool empty() const { return start_ == buf_.capacity(); }

  // Prepends `PendingPath` with `path`.
  MaybeError prepend(const cpp::string_view path) {
    if (path.empty())
      return Success{};

    cpp::string_view active = active_path();
    bool requires_sep = !path.ends_with(kPathSep) && !active.empty() &&
                        !active.starts_with(kPathSep);

    size_t sep_size = (requires_sep ? 1 : 0);
    size_t added_size = path.size() + sep_size;
    size_t new_size = added_size + active.size();

    if (new_size > path_max_)
      return Error(ENAMETOOLONG);

    if (new_size > buf_.capacity()) {
      size_t old_start = start_;
      size_t active_size = active.size();
      if (!buf_.reserve(new_size))
        return Error(ENOMEM);

      // Move data to the end of the new buffer.
      size_t new_cap = buf_.capacity();
      inline_memmove(buf_.data() + (new_cap - active_size),
                     buf_.data() + old_start, active_size);
      start_ = new_cap - active_size;
    }

    start_ -= added_size;
    inline_memcpy(buf_.data() + start_, path.data(), path.size());

    if (requires_sep) {
      buf_[start_ + path.size()] = kPathSep;
    }

    return Success{};
  }
};

// Reads `link` and returns its target as a string_view backed by `buf`.
ErrorOr<cpp::string_view> readlink(const char *link, PathBuffer &buf,
                                   size_t path_max) {
  ErrorOr<ssize_t> ssize = internal::readlink(link, buf.data(), buf.capacity());

  // While the target may have been truncated...
  while (ssize.has_value() && static_cast<size_t>(*ssize) == buf.capacity()) {
    if (buf.capacity() > path_max)
      return Error(ENAMETOOLONG);

    if (!buf.reserve(2 * buf.capacity()))
      return Error(ENOMEM);

    ssize = internal::readlink(link, buf.data(), buf.capacity());
  }

  if (!ssize)
    return Error(ssize.error());

  size_t size = static_cast<size_t>(*ssize);
  MSAN_UNPOISON(buf.data(), size);
  return cpp::string_view(buf.data(), size);
}

MaybeError resolve(ResolvedPath &out, PendingPath &pending_path,
                   size_t path_max) {
  PathBuffer readlink_buf;
  size_t symlinks_followed = 0;

  while (!pending_path.empty()) {
    cpp::string_view component = pending_path.next_component();

    // "//" and "/./" are both treated as the current directory.
    if (component.empty() || component == ".")
      continue;

    // ".." moves towards the root by one directory.
    if (component == "..") {
      out.pop_component();
      continue;
    }

    MaybeError res = out.push_component(component);
    if (!res)
      return res;

    // TODO: Check if accessible?
    struct stat st;
    ErrorOr<int> lstat_res = internal::lstat(out.c_str(), &st);
    if (!lstat_res)
      return Error(lstat_res.error());

    if (S_ISLNK(st.st_mode)) {
      if (symlinks_followed >= kMaxSymlinkFollows)
        return Error(ELOOP);
      symlinks_followed++;

      ErrorOr<cpp::string_view> target =
          readlink(out.c_str(), readlink_buf, path_max);
      if (!target)
        return Error(target.error());

      if (is_absolute_path(*target)) {
        out.set_to_filesystem_root();
      } else {
        // If link points to a relative path,
        // pop the symlink and continue relative to the link.
        out.pop_component();
      }

      MaybeError push_res = pending_path.prepend(*target);
      if (!push_res)
        return push_res;

      continue;
    }

    // If there's more to resolve but we're not looking a file,
    // the traversal should fail, e.g `realpath("/path/to/file.txt/")`
    // should fail.
    if (!pending_path.empty() && !S_ISDIR(st.st_mode))
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

  // TODO: initialize with `pathconf` if needed.
  size_t path_max = PATH_MAX;

  // A builder for the resolved path.
  ResolvedPath resolved_path(resolved, path_max);
  if (!is_absolute_path(path)) {
    auto res = resolved_path.set_to_cwd();
    if (!res)
      return Error(res.error());
  }

  // Stack for resolving each component in `path`.
  PendingPath pending_path_path(path_max);
  auto res = pending_path_path.prepend(path);
  if (!res)
    return Error(res.error());

  res = resolve(resolved_path, pending_path_path, path_max);
  if (!res)
    return Error(res.error());

  return resolved_path.release();
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

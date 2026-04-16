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
#include "src/__support/common.h"
#include "src/__support/error_or.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/string/memory_utils/inline_memcpy.h"
#include "src/string/memory_utils/inline_memmove.h"
#include "src/string/string_length.h"
#include <linux/limits.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {

namespace {

constexpr size_t kMaxSymlinkFollows = 40;

struct monostate {};

// Type alias for clearer function signatures.
using MaybeError = ErrorOr<monostate>;

// Constructor for non-errors.
MaybeError ok() { return monostate{}; }

// Builder for canonical paths.
class PathBuilder {
public:
  static ErrorOr<PathBuilder> AtCurrentWorkingDir(char *buffer,
                                                  size_t capacity) {
    auto res = internal::getcwd(buffer, capacity);
    if (!res) {
      return Error(res.error());
    }
    size_t length = internal::string_length(buffer);
    return PathBuilder(buffer, length, capacity);
  }

  static ErrorOr<PathBuilder> AtRootDir(char *buffer, size_t capacity) {
    PathBuilder builder = PathBuilder(buffer, 0, capacity);
    MaybeError res = builder.reset("/");
    if (!res) {
      return Error(res.error());
    }
    return builder;
  }

  cpp::string_view view() const { return {buf, len}; }

  MaybeError push_component(cpp::string_view comp) {
    size_t add = (len > 1 ? 1 : 0) + comp.size();
    if (len + add + 1 > cap) {
      return Error(ENAMETOOLONG);
    }
    if (len > 1) {
      buf[len++] = '/';
    }
    inline_memcpy(buf + len, comp.data(), comp.size());
    len += comp.size();
    buf[len] = '\0';
    return ok();
  }

  // Pops the last component from the path.
  // For example `/path/to/dir` -> `/path/to`.
  void pop_component() {
    if (len <= 1) {
      return;
    }
    while (len > 1 && buf[len - 1] != '/') {
      --len;
    }
    if (len > 1) {
      --len; // strip the slash itself
    }
    buf[len] = '\0';
  }

  // Completely resets the builder.
  MaybeError reset(cpp::string_view abs_path) {
    if (abs_path.size() + 1 > cap) {
      return Error(ENAMETOOLONG);
    }
    inline_memcpy(buf, abs_path.data(), abs_path.size());
    len = abs_path.size();
    buf[len] = '\0';
    return ok();
  }

private:
  PathBuilder(char *buffer, size_t len, size_t capacity)
      : buf(buffer), len(len), cap(capacity) {}

  char *buf;
  size_t len;
  size_t cap;
};

class PathComponentQueue {
  char *buf;
  size_t capacity;
  size_t pos;
  size_t end;

  PathComponentQueue(char *buffer, size_t capacity, size_t length)
      : buf(buffer), capacity(capacity), pos(0), end(length) {}

public:
  static ErrorOr<PathComponentQueue> make(char *buffer, size_t capacity,
                                          cpp::string_view path) {
    if (path.size() + 1 > capacity)
      return Error(ENAMETOOLONG);

    inline_memcpy(buffer, path.data(), path.size());
    buffer[path.size()] = '\0';

    return PathComponentQueue(buffer, capacity, path.size());
  }

  cpp::optional<cpp::string_view> next() {
    while (pos < end && buf[pos] == '/') {
      ++pos;
    }
    if (pos >= end) {
      return cpp::nullopt;
    }
    size_t start = pos;
    while (pos < end && buf[pos] != '/') {
      ++pos;
    }
    return cpp::string_view(buf + start, pos - start);
  }

  bool empty() const { return pos >= end; }

  MaybeError prepend_path(cpp::string_view p) {
    size_t remaining = end - pos;
    size_t sep = (remaining > 0) ? 1 : 0;
    size_t new_end = p.size() + sep + remaining;
    if (new_end + 1 > capacity) {
      return Error(ENAMETOOLONG);
    }
    inline_memmove(buf + p.size() + sep, buf + pos, remaining);
    inline_memcpy(buf, p.data(), p.size());
    if (sep) {
      buf[p.size()] = '/';
    }
    end = new_end;
    buf[end] = '\0';
    pos = 0;
    return ok();
  }
};

class MallocGuard {
public:
  MallocGuard(char *p) : ptr_(p) {}
  ~MallocGuard() { ::free(ptr_); }

  void release() { ptr_ = nullptr; }

  MallocGuard(const MallocGuard &) = delete;
  MallocGuard &operator=(const MallocGuard &) = delete;

private:
  char *ptr_;
};

MaybeError resolve(PathBuilder &builder, PathComponentQueue &queue,
                   char *link_buf, size_t link_cap) {
  size_t symlinks_followed = 0;

  while (true) {
    cpp::optional<cpp::string_view> component = queue.next();
    if (!component)
      break;

    // "//" and "/./" are both treated as the current directory.
    if (component->empty() || *component == ".")
      continue;

    // ".." moves up towards the root by one directory.
    if (*component == "..") {
      builder.pop_component();
      continue;
    }

    MaybeError res = builder.push_component(*component);
    if (!res)
      return res;

    struct stat st;
    ErrorOr<int> lstat_res = internal::lstat(builder.view().data(), &st);
    if (!lstat_res)
      return Error(lstat_res.error());

    if (S_ISLNK(st.st_mode)) {
      if (symlinks_followed > kMaxSymlinkFollows)
        return Error(ELOOP);
      symlinks_followed++;

      ErrorOr<ssize_t> readlink_bytes_written =
          internal::readlink(builder.view().data(), link_buf, link_cap);
      if (!readlink_bytes_written)
        return Error(readlink_bytes_written.error());

      // Check if the name exceeds link_buf's capacity and was truncated.
      size_t link_len = static_cast<size_t>(*readlink_bytes_written);
      if (link_len >= link_cap)
        return Error(ENAMETOOLONG);

      // Construct a string view, as readlink does not null-terminate.
      cpp::string_view target(link_buf, link_len);

      if (target.starts_with("/")) {
        MaybeError res = builder.reset("/");
        if (!res)
          return res;
      } else {
        // Relative symlink, so just drop the last component.
        builder.pop_component();
      }

      // Prepend the new target.
      MaybeError res = queue.prepend_path(target);
      if (!res)
        return res;

      continue;
    }

    if (!queue.empty() && !S_ISDIR(st.st_mode))
      return Error(ENOTDIR);
  }

  return ok();
}

ErrorOr<char *> realpath_impl(const char *__restrict path,
                              char *__restrict resolved) {
  if (path == nullptr)
    return Error(EINVAL);

  cpp::string_view path_view(path);
  if (path_view.empty())
    return Error(ENOENT);

  const size_t path_max = PATH_MAX;

  // Allocate memory for the resolved path if `resolved` is null.
  char *out = resolved;
  if (resolved == nullptr) {
    out = reinterpret_cast<char *>(::malloc(path_max));
    if (out == nullptr)
      return Error(ENOMEM);
  }
  MallocGuard malloc_guard(resolved == nullptr ? out : nullptr);

  char queue_buf[path_max];
  char link_buf[path_max];

  ErrorOr<PathBuilder> path_builder =
      path_view.starts_with("/")
          ? PathBuilder::AtRootDir(out, path_max)
          : PathBuilder::AtCurrentWorkingDir(out, path_max);
  if (!path_builder)
    return Error(path_builder.error());

  ErrorOr<PathComponentQueue> queue =
      PathComponentQueue::make(queue_buf, path_max, path_view);
  if (!queue)
    return Error(queue.error());

  MaybeError res = resolve(*path_builder, *queue, link_buf, path_max);
  if (!res)
    return Error(res.error());

  malloc_guard.release();
  return out;
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

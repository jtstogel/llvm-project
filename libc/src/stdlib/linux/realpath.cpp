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

  MaybeError push(cpp::string_view comp) {
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

class PathQueue {
  char *buf;
  size_t cap;
  size_t pos;
  size_t end;

  PathQueue(char *buffer, size_t capacity, size_t length)
      : buf(buffer), cap(capacity), pos(0), end(length) {}

public:
  static ErrorOr<PathQueue> make(char *buffer, size_t capacity,
                                 cpp::string_view path) {
    if (path.size() + 1 > capacity) {
      return Error(ENAMETOOLONG);
    }
    inline_memcpy(buffer, path.data(), path.size());
    buffer[path.size()] = '\0';
    return PathQueue(buffer, capacity, path.size());
  }

  cpp::string_view next() {
    while (pos < end && buf[pos] == '/') {
      ++pos;
    }
    if (pos >= end) {
      return {};
    }
    size_t start = pos;
    while (pos < end && buf[pos] != '/') {
      ++pos;
    }
    return {buf + start, pos - start};
  }

  bool has_more() const { return pos < end; }

  MaybeError prepend(cpp::string_view p) {
    size_t remaining = end - pos;
    size_t sep = (remaining > 0) ? 1 : 0;
    size_t new_end = p.size() + sep + remaining;
    if (new_end + 1 > cap) {
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

MaybeError resolve(PathBuilder &builder, PathQueue &queue, char *link_buf,
                   size_t link_cap, int &symlinks_left) {
  while (true) {
    auto comp = queue.next();
    if (comp.empty()) {
      break;
    }

    if (comp == ".") {
      continue;
    }
    if (comp == "..") {
      builder.pop_component();
      continue;
    }

    if (auto res = builder.push(comp); !res) {
      return res;
    }

    struct stat st;
    auto lstat_res = internal::lstat(builder.view().data(), &st);
    if (!lstat_res) {
      return Error(lstat_res.error());
    }

    if (S_ISLNK(st.st_mode)) {
      if (symlinks_left <= 0) {
        return Error(ELOOP);
      }
      symlinks_left -= 1;

      auto readlink_res =
          internal::readlink(builder.view().data(), link_buf, link_cap);
      if (!readlink_res) {
        return Error(readlink_res.error());
      }

      size_t link_len = static_cast<size_t>(readlink_res.value());
      if (link_len >= link_cap) {
        return Error(ENAMETOOLONG);
      }

      cpp::string_view target(link_buf, link_len);

      builder.pop_component();
      if (!target.empty() && target[0] == '/') {
        if (auto res = builder.reset("/"); !res) {
          return res;
        }
      }

      if (auto res = queue.prepend(target); !res) {
        return res;
      }
      continue;
    }

    if (queue.has_more() && !S_ISDIR(st.st_mode)) {
      return Error(ENOTDIR);
    }
  }

  return ok();
}

ErrorOr<char *> realpath_impl(const char *__restrict path,
                              char *__restrict resolved) {
  if (path == nullptr) {
    return Error(EINVAL);
  }

  cpp::string_view path_view(path);
  if (path_view.empty()) {
    return Error(ENOENT);
  }

  const size_t path_max = PATH_MAX;

  char *out = resolved;
  if (out == nullptr) {
    out = reinterpret_cast<char *>(::malloc(path_max));
    if (out == nullptr) {
      return Error(ENOMEM);
    }
  }
  MallocGuard malloc_guard(resolved == nullptr ? out : nullptr);

  char queue_buf[path_max];
  char link_buf[path_max];

  auto builder = [&path_view, out]() -> ErrorOr<PathBuilder> {
    if (path_view.starts_with("/")) {
      return PathBuilder::AtRootDir(out, path_max);
    }
    return PathBuilder::AtCurrentWorkingDir(out, path_max);
  }();
  if (!builder.has_value()) {
    return Error(builder.error());
  }

  auto queue_res = PathQueue::make(queue_buf, path_max, path_view);
  if (!queue_res) {
    return Error(queue_res.error());
  }
  PathQueue queue = queue_res.value();

  int symlinks_left = 40;
  auto res = resolve(*builder, queue, link_buf, path_max, symlinks_left);
  if (!res) {
    return Error(res.error());
  }

  malloc_guard.release();
  return out;
}

} // namespace

LLVM_LIBC_FUNCTION(char *, realpath,
                   (const char *__restrict path, char *__restrict resolved)) {
  auto res = realpath_impl(path, resolved);
  if (!res) {
    libc_errno = res.error();
    return nullptr;
  }
  return res.value();
}

} // namespace LIBC_NAMESPACE_DECL

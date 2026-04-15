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
#include "src/__support/CPP/string.h"
#include "src/__support/CPP/string_view.h"
#include "src/__support/OSUtil/filesystem.h"
#include "src/__support/common.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/string/memory_utils/inline_memcpy.h"
#include "src/string/string_utils.h"
#include <linux/limits.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(char *, realpath,
                   (const char *__restrict path, char *__restrict resolved)) {
  if (path == nullptr) {
    libc_errno = EINVAL;
    return nullptr;
  }
  if (path[0] == '\0') {
    libc_errno = ENOENT;
    return nullptr;
  }

  cpp::string resolved_path;
  if (path[0] != '/') {
    char buf[PATH_MAX];
    auto result = internal::getcwd(buf, PATH_MAX);
    if (!result.has_value()) {
      libc_errno = result.error();
      return nullptr;
    }
    resolved_path = cpp::string_view(buf);
  } else {
    resolved_path = cpp::string_view("/");
  }

  cpp::string remaining = cpp::string_view(path);
  int symlinks_followed = 0;
  // SYMLOOP_MAX is usually 40 on Linux.
  const int MAX_SYMLINKS = 40;
  const size_t path_len = internal::string_length(path);
  bool trailing_slash = (path[path_len - 1] == '/');

  while (!remaining.empty()) {
    size_t slash_pos = cpp::string_view(remaining).find_first_of('/');
    cpp::string_view component;
    if (slash_pos == cpp::string_view::npos) {
      component = remaining;
      remaining = cpp::string_view("");
    } else {
      component = cpp::string_view(remaining).substr(0, slash_pos);
      remaining = cpp::string_view(remaining).substr(slash_pos + 1);
    }

    if (component.empty() || component == ".")
      continue;

    if (component == "..") {
      if (resolved_path != "/") {
        size_t last_slash = cpp::string_view(resolved_path).find_last_of('/');
        if (last_slash == 0)
          resolved_path.resize(1);
        else
          resolved_path.resize(last_slash);
      }
      continue;
    }

    if (resolved_path.back() != '/')
      resolved_path += '/';
    resolved_path += component;

    if (resolved_path.size() >= PATH_MAX) {
      libc_errno = ENAMETOOLONG;
      return nullptr;
    }

    struct stat st;
    auto result = internal::lstat(resolved_path.c_str(), &st);
    if (!result.has_value()) {
      libc_errno = result.error();
      return nullptr;
    }

    if (S_ISLNK(st.st_mode)) {
      if (++symlinks_followed > MAX_SYMLINKS) {
        libc_errno = ELOOP;
        return nullptr;
      }
      char link_buf[PATH_MAX];
      auto link_len =
          internal::readlink(resolved_path.c_str(), link_buf, PATH_MAX);
      if (!link_len.has_value()) {
        libc_errno = link_len.error();
        return nullptr;
      }
      cpp::string_view link_path(link_buf, link_len.value());
      if (link_path.empty())
        continue;

      if (link_path[0] == '/') {
        resolved_path = cpp::string_view("/");
      } else {
        size_t last_slash = cpp::string_view(resolved_path).find_last_of('/');
        if (last_slash == 0)
          resolved_path.resize(1);
        else
          resolved_path.resize(last_slash);
      }

      if (remaining.empty()) {
        remaining = link_path;
      } else {
        remaining = cpp::string(link_path) + "/" + remaining;
      }
    } else {
      if (!remaining.empty() && !S_ISDIR(st.st_mode)) {
        libc_errno = ENOTDIR;
        return nullptr;
      }
    }
  }

  // If the original path had a trailing slash, the final resolved path must be
  // a directory.
  if (trailing_slash) {
    struct stat st;
    auto result = internal::lstat(resolved_path.c_str(), &st);
    if (!result.has_value()) {
      libc_errno = result.error();
      return nullptr;
    }
    if (!S_ISDIR(st.st_mode)) {
      libc_errno = ENOTDIR;
      return nullptr;
    }
  }

  if (resolved_path.size() >= PATH_MAX) {
    libc_errno = ENAMETOOLONG;
    return nullptr;
  }

  if (resolved == nullptr) {
    resolved = static_cast<char *>(::malloc(resolved_path.size() + 1));
    if (resolved == nullptr) {
      libc_errno = ENOMEM;
      return nullptr;
    }
  }

  inline_memcpy(resolved, resolved_path.c_str(), resolved_path.size() + 1);
  return resolved;
}

} // namespace LIBC_NAMESPACE_DECL

//===-- Implementation of realpath ----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/stdlib/realpath.h"
#include "hdr/func/malloc.h"
#include "src/__support/OSUtil/filesystem.h"
#include "src/__support/common.h"
#include "src/__support/error_or.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/string/memory_utils/inline_memcpy.h"
#include "src/string/memory_utils/inline_memmove.h"
#include "src/string/string_utils.h"
#include <linux/limits.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {

namespace {

class RealPathResolver {
  char resolved[PATH_MAX];
  size_t resolved_len;
  char remaining[PATH_MAX];
  size_t remaining_len;
  int symlinks_followed;
  static constexpr int MAX_SYMLINKS = 40;

  // Absolute path constructor
  RealPathResolver(const char *path, size_t path_len)
      : resolved_len(1), remaining_len(path_len), symlinks_followed(0) {
    resolved[0] = '/';
    resolved[1] = '\0';
    inline_memcpy(remaining, path, path_len + 1);
  }

  // Relative path constructor
  RealPathResolver(const char *path, size_t path_len, const char *cwd,
                   size_t cwd_len)
      : resolved_len(cwd_len), remaining_len(path_len), symlinks_followed(0) {
    inline_memcpy(resolved, cwd, cwd_len + 1);
    inline_memcpy(remaining, path, path_len + 1);
  }

  void pop_last_component() {
    if (resolved_len <= 1)
      return;

    char *last_slash = internal::strrchr_implementation(resolved, '/');
    if (last_slash == resolved)
      resolved_len = 1;
    else
      resolved_len = static_cast<size_t>(last_slash - resolved);
    resolved[resolved_len] = '\0';
  }

  int push_component(const char *name, size_t len) {
    if (resolved_len > 1 && resolved[resolved_len - 1] != '/') {
      if (resolved_len + 1 >= PATH_MAX)
        return ENAMETOOLONG;
      resolved[resolved_len++] = '/';
    }
    if (resolved_len + len >= PATH_MAX)
      return ENAMETOOLONG;

    inline_memcpy(resolved + resolved_len, name, len);
    resolved_len += len;
    resolved[resolved_len] = '\0';
    return 0;
  }

  int prepend_remaining(const char *path, size_t len) {
    size_t extra = (remaining_len > 0 && path[len - 1] != '/') ? 1 : 0;
    if (len + extra + remaining_len >= PATH_MAX)
      return ENAMETOOLONG;

    if (remaining_len > 0) {
      inline_memmove(remaining + len + extra, remaining, remaining_len + 1);
      if (extra)
        remaining[len] = '/';
    } else {
      remaining[len] = '\0';
    }
    inline_memcpy(remaining, path, len);
    remaining_len += len + extra;
    return 0;
  }

  int handle_symlink() {
    if (++symlinks_followed > MAX_SYMLINKS)
      return ELOOP;

    char link_buf[PATH_MAX];
    auto link_len_or_err = internal::readlink(resolved, link_buf, PATH_MAX);
    if (!link_len_or_err.has_value())
      return link_len_or_err.error();

    size_t link_len = static_cast<size_t>(link_len_or_err.value());
    if (link_buf[0] == '/') {
      resolved[0] = '/';
      resolved[1] = '\0';
      resolved_len = 1;
    } else {
      pop_last_component();
    }
    return prepend_remaining(link_buf, link_len);
  }

  int process_next() {
    char *next_slash = internal::strchr_implementation(remaining, '/');
    size_t component_len =
        next_slash ? static_cast<size_t>(next_slash - remaining) : remaining_len;
    char component[PATH_MAX];
    inline_memcpy(component, remaining, component_len);
    component[component_len] = '\0';

    if (next_slash) {
      remaining_len -= component_len + 1;
      inline_memmove(remaining, next_slash + 1, remaining_len + 1);
    } else {
      remaining[0] = '\0';
      remaining_len = 0;
    }

    if (component_len == 0 || (component_len == 1 && component[0] == '.'))
      return 0;
    if (component_len == 2 && component[0] == '.' && component[1] == '.') {
      pop_last_component();
      return 0;
    }

    if (int err = push_component(component, component_len))
      return err;

    struct stat st;
    auto stat_err = internal::lstat(resolved, &st);
    if (!stat_err.has_value())
      return stat_err.error();

    if (S_ISLNK(st.st_mode))
      return handle_symlink();
    if (remaining_len > 0 && !S_ISDIR(st.st_mode))
      return ENOTDIR;
    return 0;
  }

public:
  static ErrorOr<RealPathResolver> init_absolute(const char *path) {
    size_t path_len = internal::string_length(path);
    if (path_len >= PATH_MAX)
      return Error(ENAMETOOLONG);
    return RealPathResolver(path, path_len);
  }

  static ErrorOr<RealPathResolver> init_relative(const char *path) {
    size_t path_len = internal::string_length(path);
    if (path_len >= PATH_MAX)
      return Error(ENAMETOOLONG);

    char buf[PATH_MAX];
    auto err = internal::getcwd(buf, PATH_MAX);
    if (!err.has_value())
      return Error(err.error());

    return RealPathResolver(path, path_len, buf, internal::string_length(buf));
  }

  int resolve() {
    while (remaining_len > 0) {
      if (int err = process_next())
        return err;
    }
    return 0;
  }

  int check_trailing_slash(const char *path) {
    size_t path_len = internal::string_length(path);
    if (path_len > 0 && path[path_len - 1] == '/') {
      struct stat st;
      auto stat_err = internal::lstat(resolved, &st);

      if (!stat_err.has_value())
        return stat_err.error();

      if (!S_ISDIR(st.st_mode))
        return ENOTDIR;
    }
    return 0;
  }

  char *finalize(char *output) {
    if (output == nullptr) {
      output = static_cast<char *>(::malloc(resolved_len + 1));
      if (output == nullptr) {
        libc_errno = ENOMEM;
        return nullptr;
      }
    }
    inline_memcpy(output, resolved, resolved_len + 1);
    return output;
  }
};

} // namespace

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

  auto resolver = (path[0] == '/') ? RealPathResolver::init_absolute(path)
                                  : RealPathResolver::init_relative(path);
  if (!resolver.has_value()) {
    libc_errno = resolver.error();
    return nullptr;
  }

  if (int err = resolver->resolve()) {
    libc_errno = err;
    return nullptr;
  }

  if (int err = resolver->check_trailing_slash(path)) {
    libc_errno = err;
    return nullptr;
  }

  return resolver->finalize(resolved);
}

} // namespace LIBC_NAMESPACE_DECL

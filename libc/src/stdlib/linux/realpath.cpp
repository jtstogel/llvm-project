//===-- Implementation of realpath ----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/stdlib/realpath.h"
#include "src/__support/CPP/string_view.h"
#include "src/__support/OSUtil/syscall.h" // For internal syscall function.
#include "src/__support/common.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/string/strlen.h"
#include "src/sys/stat/lstat.h"
#include <linux/limits.h> // This is safe to include without any name pollution.
#include <stddef.h>       // For size_t
#include <sys/syscall.h>  // For syscall numbers.

namespace LIBC_NAMESPACE_DECL {
namespace {

bool getcwd_syscall(char *buf, size_t size) {
  int ret = LIBC_NAMESPACE::syscall_impl<int>(SYS_getcwd, buf, size);
  if (ret < 0) {
    libc_errno = -ret;
    return false;
  } else if (ret == 0 || buf[0] != '/') {
    libc_errno = ENOENT;
    return false;
  }
  return true;
}

class CanonicalizedPath {
public:
  CanonicalizedPath(char *data, size_t length, size_t buf_size)
      : data(data), length(length), buf_size(buf_size) {}

  CanonicalizedPath(char *data, size_t buf_size)
      : data(data), length(simple_strlen(data)), buf_size(buf_size) {}

  static size_t simple_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
      len++;
    };
    return len;
  }

  void switch_to_parent() {
    if (length == 0 || (length == 1 && data[0] == '/')) {
      return; // Already at root or empty
    }
    
    auto view = cpp::string_view(data, length);
    size_t slash_idx = view.find_last_of('/');
    
    if (slash_idx == cpp::string_view::npos) {
      length = 0; // Relative path 'a' becomes empty
    } else if (slash_idx == 0) {
      length = 1; // Absolute path '/a' becomes '/'
    } else {
      length = slash_idx; // '/a/b' becomes '/a'
    }
  }

  void append_segment(const cpp::string_view &segment) {
    if (data[length - 1] != '/') {
      append_char('/');
    }
    for (size_t i = 0; i < segment.size(); i++) {
      append_char(segment[i]);
    }
  }

  void append_char(char c) {
    data[length] = c;
    length++;
  }

  void terminate() {
    data[length] = '\0';
  }

  char *data;
  size_t length;
  size_t buf_size;
};

void canonicalize(cpp::string_view path, char *buf, size_t buf_size) {
  CanonicalizedPath result(buf, 0, buf_size);

  bool is_absolute_path = path.starts_with("/");
  if (is_absolute_path) {
    result.append_char('/');
  } else {
    if (!getcwd_syscall(buf, buf_size)) {
      // error
    }
    result = CanonicalizedPath(buf, buf_size);
  }

  while (!path.empty()) {
    size_t next_slash = path.find_first_of('/');
    cpp::string_view segment = path.substr(0, next_slash);

    if (segment == "..") {
      result.switch_to_parent();
    } else if (segment != "." && !segment.empty()) {
      result.append_segment(segment);
    }

    if (next_slash == cpp::string_view::npos) {
      break;
    }

    // Move past the slash
    path.remove_prefix(next_slash + 1);
  }

  result.terminate();
}

} // namespace

LLVM_LIBC_FUNCTION(char *, realpath,
                   ([[maybe_unused]] const char *__restrict path,
                    [[maybe_unused]] char *__restrict resolved_path)) {
  if (path == NULL) {
    return NULL; // ret EINVAL
  }

  canonicalize(path, resolved_path, PATH_MAX);
  return resolved_path;
}

} // namespace LIBC_NAMESPACE_DECL

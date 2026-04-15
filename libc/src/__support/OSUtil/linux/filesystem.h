//===-- Linux implementation of internal filesystem functions ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_OSUTIL_LINUX_FILESYSTEM_H
#define LLVM_LIBC_SRC___SUPPORT_OSUTIL_LINUX_FILESYSTEM_H

#include "hdr/types/mode_t.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/chdir.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/close.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/getcwd.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/lstat.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/mkdir.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/open.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/readlink.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/rmdir.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/symlink.h"
#include "src/__support/OSUtil/linux/syscall_wrappers/unlink.h"
#include "src/__support/common.h"
#include "src/__support/error_or.h"

namespace LIBC_NAMESPACE_DECL {
namespace internal {

LIBC_INLINE ErrorOr<int> open(const char *path, int flags, mode_t mode) {
  return linux_syscalls::open(path, flags, mode);
}

LIBC_INLINE ErrorOr<int> close(int fd) {
  return linux_syscalls::close(fd);
}

LIBC_INLINE ErrorOr<int> mkdir(const char *path, mode_t mode) {
  return linux_syscalls::mkdir(path, mode);
}

LIBC_INLINE ErrorOr<int> rmdir(const char *path) {
  return linux_syscalls::rmdir(path);
}

LIBC_INLINE ErrorOr<int> chdir(const char *path) {
  return linux_syscalls::chdir(path);
}

LIBC_INLINE ErrorOr<int> getcwd(char *buf, size_t size) {
  return linux_syscalls::getcwd(buf, size);
}

LIBC_INLINE ErrorOr<int> unlink(const char *path) {
  return linux_syscalls::unlink(path);
}

LIBC_INLINE ErrorOr<int> symlink(const char *target, const char *linkpath) {
  return linux_syscalls::symlink(target, linkpath);
}

LIBC_INLINE ErrorOr<ssize_t> readlink(const char *path, char *buf, size_t bufsiz) {
  return linux_syscalls::readlink(path, buf, bufsiz);
}

LIBC_INLINE ErrorOr<int> lstat(const char *path, struct stat *statbuf) {
  return linux_syscalls::lstat(path, statbuf);
}

} // namespace internal
} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_SRC___SUPPORT_OSUTIL_LINUX_FILESYSTEM_H

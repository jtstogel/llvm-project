//===-- Internal filesystem functions ---------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_OSUTIL_FILESYSTEM_H
#define LLVM_LIBC_SRC___SUPPORT_OSUTIL_FILESYSTEM_H

#include "src/__support/macros/properties/architectures.h"

#if defined(__linux__)
#include "linux/filesystem.h"
#else
#error filesystem.h not implemented for platform
#endif

#endif // LLVM_LIBC_SRC___SUPPORT_OSUTIL_FILESYSTEM_H

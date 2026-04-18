//===-- Standalone implementation of a char vector --------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_CHARVECTOR_H
#define LLVM_LIBC_SRC___SUPPORT_CHARVECTOR_H

#include "src/__support/common.h" // LIBC_INLINE
#include "src/__support/macros/config.h"
#include "src/__support/sso_buffer.h" // LIBC_INLINE

#include <stddef.h> // size_t

namespace LIBC_NAMESPACE_DECL {

// This is very simple alternate of the std::string class. There is no
// bounds check performed in any of the methods. The callers are expected to
// do the checks before invoking the methods.
//
// This class will be extended as needed in future.

class CharVector {
  static constexpr size_t INIT_BUFF_SIZE = 64;
  SSOBuffer<INIT_BUFF_SIZE> buf;
  size_t index = 0;

public:
  CharVector() = default;
  ~CharVector() = default;

  // append returns true on success and false on allocation failure.
  LIBC_INLINE bool append(char new_char) {
    // +2 for new character and null-terminator.
    size_t required_size = index + 2;
    if (!buf.reserve(required_size)) {
      return false;
    }

    buf[index] = new_char;
    index++;
    return true;
  }

  LIBC_INLINE char *c_str() {
    buf[index] = '\0';
    return buf.data();
  }

  LIBC_INLINE size_t length() { return index; }
};

} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_SRC___SUPPORT_CHARVECTOR_H

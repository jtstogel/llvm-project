//===-- A small-size optimized buffer --------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===---------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_SSO_BUFFER_H
#define LLVM_LIBC_SRC___SUPPORT_SSO_BUFFER_H

#include "src/__support/macros/attributes.h"
#include "src/__support/macros/config.h"

#include <stddef.h>
#include <stdlib.h>

namespace LIBC_NAMESPACE_DECL {

// A buffer that holds up to InitialSize bytes inline, allocating
// on the heap if more capacity is needed.
template <size_t InitialSize> class SSOBuffer {
  char *buf = inline_buf;
  size_t cap = InitialSize;
  char inline_buf[InitialSize];

public:
  constexpr static size_t kInitialSize = InitialSize;

  LIBC_INLINE SSOBuffer() = default;

  LIBC_INLINE ~SSOBuffer() {
    if (buf != inline_buf)
      ::free(buf);
  }

  // Don't allow copy to avoid double-free.
  SSOBuffer(const SSOBuffer &) = delete;
  SSOBuffer &operator=(const SSOBuffer &) = delete;

  SSOBuffer(SSOBuffer &&other) : cap(other.cap) {
    if (other.buf != other.inline_buf) {
      // Steal the heap allocation.
      buf = other.buf;

      other.buf = other.inline_buf;
      other.cap = InitialSize;
    } else {
      for (size_t i = 0; i < InitialSize; ++i)
        inline_buf[i] = other.inline_buf[i];
    }
  }

  LIBC_INLINE char *data() const { return buf; }

  LIBC_INLINE size_t capacity() const { return cap; }

  LIBC_INLINE char &operator[](size_t index) const { return buf[index]; }

  // Releases ownership of the internal buffer.
  // Returns `nullptr` if memory allocation fails.
  [[nodiscard]] LIBC_INLINE char *release() {
    if (buf != inline_buf) {
      char *result = buf;
      buf = inline_buf;
      cap = InitialSize;
      return result;
    }

    char *result = static_cast<char *>(::malloc(cap));
    if (result == nullptr) {
      return nullptr;
    }
    for (size_t i = 0; i < cap; ++i)
      result[i] = inline_buf[i];
    buf = inline_buf;
    cap = InitialSize;
    return result;
  }

  // Ensures capacity is at least `size`. On allocation failure returns
  // false and leaves the buffer untouched.
  [[nodiscard]] LIBC_INLINE bool reserve(size_t size) {
    if (size <= cap)
      return true;

    // If we already have a heap allocation, grow it.
    if (buf != inline_buf) {
      char *new_buf = static_cast<char *>(::realloc(buf, size));
      if (new_buf == nullptr)
        return false;
      buf = new_buf;
      cap = size;
      return true;
    }

    // Transition our local buffer to the heap.
    char *new_buf = static_cast<char *>(::malloc(size));
    if (new_buf == nullptr)
      return false;

    for (size_t i = 0; i < cap; ++i)
      new_buf[i] = inline_buf[i];

    buf = new_buf;
    cap = size;
    return true;
  }
};

} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_SRC___SUPPORT_SSO_BUFFER_H

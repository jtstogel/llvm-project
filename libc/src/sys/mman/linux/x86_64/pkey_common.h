#ifndef LLVM_SYS_MMAN_LINUX_X86_64_PKEY_COMMON_H_
#define LLVM_SYS_MMAN_LINUX_X86_64_PKEY_COMMON_H_

#include "hdr/errno_macros.h" // For ENOSYS
#include "hdr/stdint_proxy.h"
#include "src/__support/common.h"
#include "src/__support/error_or.h"
#include "src/__support/macros/properties/architectures.h"

#if !defined(LIBC_TARGET_ARCH_IS_X86_64)
#error "Invalid include"
#endif

namespace LIBC_NAMESPACE_DECL {
namespace pkey_common {
namespace internal {

constexpr int kMaxKey = 15;
constexpr int kKeyMask = 0x3;
constexpr int kBitsPerKey = 2;

// This will SIGILL on CPUs that don't support PKU / OSPKE,
// but this case should never be reached as a prior pkey_alloc invocation
// would have failed more gracefully.
LIBC_INLINE uint32_t read_prku() {
  uint32_t pkru = 0;
  uint32_t edx = 0;
  LIBC_INLINE_ASM("rdpkru" : "=a"(pkru), "=d"(edx) : "c"(0));
  return pkru;
}

// This will SIGILL on CPUs that don't support PKU / OSPKE,
// but this case should never be reached as a prior pkey_alloc invocation
// would have failed more gracefully.
LIBC_INLINE void write_prku(uint32_t pkru) {
  LIBC_INLINE_ASM("wrpkru" : : "a"(pkru), "d"(0), "c"(0));
}

} // namespace internal

// x86_64 implementation of pkey_get.
// Returns the access rights for the given pkey on success, errno otherwise.
LIBC_INLINE static ErrorOr<int> pkey_get(int pkey) {
  if (pkey < 0 || pkey > internal::kMaxKey) {
    return Error(EINVAL);
  }

  uint32_t pkru = internal::read_prku();
  return (pkru >> (pkey * internal::kBitsPerKey)) & internal::kKeyMask;
}

// x86_64 implementation of pkey_set.
// Returns 0 on success, errno otherwise.
LIBC_INLINE static ErrorOr<int> pkey_set(int pkey, unsigned int access_rights) {
  if (pkey < 0 || pkey > internal::kMaxKey ||
      access_rights > internal::kKeyMask) {
    return Error(EINVAL);
  }

  uint32_t pkru = internal::read_prku();
  pkru &= ~(internal::kKeyMask << (pkey * internal::kBitsPerKey));
  pkru |=
      ((access_rights & internal::kKeyMask) << (pkey * internal::kBitsPerKey));
  internal::write_prku(pkru);

  return 0;
}

} // namespace pkey_common
} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_SYS_MMAN_LINUX_X86_64_PKEY_COMMON_H_

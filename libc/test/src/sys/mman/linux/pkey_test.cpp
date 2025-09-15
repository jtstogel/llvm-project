//===-- Unit tests for pkey functions -------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "hdr/errno_macros.h"
#include "hdr/types/size_t.h"
#include "src/__support/libc_errno.h"
#include "src/sys/mman/mmap.h"
#include "src/sys/mman/munmap.h"
#include "src/sys/mman/pkey_alloc.h"
#include "src/sys/mman/pkey_free.h"
#include "src/sys/mman/pkey_get.h"
#include "src/sys/mman/pkey_mprotect.h"
#include "src/sys/mman/pkey_set.h"
#include "test/UnitTest/ErrnoCheckingTest.h"
#include "test/UnitTest/ErrnoSetterMatcher.h"
#include "test/UnitTest/LibcTest.h"
#include "test/UnitTest/Test.h"
#include "test/UnitTest/TestLogger.h"

#include <signal.h>

using LIBC_NAMESPACE::testing::tlog;
using LIBC_NAMESPACE::testing::ErrnoSetterMatcher::Fails;
using LIBC_NAMESPACE::testing::ErrnoSetterMatcher::Succeeds;

using LlvmLibcProtectionKeyTest = LIBC_NAMESPACE::testing::ErrnoCheckingTest;

// Wrapper around a pkey to ensure it is freed.
class PKeyGuard {
public:
  int key{-1};

  PKeyGuard(int key) : key(key) {}

  ~PKeyGuard() {
    if (key != -1) {
      LIBC_NAMESPACE::pkey_free(key);
    }
  }
};

// Wrapper around mmap to ensure munmap is called.
class MMapPageGuard {
public:
  void *addr = nullptr;
  size_t size = 0;

  static MMapPageGuard mmap(int prot) {
    size_t page_size = 4096;
    void *addr = LIBC_NAMESPACE::mmap(nullptr, page_size, prot,
                                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
      return MMapPageGuard(nullptr, 0);
    }

    return MMapPageGuard(addr, page_size);
  }

  MMapPageGuard(void *addr, size_t size) : addr(addr), size(size) {}

  ~MMapPageGuard() {
    if (addr != nullptr) {
      LIBC_NAMESPACE::munmap(addr, size);
    }
  }
};

bool protection_key_syscalls_supported() {
  static bool supported = []() {
    int key = LIBC_NAMESPACE::pkey_alloc(0, 0);
    int err = libc_errno;
    libc_errno = 0;
    tlog << "pkey_alloc: " << key << ", " << err << "\n";
    return key != -1 || (err != ENOSPC && err != ENOSYS && err != EINVAL);
  }();
  return supported;
}

bool protection_key_accessors_supported() {
  static bool supported = []() {
    if (!protection_key_syscalls_supported()) {
      return false;
    }
    PKeyGuard pkey{LIBC_NAMESPACE::pkey_alloc(0, 0)};
    int access_rights = LIBC_NAMESPACE::pkey_get(pkey.key);
    int err = libc_errno;
    libc_errno = 0;
    return access_rights != -1 || err != ENOSYS;
  }();
  return supported;
}

TEST_F(LlvmLibcProtectionKeyTest, MemoryProtectionDisablesWrite) {
  if (!protection_key_syscalls_supported()) {
    tlog << "Skipping test: pkey syscalls are not available\n";
    return;
  }

  PKeyGuard pkey(LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE));
  ASSERT_NE(pkey.key, -1);

  MMapPageGuard page = MMapPageGuard::mmap(PROT_READ | PROT_WRITE);
  ASSERT_NE(page.addr, nullptr);

  volatile char *data = (char *)page.addr;
  data[0] = 'a';

  EXPECT_THAT(LIBC_NAMESPACE::pkey_mprotect(page.addr, page.size,
                                            PROT_READ | PROT_WRITE, pkey.key),
              Succeeds());

  // Read is still allowed.
  EXPECT_EQ(data[0], 'a');

  // Write is not allowed.
  // TODO: check segfault reason is SEGV_PKUERR.
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));
}

TEST_F(LlvmLibcProtectionKeyTest, PKeySetChangesAccessRights) {
  if (!protection_key_accessors_supported()) {
    tlog << "Skipping test: pkey accessors are not available\n";
    return;
  }

  PKeyGuard pkey(LIBC_NAMESPACE::pkey_alloc(0, 0));
  ASSERT_NE(pkey.key, -1);

  MMapPageGuard page = MMapPageGuard::mmap(PROT_READ | PROT_WRITE);
  ASSERT_NE(page.addr, nullptr);

  EXPECT_THAT(LIBC_NAMESPACE::pkey_mprotect(page.addr, page.size,
                                            PROT_READ | PROT_WRITE, pkey.key),
              Succeeds());

  // Write is allowed by default.
  volatile char *data = (char *)page.addr;
  data[0] = 'a';

  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey.key, PKEY_DISABLE_WRITE),
              Succeeds());

  // Now read is allowed but write is not.
  EXPECT_EQ(data[0], 'a');
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));

  // Now neither read nor write is allowed.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey.key, PKEY_DISABLE_ACCESS |
                                                     PKEY_DISABLE_WRITE),
              Succeeds());
  EXPECT_DEATH([&data]() { (void)data[0]; }, WITH_SIGNAL(SIGSEGV));
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));
}

TEST_F(LlvmLibcProtectionKeyTest, FallsBackToMProtectForInvalidPKey) {
  MMapPageGuard page = MMapPageGuard::mmap(PROT_READ | PROT_WRITE);
  ASSERT_NE(page.addr, nullptr);

  volatile char *data = (char *)page.addr;
  data[0] = 'a';

  EXPECT_THAT(
      LIBC_NAMESPACE::pkey_mprotect(page.addr, page.size, PROT_READ, -1),
      Succeeds());

  // Read is still allowed.
  EXPECT_EQ(data[0], 'a');

  // Write is not allowed.
  // TODO: check segfault reason is not SEGV_PKUERR.
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));
}

TEST_F(LlvmLibcProtectionKeyTest, ExhaustedKeysFailsWithENOSPC) {
  if (!protection_key_syscalls_supported()) {
    tlog << "Skipping test: pkey syscalls are not available\n";
    return;
  }

  // Use an unreasonably large limit to ensure test is cross-platform.
  // The limit is 16 pkeys on x86_64, and 8 on aarch64.
  constexpr int kMaxPKeysAvailable = 64;
  int pkeys[kMaxPKeysAvailable] = {-1};
  for (int i = 0; i < kMaxPKeysAvailable; ++i) {
    pkeys[i] = LIBC_NAMESPACE::pkey_alloc(0, 0);
  }

  // pkey allocation should eventually fail with ENOSPC.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_alloc(0, 0), Fails(ENOSPC));

  for (int i = 0; i < kMaxPKeysAvailable; ++i) {
    if (pkeys[i] != -1) {
      EXPECT_THAT(LIBC_NAMESPACE::pkey_free(pkeys[i]), Succeeds());
    }
  }
}

TEST_F(LlvmLibcProtectionKeyTest, Accessors) {
  if (!protection_key_accessors_supported()) {
    tlog << "Skipping test: pkey accessors are not available\n";
    return;
  }

  PKeyGuard pkey(LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE));
  ASSERT_NE(pkey.key, -1);

  // Check that pkey_alloc sets the access rights.
  EXPECT_EQ(LIBC_NAMESPACE::pkey_get(pkey.key), PKEY_DISABLE_WRITE);

  // Check that pkey_set changes the access rights.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey.key, PKEY_DISABLE_ACCESS),
              Succeeds());
  EXPECT_EQ(LIBC_NAMESPACE::pkey_get(pkey.key), PKEY_DISABLE_ACCESS);
}

// > Doesn’t test that execute is unaffected by PKU on x86
//
// x86 PKU applies to data access; instruction fetch isn’t governed by PKRU.
// While your tests don’t toggle PROT_EXEC, it’s still valuable to assert the
// documented invariant on x86 (and not assume it on other arches). Otherwise,
// future changes could break this subtle guarantee without detection.

TEST_F(LlvmLibcProtectionKeyTest, AccessorsErrorForInvalidValues) {
  if (!protection_key_accessors_supported()) {
    tlog << "Skipping test: pkey accessors are not available\n";
    return;
  }

  PKeyGuard pkey(LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE));
  ASSERT_NE(pkey.key, -1);

  // Pkey is out of bounds in pkey_get.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_get(100), Fails(EINVAL));
  EXPECT_THAT(LIBC_NAMESPACE::pkey_get(-1234), Fails(EINVAL));

  // Pkey is out of bounds in pkey_set.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(100, PKEY_DISABLE_ACCESS),
              Fails(EINVAL));
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(-1234, PKEY_DISABLE_ACCESS),
              Fails(EINVAL));

  // Non-zero flags are not supported in pkey_alloc.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_alloc(123, PKEY_DISABLE_WRITE),
              Fails(EINVAL));

  // Access rights are out of bounds.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_alloc(0, 1000), Fails(EINVAL));
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey.key, 1000), Fails(EINVAL));
}

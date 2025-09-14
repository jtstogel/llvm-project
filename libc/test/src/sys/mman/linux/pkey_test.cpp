//===-- Unittests for mprotect --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "hdr/errno_macros.h"
#include "src/__support/libc_errno.h"
#include "src/sys/mman/mmap.h"
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

static bool protection_key_syscalls_supported() {
  static bool supported = []() {
    int pkey = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
    if (pkey == -1) {
      libc_errno = 0;
      return false;
    }
    return LIBC_NAMESPACE::pkey_free(pkey) == 0;
  }();
  return supported;
}

static bool protection_key_accessors_supported() {
  static bool supported = []() {
    int pkey = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
    if (pkey == -1) {
      libc_errno = 0;
      return false;
    }
    int access_rights = LIBC_NAMESPACE::pkey_get(pkey);
    if (access_rights == -1) {
      libc_errno = 0;
      return false;
    }
    return LIBC_NAMESPACE::pkey_free(pkey) == 0;
  }();
  return supported;
}

TEST_F(LlvmLibcProtectionKeyTest, EnablesMemoryProtection) {
  if (!protection_key_syscalls_supported()) {
    tlog << "Skipping test: pkey syscalls are not available\n";
    return;
  }

  int pkey = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
  ASSERT_NE(pkey, -1);

  void *addr = LIBC_NAMESPACE::mmap(nullptr, 4096, PROT_READ | PROT_WRITE,
                                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  ASSERT_NE(addr, MAP_FAILED);

  char *data = (char *)addr;
  data[0] = 'a';

  EXPECT_THAT(
      LIBC_NAMESPACE::pkey_mprotect(addr, 4096, PROT_READ | PROT_WRITE, pkey),
      Succeeds());

  // Read is still allowed.
  EXPECT_EQ(data[0], 'a');

  // Write is not allowed.
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));
}

TEST_F(LlvmLibcProtectionKeyTest, FallsBackToMProtectForInvalidPKey) {
  void *addr = LIBC_NAMESPACE::mmap(nullptr, 4096, PROT_READ | PROT_WRITE,
                                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  ASSERT_NE(addr, MAP_FAILED);

  char *data = (char *)addr;
  data[0] = 'a';

  EXPECT_THAT(LIBC_NAMESPACE::pkey_mprotect(addr, 4096, PROT_READ, -1),
              Succeeds());

  // Read is still allowed.
  EXPECT_EQ(data[0], 'a');

  // Write is not allowed.
  EXPECT_DEATH([&data]() { data[0] = 'b'; }, WITH_SIGNAL(SIGSEGV));
}

TEST_F(LlvmLibcProtectionKeyTest, KeysExhaust) {
  if (!protection_key_syscalls_supported()) {
    tlog << "Skipping test: pkey syscalls are not available\n";
    return;
  }

  // Use an unreasonably large limit to ensure test is cross-platform.
  // The limit is 16 pkeys on x86_64, and 32 on aarch64.
  constexpr int kMaxPKeysAvailable = 128;
  int pkeys[kMaxPKeysAvailable] = {-1};
  for (int i = 0; i < kMaxPKeysAvailable; ++i) {
    pkeys[i] = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
  }

  // pkey allocation should eventually fail with ENOSPC.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE), Fails(ENOSPC));

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

  int pkey = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
  ASSERT_NE(pkey, -1);

  // Check that pkey_alloc sets the access rights.
  EXPECT_EQ(LIBC_NAMESPACE::pkey_get(pkey), PKEY_DISABLE_WRITE);

  // Check that pkey_set changes the access rights.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey, PKEY_DISABLE_ACCESS), Succeeds());
  EXPECT_EQ(LIBC_NAMESPACE::pkey_get(pkey), PKEY_DISABLE_ACCESS);

  EXPECT_THAT(LIBC_NAMESPACE::pkey_free(pkey), Succeeds());
}

TEST_F(LlvmLibcProtectionKeyTest, AccessorsErrorForInvalidValues) {
  if (!protection_key_accessors_supported()) {
    tlog << "Skipping test: pkey accessors are not available\n";
    return;
  }

  int pkey = LIBC_NAMESPACE::pkey_alloc(0, PKEY_DISABLE_WRITE);
  ASSERT_NE(pkey, -1);

  // Pkey is out of bounds.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_get(100), Fails(EINVAL));
  EXPECT_THAT(LIBC_NAMESPACE::pkey_get(-1234), Fails(EINVAL));

  // Pkey is out of bounds.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(100, PKEY_DISABLE_ACCESS),
              Fails(EINVAL));
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(-1234, PKEY_DISABLE_ACCESS),
              Fails(EINVAL));

  // Access rights are out of bounds.
  EXPECT_THAT(LIBC_NAMESPACE::pkey_set(pkey, 1000), Fails(EINVAL));

  EXPECT_THAT(LIBC_NAMESPACE::pkey_free(pkey), Succeeds());
}

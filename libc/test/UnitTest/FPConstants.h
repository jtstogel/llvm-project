//===-- FPTestConstants.h ---------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_TEST_UNITTEST_FPTESTCONSTANTS_H
#define LLVM_LIBC_TEST_UNITTEST_FPTESTCONSTANTS_H

#include "src/__support/FPUtil/FPBits.h"
#include "src/__support/macros/config.h"

using LIBC_NAMESPACE::Sign;

#define DECLARE_SPECIAL_FP_SCALARS(T)                                          \
  using FPBits = LIBC_NAMESPACE::fputil::FPBits<T>;                            \
  const T zero = FPBits::zero(Sign::POS).get_val();                            \
  const T neg_zero = FPBits::zero(Sign::NEG).get_val();                        \
  const T aNaN = FPBits::quiet_nan(Sign::POS).get_val();                       \
  const T neg_aNaN = FPBits::quiet_nan(Sign::NEG).get_val();                   \
  const T sNaN = FPBits::signaling_nan(Sign::POS).get_val();                   \
  const T neg_sNaN = FPBits::signaling_nan(Sign::NEG).get_val();               \
  const T inf = FPBits::inf(Sign::POS).get_val();                              \
  const T neg_inf = FPBits::inf(Sign::NEG).get_val();                          \
  const T min_normal = FPBits::min_normal().get_val();                         \
  const T max_normal = FPBits::max_normal(Sign::POS).get_val();                \
  const T neg_max_normal = FPBits::max_normal(Sign::NEG).get_val();            \
  const T min_denormal = FPBits::min_subnormal(Sign::POS).get_val();           \
  const T neg_min_denormal = FPBits::min_subnormal(Sign::NEG).get_val();       \
  const T max_denormal = FPBits::max_subnormal().get_val();

#endif // LLVM_LIBC_TEST_UNITTEST_FPTESTCONSTANTS_H

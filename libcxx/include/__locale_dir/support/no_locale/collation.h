//===-----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_COLLATION_H
#define _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_COLLATION_H

#include <__config>
#include <__cstddef/size_t.h>
#include <cstring>
#if _LIBCPP_HAS_WIDE_CHARACTERS
#  include <cwchar>
#endif

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD
namespace __locale {

#if defined(_LIBCPP_BUILDING_LIBRARY)
inline _LIBCPP_HIDE_FROM_ABI int __strcoll(const char* __s1, const char* __s2, __locale_t) {
  return std::strcoll(__s1, __s2);
}

inline _LIBCPP_HIDE_FROM_ABI size_t __strxfrm(char* __dest, const char* __src, size_t __n, __locale_t) {
  return std::strxfrm(__dest, __src, __n);
}

#  if _LIBCPP_HAS_WIDE_CHARACTERS
inline _LIBCPP_HIDE_FROM_ABI int __wcscoll(const wchar_t* __ws1, const wchar_t* __ws2, __locale_t) {
  return std::wcscoll(__ws1, __ws2);
}

inline _LIBCPP_HIDE_FROM_ABI size_t __wcsxfrm(wchar_t* __dest, const wchar_t* __src, size_t __n, __locale_t) {
  return std::wcsxfrm(__dest, __src, __n);
}
#  endif // _LIBCPP_HAS_WIDE_CHARACTERS
#endif   // _LIBCPP_BUILDING_LIBRARY

} // namespace __locale
_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_COLLATION_H

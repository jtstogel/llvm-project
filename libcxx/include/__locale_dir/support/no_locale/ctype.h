//===-----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_CTYPE_H
#define _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_CTYPE_H

#include <__config>
#include <cctype>
#if _LIBCPP_HAS_WIDE_CHARACTERS
#  include <cwctype>
#endif

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD
namespace __locale {

#if defined(_LIBCPP_BUILDING_LIBRARY)
inline _LIBCPP_HIDE_FROM_ABI int __toupper(int __c, __locale_t) { return std::toupper(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __tolower(int __c, __locale_t) { return std::tolower(__c); }

#  if _LIBCPP_HAS_WIDE_CHARACTERS
inline _LIBCPP_HIDE_FROM_ABI int __iswctype(wint_t __c, wctype_t __type, __locale_t) {
  return std::iswctype(__c, __type);
}

inline _LIBCPP_HIDE_FROM_ABI int __iswspace(wint_t __c, __locale_t) { return std::iswspace(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswprint(wint_t __c, __locale_t) { return std::iswprint(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswcntrl(wint_t __c, __locale_t) { return std::iswcntrl(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswupper(wint_t __c, __locale_t) { return std::iswupper(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswlower(wint_t __c, __locale_t) { return std::iswlower(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswalpha(wint_t __c, __locale_t) { return std::iswalpha(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswblank(wint_t __c, __locale_t) { return std::iswblank(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswdigit(wint_t __c, __locale_t) { return std::iswdigit(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswpunct(wint_t __c, __locale_t) { return std::iswpunct(__c); }

inline _LIBCPP_HIDE_FROM_ABI int __iswxdigit(wint_t __c, __locale_t) { return std::iswxdigit(__c); }

inline _LIBCPP_HIDE_FROM_ABI wint_t __towupper(wint_t __c, __locale_t) { return std::towupper(__c); }

inline _LIBCPP_HIDE_FROM_ABI wint_t __towlower(wint_t __c, __locale_t) { return std::towlower(__c); }
#  endif // _LIBCPP_HAS_WIDE_CHARACTERS
#endif   // _LIBCPP_BUILDING_LIBRARY

} // namespace __locale
_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___LOCALE_DIR_SUPPORT_NO_LOCALE_CTYPE_H

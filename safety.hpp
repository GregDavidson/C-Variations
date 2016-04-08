/* safety.H -- miscellaneous constructs for better C++ programming
 * 
 * Author: J. Greg Davidson
 * Date: Thu Jun 14 2001
 * Copyright (c) 2001 Virtual Infinity Systems (VIS).
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided 
 * that this C comment appear unchanged in all copies and that both the
 * copyright notice and this paragraph appear in supporting 
 * documentation, and that the name of VIS not be used in advertising
 * or publicity pertaining to distribution of the software without specific, 
 * written prior permission.  VIS makes no representations about the 
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 */

#ifndef VIS_SAFETY_MISC
#define VIS_SAFETY_MISC

namespace vis {

template <bool b, typename error> struct static_assert {};

template <typename error> struct static_assert<false, error> {
  static_assert() {error message; }
};

template <typename error, typename i1, typename i2> struct error2 {};

struct bigger {};

template <typename To, typename From>
To widen_cast(From from) {
  static_assert< sizeof (From) <= sizeof (To), error2<bigger, From, To> >();
  return static_cast<To>(from);
}

} // vis namespace end


#endif

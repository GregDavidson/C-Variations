/* safety.H -- miscellaneous constructs for better C++ programming
 * 
 * Author: J. Greg Davidson
 * Date: Thu Jun 14 2001
 * Attribution appreciated!
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

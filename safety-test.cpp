
#include "safety.hpp"
using vis::static_assert;
using vis::error2;
using vis::widen_cast;

struct wrong_metauniverse  { };

int main() {

#ifdef FAIL_MATH
  static_assert< (0>10), error2<wrong_metauniverse,int,int> >();
#else
  static_assert< (10>0), error2<wrong_metauniverse,int,int> >();
#endif

  char c = 'a';
  int i = 12345;
#ifdef NARROW
  c = widen_cast<char>(i);
#else
  i = widen_cast<int>(c);
#endif

  return 0;
}

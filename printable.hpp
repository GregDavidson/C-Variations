/* File printable.H - a simple mixin class for printable types
 * See also: fetchable.H, time.H, money.H, money.C
 * - Greg Davidson, April 1999
 */

#ifndef VIS_PRINTABLE_H
#define VIS_PRINTABLE_H

#include <iostream>

namespace vis {

#ifdef TEMPLATE_GENERIC_INSERTION

// Example generic insertion operator:
template <typename T> inline
std::ostream& operator<<(std::ostream& os, const T& item) {
	return item.print(os);
}
/* Unfortunately, the final C++ standard makes a generic template
 * definition of operator<< and operator>> ambiguous, so this code
 * is commented out.
 */

#else

/* Fortunately there's more than one way to approach the problem.
 * Many things can be done with either templates or inheritance:
 */

using std::ostream;
using std::cout;

struct Printable {
	virtual ostream& print(ostream& os = cout) const = 0;
};
inline ostream& operator<<(ostream& os, const Printable& p) {
	return p.print(os);
}

#endif

} // namespace vis

#endif

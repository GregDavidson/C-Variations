/* File fetchable.H - see printable.H, time.H, money.H
 * - Greg Davidson, April 1999
 */

#ifndef VIS_FETCHABLE_H
#define VIS_FETCHABLE_H

#include <iostream>

namespace vis {

using std::istream;
using std::cin;

struct Fetchable {
	virtual istream& fetch(istream& is = cin) = 0;
};
inline istream& operator>>(istream& is, Fetchable& p) {
	return p.fetch(is);
}

#endif

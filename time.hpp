/* File time.H - a very simple time class.
 * A real time class would be much more sophisticated!
 * The code here is for demonstration purposes only.
 * J. Greg Davidson, April 1999
 */

#ifndef VIS_TIME_H
#define VIS_TIME_H

#include "cstdlib"	// for time_t
#include "printable.H"

namespace vis {

struct Time: Printable {
	Time();		// ctor initializes date to today's date
	ostream& print(ostream& = cout) const;
private:
	std::time_t today;
};

} // vis namespace end

#endif

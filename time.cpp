/* File time.C - a very simple time class.
 * A real time class would be much more sophisticated!
 * The code here is for demonstration purposes only.
 * J. Greg Davidson, April 1999
 */

#include "time.H"

namespace vis {

using namespace std;

Time::Time() { time(&today); }

ostream& Time::print(ostream& os) const {
	struct tm* dateptr = localtime(&today);
	char tmpbuf[128];
	strftime(tmpbuf, 128, "%a, %d %b %Y", dateptr);
	return os << tmpbuf;
}

} // vis namespace end

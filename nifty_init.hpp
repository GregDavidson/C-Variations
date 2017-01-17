/* File open_close.C - Open(Close) any class before first(after last) use
 * Greg Davidson, February 2003
 * Attribution appreciated!
 * See ifdef'ed code at bottom for usage.
 */

namespace vis {

  template <class T>
  class OpenClose {
    static int nifty_counter;
    OpenClose() {
      if (nifty_counter++ == 0) {
	T::Open();
      }
    }
    ~OpenClose() {
      if (--nifty_counter == 0) {
	T::Close();
      }
    }
  }; // struct OpenClose

#ifdef 0

  // In some header file myclass.H we might have:
  struct MyClass {
    static Open() {	// Open for business
          /* Do whatever is needed before
       * any objects are instantiated
       * or any other static member
       * functions are called, e.g.:
       * - Open logging file,
       * - Open db connection,
       * - Initialize graphics,
       * - Fancy init static class data,
       * - etc.
       */
    }
    static Close() {	// Close for business
          /* There will be no more calls to
       * any code in MyClass, so:
       * - close all external connections
       * - detach any services
       * - close any processes,
       * - etc.
       */
    }
  private:
    // None of your business
  };
  
  namespace {
    OpenClose<MyClass> nifty;
  } // anonymous namespace

   /* So the result is that each compilation
   * unit which includes myclass.H will get
   * an instance of OpenClose<MyClass> with
   * a hidden name.  A side effect will be that
   * the nifty_counter within that class will
   * be incremented to the number of such
   * compilation units and will trigger the
   * initialization of MyClass before the
   * point of its first possible use and
   * trigger its shutdown just after the
   * point of its last possible use.
   * Nifty, huh?
   * You might need one more thing...
   */
  
  // In a file myclass.C you might need:
  int OpenClose<MyClass>::nifty_counter = 0;

  
#endif


} // namespace vis

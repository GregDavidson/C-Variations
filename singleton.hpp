/* File singleton.cpp - four singleton idioms in C++
 * Greg Davidson, December 2007
 * Attributoin appreciated!
 */

/* Idiom 1:  namespace_singleton
 * Advantage: simple and minimal overhead
 * Disadvantage: data is not protected!
   For reference only: do not use!
 */

namespace namespace_singleton {
  // define operations as external functions inside namespace
  // define data inside namespace
}

/* Idiom 2:  eager_class_object_singleton
 * Advantage: still pretty simple, also minimal overhead
 * Disadvantage: can really only have one object,
   no flexibility for growth if requirements change
 */

struct eager_class_object_singleton {
  // declare all function members as static
private:
  // declare all data members as static
  eager_class_object_singleton() {}
};

/* Idiom 3: eager_static_member_singleton
 * Advantage: still pretty simple, can have any static multiplicity
 * Disadvantage: this-pointer overhead
 */

struct eager_static_member_singleton {
  static eager_static_member_singleton instance;
  static eager_static_member_singleton another_instance;
  static eager_static_member_singleton three_more_instances[3];
  // declare all function members normally
private:
  // declare data members normally
  eager_static_member_singleton() {}
};

/* Idiom 4: Lazy Factory Singleton
 * Advantage: object creation postponed until needed, can generalize
   to provide any desired number of instances
 * Disadvantage: this-pointer overhead, test overhead
 * Note: this is same as GOF book pattern
 */

struct LFSingleton {
  static LFSingleton& Instance() {
    return TheInstance
      ? TheInstance
      : TheInstance = *(new LFSingleton);
  }
  // declare public function members normally
private:
  static LFSingleton& TheInstance;
  LFSingleton() {}
  // declare data members normally
};

// In one compilation unit:
LFSingleton& LFSingleton::TheInstance;

/* Idiom 4b: Myers Lazy Factory Singleton
 * Advantage: compilation unit doesn't need to
   explicitly define the static data member
 */

struct MLFSingleton {
  static MLFSingleton& Instance() {
    static MLFSingleton theSingleton;
    return theSingleton;
  }
  // declare public function members normally
private:
  MLFSingleton(); // ctor hidden
  MLFSingleton(MLFSingleton const&); // copy ctor hidden
  MLFSingleton& operator=(MLFSingleton const&); // assign op. hidden
  ~MLFSingleton(); // dtor hidden
  // declare other data members normally
};

/* Idiom 5: Policy-Based Myers Lazy Factory Singleton Template(s)
 * Advantages:
   Template is more explicit & factored (DRY)
   Policy-based design is more flexible
   Design can be made thread-safe
   Disadvantage: more abstract, more components
 * Reference for discussion and code:
   https://www.devarticles.com/c/a/Cplusplus/The-Singleton-Pattern-Revisited
 * Reference on locking:
   http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 * Reference for C++-11 variations (and see comments):
   http://silviuardelean.ro/2012/06/05/few-singleton-approaches/
 */

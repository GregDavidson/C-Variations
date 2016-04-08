/* File singleton.cpp - four singleton idioms in C++
 * Greg Davidson, December 2007
 */

/* idiom 1:  namespace_singleton
 * advantage: simple and minimal overhead
 * disadvantage: data is not protected
 * here for reference: do not use!
 */

namespace namespace_singleton {
  // define operations as external functions inside namespace
  // define data inside namespace
}

/* idiom 2:  eager_class_object_singleton
 * advantage: still pretty simple, also minimal overhead
 * disadvantage: can really only have one object
 * - no flexibility for growth if requirements change
 */

struct eager_class_object_singleton {
  // declare all function members as static
private:
  // declare all data members as static
  eager_class_object_singleton() {}
};

/* idiom 3: eager_static_member_singleton
 * advantage: still pretty simple, can have any static multiplicity
 * disadvantage: this-pointer overhead
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

/* idiom 4: eager_static_member_singleton
 * advantage: object creation postponed until needed, can generalize
   to provide any desired number of instances
 * disadvantage: this-pointer overhead, test overhead
 */

struct lazy_factory_singleton {
  static lazy_factory_singleton& Instance() {
    return TheInstance
      ? TheInstance
      : TheInstance = *(new lazy_factor_singleton);
  }
  // declare public function members normally
private:
  static lazy_factory_singleton& TheInstance;
  lazy_factory_singleton() {}
  // declare data members normally
};


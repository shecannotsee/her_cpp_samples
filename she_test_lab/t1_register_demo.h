#ifndef T1_REGISTER_DEMO_H
#define T1_REGISTER_DEMO_H

#include <functional>
#include <vector>

namespace t1_register_demo {

// just to show how to register
#define REGISTER_TEST(test_name)                               \
  void test_name##_test_function();                            \
  namespace {                                                  \
  struct test_name##_register {                                \
    test_name##_register() {                                   \
      register_demo::register_test(test_name##_test_function); \
    }                                                          \
  } test_name##_register_instance;                             \
  }                                                            \
  void test_name##_test_function()

class register_demo {
 public:
  // register test function
  static void register_test(std::function<void()> testFunction) {
    instance().tests.push_back(testFunction);
  }

  // run
  static void run_all_tests() {
    for (auto test : instance().tests) {
      test();  // call test function
    }
  }

 private:
  register_demo() = default;

  static register_demo& instance() {
    static register_demo instance;
    return instance;
  }

  // test table
  std::vector<std::function<void()>> tests;
};

static void run() {
  register_demo::run_all_tests();
}

}  // namespace t1_register_demo

#endif  // T1_REGISTER_DEMO_H

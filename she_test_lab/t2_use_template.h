#ifndef T2_USE_TEMPLATE_H
#define T2_USE_TEMPLATE_H

#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <variant>

namespace t2_use_template {

class register_demo {
  using function_type = std::function<void()>;
  std::unordered_map<std::string, function_type> function_table_;
  std::vector<std::vector<std::string>> function_names_;

  void insert(const std::vector<std::string>& names, const function_type& func) {
    std::string key;
    for (const auto& name : names) {
      key += name;
    }
    function_table_[key] = func;
    function_names_.emplace_back(names);
  }

  auto find(const std::vector<std::string>& names) const -> function_type {
    std::string key;
    for (const auto& name : names) {
      key += name;
    }
    // Not found
    if (const auto it = function_table_.find(key); it == function_table_.end()) {
      return nullptr;
    }
    // Return function
    return function_table_.at(key);
  }

  void run_all_recursive() {
    for (const auto& function_name : function_names_) {
      std::string key;
      for (const auto& name : function_name) {
        key += name;
      }
      const auto func = function_table_[key];
      if (func != nullptr) {
        func();
      }
    }
  }

 public:
  // register test function
  static void register_test(const std::vector<std::string>& names, const function_type& func) {
    instance().insert(names, func);
  }

  // run
  // 运行所有函数
  static void run_all_tests() {
    instance().run_all_recursive();
  }

 private:
  register_demo() = default;

  static register_demo& instance() {
    static register_demo instance;
    return instance;
  }
};

#define TEST1(name)                                \
  namespace name {                                 \
  void func();                                     \
  struct _func_register {                          \
    _func_register() {                             \
      register_demo::register_test({#name}, func); \
    }                                              \
  } func_register;                                 \
  }                                                \
  void name::func()

#define TEST2(name1, name2)                                 \
  namespace name1::name2 {                                  \
  void func();                                              \
  struct _func_register {                                   \
    _func_register() {                                      \
      register_demo::register_test({#name1, #name2}, func); \
    }                                                       \
  } func_register;                                          \
  }                                                         \
  void name1::name2::func()

static void run() {
  register_demo::run_all_tests();
}
}  // namespace t2_use_template





#endif  // T2_USE_TEMPLATE_H

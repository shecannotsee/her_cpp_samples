#ifndef FOO_H
#define FOO_H
#include <iostream>
#include <utility>

#define PRINT(x) std::cout << x << std::endl

template<typename T>
class foo {
  std::string name_;
  T value_i_;
  T* value_p_;

  public:
    explicit foo(std::string name, const T input): name_(std::move(name)), value_i_(input), value_p_(new T(input)) {
      PRINT(name_ + ": Constructor");
    }

    ~foo() {
      delete value_p_;
      PRINT(name_ + ": Destructor");
    }

    foo(const foo&other): name_(other.name_), value_i_(other.value_i_), value_p_(new T(other.value_i_)) {
      PRINT(name_ + ": Copy constructor");
    }

    foo(foo&&other) noexcept: name_(std::move(other.name_)), value_i_(std::move(other.value_i_)),
                              value_p_(other.value_p_) {
      // clear other
      other.value_i_ = {};
      other.value_p_ = nullptr;
      PRINT(name_ + ": Move constructor");
    }

    foo& operator=(const foo&other) {
      if (this == &other) {
        return *this;
      }
      // Self release
      delete value_p_;
      // Copy from other
      name_ = other.name_;
      value_i_ = other.value_i_;
      value_p_ = new T(value_i_);

      PRINT(name_ + ": Copy assignment operator");
      return *this;
    }


    foo& operator=(foo&&other) noexcept {
      if (this == &other) {
        return *this;
      }
      // Self release
      delete value_p_;
      // Copy from other
      name_ = std::move(other.name_);
      value_i_ = std::move(other.value_i_);
      value_p_ = other.value_p_;
      // clear other
      other.name_ = {};
      other.value_i_ = {};
      other.value_p_ = nullptr;
      PRINT(name_ + ": Move assignment operator");
      return *this;
    }

  public:
    auto get() const -> T {
      return value_i_;
    }

    auto get_p() const -> T* {
      return value_p_;
    }

    auto set_name(const std::string&name) -> void {
      name_ = name;;
    }

    auto get_name() const -> const std::string& {
      return name_;
    }
};


#endif //FOO_H

#ifndef T2_REQUIRES_H
#define T2_REQUIRES_H

#include <iostream>
#include <type_traits>

namespace t2_requires {

// 为 my_type 添加约束
template <typename T>
concept my_type = requires(T t) {
  std::is_class_v<T>;                       // T是一个类
  t.func();                                 // T有func函数
  std::is_same_v<decltype(t.func()), int>;  // T的func函数返回值为int
};

// 使用 my_type
template <my_type T>
int func(T para) {
  return para.func();
}

class my_class {
 public:
  int func() const {
    return value_;
  }

 private:
  int value_{99};
};

inline void run() {
  std::cout << "t2_requires start-----------------------------------------------------------------------------------\n";
  constexpr my_class temp;
  std::cout << func<my_class>(temp) << std::endl;

  std::cout << "t2_requires done\n";
}
}  // namespace t2_requires

#endif  // T2_REQUIRES_H

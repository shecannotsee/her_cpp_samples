#ifndef T1_CONCEPT_H
#define T1_CONCEPT_H

#include <iostream>
#include <type_traits>

namespace t1_concept {

// 为Number类型添加约束
template <typename T>
concept Number = std::is_arithmetic_v<T>;

// 使用 Number, 调用该函数时, T类型必须符合std::is_arithmetic<T>::value等于true, 否则编译报错
template <Number T>
T get_number(T value) {
  return value;
}

struct not_number {};

inline void run() {
  std::cout << "t1_concept start------------------------------------------------------------------------------------\n";
  std::cout << get_number<int>(1) << std::endl;
  std::cout << get_number<double>(1.1) << std::endl;
  // func<not_number>(not_number()); // error
  std::cout << "t1_concept done\n";
}

}  // namespace t1_concept

#endif  // T1_CONCEPT_H

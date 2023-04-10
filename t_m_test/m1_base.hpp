//
// Created by shecannotsee on 2023/4/6.
//

#ifndef T_M_TEST_T_M_TEST_M1_BASE_HPP_
#define T_M_TEST_T_M_TEST_M1_BASE_HPP_

#include <iostream>

namespace m1_base {

template <unsigned long N>
struct binary {
  static unsigned const value = binary<N/10>::value * 2 + N%10;
};

template <>
struct binary<0> {
  static unsigned const value = 0;
};

int main() {
  // 编译期计算
  int number = binary<1111>::value;
  std::cout << number << std::endl;

  return 0;
};

};

#endif //T_M_TEST_T_M_TEST_M1_BASE_HPP_

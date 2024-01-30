//
// Created by  shecannotsee on 2023/1/18.
//

#ifndef TEMPLATE_METAPROGRAMMING_TEST_METHOD_3_H
#define TEMPLATE_METAPROGRAMMING_TEST_METHOD_3_H

#include <iostream>
#include <type_traits>
#include <tuple>

namespace method_3 {

void printN() {
  std::cout<<"\n";
};

// printN递归单参数出口,需要放在多参数同名函数前,以便于编译器来进行实例化的匹配
template<typename LAST>
void printN(LAST t) {
  std::cout << t << "\n";
};

template<typename T0, typename ... T1toN>
void printN(T0 t, T1toN... rest) {
  std::cout << t << ",";
  printN(rest...);
};

void main() {
  std::cout << std::boolalpha;
  printN(9, "shecannotsee", 3.2, false);
  printN();
  printN("hello", "world");

  auto tuple = std::make_tuple(9, "shecannotsee", 3.2, false);
};

};// namespace method_3

#endif //TEMPLATE_METAPROGRAMMING_TEST_METHOD_3_H

//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef TEMPLATE_METAPROGRAMMING_TEST_METHOD_1_H
#define TEMPLATE_METAPROGRAMMING_TEST_METHOD_1_H

#include <iostream>
#include <string>
//#include <type_traits>

// 一些关于模板偏特化和优先级的例子
namespace method_1 {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 使用模板特例化的优先级来处理指针和非指针的情况
template<typename T>
struct is_pointer {
  static constexpr bool value = false;
};
// 特例化
template <typename T>
struct is_pointer<T*> {
  static constexpr bool value = true;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
struct strip_pointer {
  using type = T;
};
// 特例化
template <typename T>
struct strip_pointer<T*> {
  using type = T;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void print(T t) {
  using T_without_pointer = typename strip_pointer<T>::type;
  // /*判断传入类型是否为指针*/
  if constexpr(/*或者使用std::is_pointer<T>::value*/is_pointer<T>::value && std::is_floating_point<T_without_pointer>::value) {
    std::cout<<"Is pointer:["<<*t<<"]\n";
  } else {
    std::cout<<"Is not pointer:["<<t<<"]\n";
  }
};

template<typename A,typename B,typename C>
void print3(A a, B b, C c) {
  print(a);
  print(b);
  print(c);
}

void main() {
  print(1);
  std::string str = "shecannotsee";
  print(&str);
  print(str);

  print3(&str, 3.1, 3.2);

};

};// namespace method_1

#endif //TEMPLATE_METAPROGRAMMING_TEST_METHOD_1_H

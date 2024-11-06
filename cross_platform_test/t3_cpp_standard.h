#ifndef T3_CPP_STANDARD_H
#define T3_CPP_STANDARD_H

#include <iostream>

static void t3_cpp_standard() {
  std::cout << "c++ standrard is        :";
#if __cplusplus >= 202002L
  std::cout << "c++20 implementation" << std::endl;
#elif __cplusplus >= 201703L
  std::cout << "c++17 implementation" << std::endl;
#elif __cplusplus >= 201402L
  std::cout << "c++14 implementation" << std::endl;
#elif __cplusplus >= 201103L
  std::cout << "c++11 implementation" << std::endl;
#else
  std::cout << "c++98 implementation" << std::endl;
#endif
}

#endif //T3_CPP_STANDARD_H

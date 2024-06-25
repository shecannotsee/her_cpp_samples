#ifndef CPP_STANDARD_H
#define CPP_STANDARD_H

static void cpp_standard_display() {
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

#endif // CPP_STANDARD_H

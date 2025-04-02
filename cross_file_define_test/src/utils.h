#ifndef UTILS_H
#define UTILS_H

#include <iostream>

inline void func_header() {
  std::cout << "func_header" << std::endl;
}

inline int global_value = 42;

void print_value();
void make_value_10();


#endif //UTILS_H

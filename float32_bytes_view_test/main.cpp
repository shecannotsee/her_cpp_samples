//
// Created by shecannotsee on 23-9-27.
//
#include <iostream>
#include "t_get_bytes.h"

int main() {
  std::cout << "\033[33m" << "test start" << "\033[0m" << std::endl;

  t_get_bytes::main();

  std::cout << "\033[33m" << "test end" << "\033[0m" << std::endl;
  return 0;
}

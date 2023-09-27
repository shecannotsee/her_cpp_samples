//
// Created by shecannotsee on 23-9-27.
//
#include <iostream>
#include "t1_big_little_check.h"
#include "t2_endian_switch.h"

int main() {
  std::cout << "\033[33m" << "test start" << "\033[0m" << std::endl;

  auto ret = endian_check();
  (ret==endian::big)?
  [](){
    std::cout << "big endian" << std::endl;
  }() :
  [](){
    std::cout << "little endian" << std::endl;
  }();
  t1_big_little_check::main();
  t2_endian_switch::main();

  std::cout << "\033[33m" << "test end" << "\033[0m" << std::endl;
  return 0;
}

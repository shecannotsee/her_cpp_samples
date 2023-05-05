//
// Created by shecannotsee on 2023/4/6.
//

#include <iostream>

#include "m1_base.hpp"
#include "m2_traits.h"

int main() {
  std::cout << "template meta program test start.\n";
  m1_base::main();
  m2_traits::main();
  std::cout << "template meta program test end.\n";
  return 0;
};

//
// Created by shecannotsee on 2023/4/10.
//

#include <iostream>
#include <future>

#include "m1_memory_share_test.h"
#include "m2_display_1_test.h"
#include "m2_display_2_test.h"

int main() {
  std::cout << "memory shared test start.\n";
  //m1_memory_share_test::main();
//  m2_display_1_test::main();
  m2_display_2_test::main();


  std::cout << "memory shared test end.\n";
  return 0;
};

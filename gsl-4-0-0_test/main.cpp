//
// Created by shecannotsee on 2023/3/2.
//
#include <iostream>

#include "global_test_set.h"
#include "t1_algorithms.h"
#include "t2_assert.h"
#include "t3_byte.h"
#include "t4_narrow.h"
#include "t5_pointers.h"
#include "t6_span.h"
#include "t7_zstring.h"
#include "t8_util.h"

int main() {
  std::cout << YELLOW_COLOR << "Start test " << RESET_COLOR << std::endl;
  t1_algorithms::run();


  std::cout << GREEN_COLOR << "Pass the test." << RESET_COLOR << std::endl;
  return 0;
}
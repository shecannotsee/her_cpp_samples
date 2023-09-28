//
// Created by shecannotsee on 23-9-28.
//
#include <iostream>
#include "t1_bit_map.h"
#include "t2_bloom_filter.h"

int main() {
  std::cout << "\033[33m" << "test start" << "\033[0m" << std::endl;

  t1_bitmap::main();
  t2_bloomfilter::main();

  std::cout << "\033[33m" << "test end" << "\033[0m" << std::endl;
  return 0;
}

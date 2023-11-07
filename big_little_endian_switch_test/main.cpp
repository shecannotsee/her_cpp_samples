//
// Created by shecannotsee on 23-9-27.
//
#include <iostream>
#include "t1_big_little_check.h"
#include "t2_endian_switch.h"
#include "t3_stream_and_endian.h"
#include "t4_stream.h"

int main() {
  std::cout << "\033[33m" << "test start" << "\033[0m" << std::endl;

//  t1_big_little_check::main();
//  t2_endian_switch::main();
//  t3_stream_and_endian::main();
  t4_stream::main();

  std::cout << "\033[33m" << "test end" << "\033[0m" << std::endl;
  return 0;
}

//
// Created by shecannotsee on 23-4-25.
//
#include <iostream>
#include "m1_sync_timer_test.h"
#include "m2_async_timer_test.h"

int main() {
  std::cout << "asio test start.\n";

  m1_sync_timer_test::main();
  m2_async_timer_test::main();


  std::cout << "asio test done.\n";
  return 0;
};

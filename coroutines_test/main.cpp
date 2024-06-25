#include <iostream>

#include "t1_easy_sample.h"
#include "t2_leak_sample.h"
#include "t3_sample.h"

int main() {
  std::cout << "coroutines_test start.\n";
  t1_easy_sample::run();
  t2_leak_sample::run();
  t3_sample::run();
  std::cout << "coroutines_test done.\n";
  return 0;
}

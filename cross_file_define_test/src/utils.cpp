#include "utils.h"

void print_value() {
  std::cout << "global_value = " << global_value << std::endl;
}

void make_value_10() {
  global_value = 10;
  std::cout << "global_value = " << global_value << std::endl;
}


#include <iostream>
#include "api_1.h"
#include "api_2.h"

int main() {
  std::cout << "static and inline test" << std::endl;

  std::cout << "----- inline -----" << std::endl;
  api_1::print();
  api_2::print();

  std::cout << "----- static -----" << std::endl;
  api_1::print_s();
  api_2::print_s();

  return 0;
}

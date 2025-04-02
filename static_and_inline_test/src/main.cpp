#include <iostream>
#include "api_1.h"
#include "api_2.h"

int main() {
  std::cout << "static and inline test" << std::endl;

  api_1::print();
  api_2::print();

  return 0;
}

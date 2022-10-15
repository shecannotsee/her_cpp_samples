#include <stdio.h>
#include <string>
#include <iostream>
#include <mysql.h>
#include "query.h"
#include "precompile_test.h"

int main() {
  std::cout<<"method 1:\n";
  method_1();
  std::cout<<"method 2:\n";
  method_2();
  std::cout<<"method 3:\n";
  method_3();
  std::cout<<"program exit.\n";
  return 0;
}
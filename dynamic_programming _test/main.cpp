//
// Created by shecannotsee on 23-9-21.
//
#include <iostream>
#include "t1_make_up_the_number_amount.h"

int main(int argc,char** argv) {
  int range = std::atoi(argv[1]);
  for (int i = 0; i <= range; ++i) {
    t1_make_up_the_number_amount::main(i);
  }
  return 0;
}

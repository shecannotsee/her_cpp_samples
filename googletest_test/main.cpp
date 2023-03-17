//
// Created by shecannotsee on 2022/11/30.
//
#include <iostream>
#include "head.h"
#include "m2_gmock_test.h"

int main(int argc,char* argv[]) {
  std::cout<<"googletest test start.\n";
//  method1::main_r_void();
//  method1::main_r_int();
  m2_gmock_test::main(argc,argv);
  std::cout<<"googletest test end.\n";
  return 0;
};


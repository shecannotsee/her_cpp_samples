//
// Created by shecannotsee on 2023/2/7.
//

#include <iostream>
#include <future>
#include "method_1_base.h"
#include "method_2_sub.h"

int main() {
  std::cout<<"mqtt lib test.\n";
//  method_1_base::main();
//  method_2_sub::main();
  auto sub_future = std::async(method_2_sub::main);
  auto pub_future = std::async(method_1_base::main);
  sub_future.wait();
  pub_future.get();

  std::cout<<"mqtt lib test.\n";
  return 0;
};

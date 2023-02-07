//
// Created by shecannotsee on 2023/2/7.
//

#include <iostream>
#include <future>
#include "method_1_publish_sync.h"
#include "method_2_sub.h"
#include "method_3_publish_async.h"

int main() {
  std::cout<<"mqtt lib test.\n";
  auto sub_future = std::async(std::launch::async, method_2_sub::main);
  auto pub_future = std::async(std::launch::async,method_1_publish_sync::main);
//  sub_future.wait();
//  pub_future.get();

  pub_future.wait();
  std::cout<<"\n";
  sub_future.get();

  std::cout<<"mqtt lib test.\n";
  return 0;
};

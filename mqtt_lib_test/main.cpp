//
// Created by shecannotsee on 2023/2/7.
//

#include <iostream>
#include <future>
#include "method_1_publish_sync.h"
#include "method_2_sub_async.h"
#include "method_3_publish_async.h"
#include "method_4_async_pub.h"
#include "method_5_async_sub.h"
#include "method_6_interface.h"
//#include "method_7_async_ssl_pub.h"// example to read
//#include "method_8_async_ssl_sub.h"// example to read
#include "method_9_cpp_sub.h"
#include "method_10_cpp_ssl_pub.h"
#include "method_11_cpp_pub.h"
#include "method_12_cpp_pub_sub.h"

int main() {
//  std::cout<<"mqtt lib test.\n";
//  auto sub_future       = std::async(std::launch::async, method_2_sub::main);
//  auto pub_sync_future  = std::async(std::launch::async, method_1_publish_sync::main);
//  auto pub_async_future = std::async(std::launch::async, method_3_publish_async::main);
//
//  pub_sync_future.wait();
//  pub_async_future.wait();
//  sub_future.wait();
//  method_3_publish_async::main();
//  method_4_async_pub::main();
//  method_5_async_sub::main();
//  method_9_cpp_sub::main();
//  method_10_cpp_ssl_pub::main();
//  method_11_cpp_pub::main();
  method_12_cpp_pub_sub::main();

  std::cout<<"mqtt lib test.\n";
  return 0;
};

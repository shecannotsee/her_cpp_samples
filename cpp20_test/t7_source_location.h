//
// Created by shecannotsee on 24-7-8.
//

#ifndef T7_SOURCE_LOCATION_H
#define T7_SOURCE_LOCATION_H

#include <iostream>
#include <source_location>
#include <string_view>

namespace t7_source_location {
void log(const std::string_view message,
         const std::source_location location =
           std::source_location::current()) {
  std::cout << "file: " << location.file_name() << std::endl;
  std::cout << "line: " << location.line() << std::endl;
  std::cout << "column:" << location.column() << std::endl;
  std::cout << "function_name: " << location.function_name() << std::endl;
  std::cout << "log meg: " << message << std::endl;
}

template<typename T>
void fun(T x) {
  log(x); // 第 25 行
}

int main() {
  std::cout << "t7_source_location start----------------------------------------------------------------------------\n";

  log("Hello world!"); // 第 31 行
  fun("Hello C++20!");

  std::cout << "t6_endian done\n";
}
}

#endif //T7_SOURCE_LOCATION_H

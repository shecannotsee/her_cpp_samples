//
// Created by shecannotsee on 24-5-10.
//
#include "source_code_check.h"
#include "string_support.h"
#include <iostream>

int main() {
  {
    const auto source_code = a::b();

    std::cout << "Process source_code ......\n";
    std::cout << source_code << std::endl;
    std::cout << remove_spaces_and_new_lines(source_code) << std::endl;
    std::cout << adler32(remove_spaces_and_new_lines(source_code)) << std::endl;
  }
  {
    const auto source_code = a::b1();

    std::cout << "Process source_code ......\n";
    std::cout << source_code << std::endl;
    std::cout << remove_spaces_and_new_lines(source_code) << std::endl;
    std::cout << adler32(remove_spaces_and_new_lines(source_code)) << std::endl;
  }

  return 0;
}

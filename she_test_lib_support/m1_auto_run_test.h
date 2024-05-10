//
// Created by shecannotsee on 24-5-10.
//

#ifndef M1_AUTO_RUN_TEST_H
#define M1_AUTO_RUN_TEST_H

#include "source_code_check.h"
#include "string_support.h"
#include <iostream>

namespace m1_auto_run_test {
inline int main() {
  {
    const auto source_code = a::b();
    unsigned int flag = 0;

    std::cout << "Process source_code ......\n";
    std::cout << source_code << std::endl;
    std::cout << remove_spaces_and_new_lines(source_code) << std::endl;
    std::cout << [&flag, &source_code]() {
      flag = adler32(remove_spaces_and_new_lines(source_code));
      return flag;
    }() << std::endl;
    if (flag == 1008534972) {
      std::cout << "The source code has not been modified\n";
    } else {
      std::cout << "The source code has been modified\n";
    }
  }
  {
    const auto source_code = a::b1();
    unsigned int flag = 0;

    std::cout << "Process source_code ......\n";
    std::cout << source_code << std::endl;
    std::cout << remove_spaces_and_new_lines(source_code) << std::endl;
    std::cout << [&flag, &source_code]() {
      flag = adler32(remove_spaces_and_new_lines(source_code));
      return flag;
    }() << std::endl;
    if (flag == 816324916) {
      std::cout << "The source code has not been modified\n";
    } else {
      std::cout << "The source code has been modified\n";
    }
  }

  return 0;
}
} // namespace m1_auto_run_test

#endif // M1_AUTO_RUN_TEST_H

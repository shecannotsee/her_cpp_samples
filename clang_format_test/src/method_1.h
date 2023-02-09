//
// Created by shecannotsee on 2023/2/9.
//

#ifndef CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_METHOD_1_H_
#define CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_METHOD_1_H_

#include <test_class/test_class.h>

namespace method_1 {

enum state : unsigned char { s1, s2, s3, s4 };

void main() {
  test_class tool(7);
  tool.set_data(6);
  tool.get_data();
};

};  // namespace method_1

#endif  // CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_METHOD_1_H_

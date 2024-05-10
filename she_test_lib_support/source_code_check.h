//
// Created by shecannotsee on 24-5-10.
//

#ifndef SOURCE_CODE_CHECK_H
#define SOURCE_CODE_CHECK_H

#include <cstdio> // Include the necessary header for printf
#include <string>

#define STRINGIFY(x) #x
#define SHE_TEST_STORE(test_suite_name, test_name, code)                       \
  namespace test_suite_name {                                                  \
  std::string test_name() {                                                    \
    code;                                                                      \
    return std::string(#code);                                                 \
  }                                                                            \
  }

SHE_TEST_STORE(a, b, { printf("123\n"); })
SHE_TEST_STORE(a, b1, {
  // 测试数学运算
  int num1 = 10;
  int num2 = 5;
  printf("10+5=%d", num1 + num2);
  printf("10-5=%d", num1 - num2);
  printf("10x5=%d", num1 * num2);
})


#endif // SOURCE_CODE_CHECK_H

//
// Created by shecannotsee on 24-5-10.
//

#ifndef M2_MOCK_TEST_H
#define M2_MOCK_TEST_H

#include <dlfcn.h>
#include <stdio.h>

namespace m2_mock_test {
int func() {
  return 0;
}

int func_mock() {
  return -1;
}


// 测试函数，不修改其内部代码
bool test() {
  if (func() == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // 执行测试
  printf("Test result: %s\n", test() ? "Passed" : "Failed");

  return 0;
}
}


#endif //M2_MOCK_TEST_H

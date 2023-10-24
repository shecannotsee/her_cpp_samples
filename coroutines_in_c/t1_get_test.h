//
// Created by shecannotsee on 23-10-24.
//

#ifndef COROUTINES_IN_C_T1_GET_TEST_H
#define COROUTINES_IN_C_T1_GET_TEST_H

#include "coroutine.h"
#include <string>
#include <vector>
#include <memory>

namespace t1_get_test {

void get () {
  // 打开文件
  FILE *file = fopen("../test_file.txt", "r");
  if (file == NULL) {
    std::cout <<"can not open file.\n";
    return;
  }

  // 逐个字符读取并打印
  char c;
  while ((c = fgetc(file)) != EOF) {
    if( c == '\n' ) {
      std::cout << "\\n" << std::endl;
    } else {
      std::cout << c << std::endl;
    }
  }

  // 关闭文件
  fclose(file);
}

void main() {


}


}// namespace t1_get_test

#endif //COROUTINES_IN_C_T1_GET_TEST_H

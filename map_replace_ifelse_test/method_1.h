//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef MAP_REPLACE_IFELSE_TEST_METHOD_1_H
#define MAP_REPLACE_IFELSE_TEST_METHOD_1_H

#include <iostream>

// 使用传统的if else
namespace method_1 {

enum class if_branch : unsigned int {
  b_1 = 1,
  b_2,
  b_3,
  b_4,
  b_5
};

void main() {
  if_branch use = if_branch::b_1;

  if (use==if_branch::b_1) {
    std::cout<<"b_1"<<std::endl;
  }
  else if (use==if_branch::b_2) {
    std::cout<<"b_2"<<std::endl;
  }
  else if (use==if_branch::b_3) {
    std::cout<<"b_3"<<std::endl;
  }
  else if (use==if_branch::b_4) {
    std::cout<<"b_4"<<std::endl;
  }
  else if (use==if_branch::b_5) {
    std::cout<<"b_5"<<std::endl;
  }

};

};// namespace method_1

#endif //MAP_REPLACE_IFELSE_TEST_METHOD_1_H

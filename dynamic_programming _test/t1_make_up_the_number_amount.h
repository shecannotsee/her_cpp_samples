//
// Created by shecannotsee on 23-9-21.
//

#ifndef DP_TEST_T1_MAKE_UP_THE_NUMBER_AMOUNT_H
#define DP_TEST_T1_MAKE_UP_THE_NUMBER_AMOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace t1_make_up_the_number_amount {

void cal(int num, std::unordered_map<int,int>& num_paper) {
  if (num_paper.count(num) > 0) {
    // 已经计算过了
    return;
  } else {
    int temp = 0;
    // 尚未计算
    /*zzz*/if (num > 11) {

    } else if (num >  5) {

    } else if (num >  0) {

    }

    num_paper.insert(std::make_pair(num,temp));
    return;
  }
}

int get_min_paper(int num) {
  // 11 5 1
  int paper = num;// 使用的张数

  std::unordered_map<int,int> num_paper;/*init*/ {
    num_paper.insert(std::make_pair( 1,1));
    num_paper.insert(std::make_pair( 5,1));
    num_paper.insert(std::make_pair(11,1));
  }
  /* file num_paper, Incremental */
  for (int i = 1; i <= num; i++) {
    cal(i,num_paper);
  }

  return num_paper[num];
}

int main(int argc,char** argv) {
  std::cout << "test start" << std::endl;
  std::cout << "argc numbers:" << argc << std::endl;
  int value = 0;
  for (size_t i = 0; i < argc; i++) {
    std::cout << argv[i] << (i==argc-1? "\n" : " ");
    value = std::atoi(argv[1]);
  }

  std::cout << "===============\n";
  std::cout << "value(11,5,1):[" << get_min_paper(value) << "]\n";

  std::cout << "===============\ntest end" << std::endl;
  return 0;
}



}// namespace t1_make_up_the_number_amount {

#endif //DP_TEST_T1_MAKE_UP_THE_NUMBER_AMOUNT_H

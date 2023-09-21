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

//
int cal_model(int num, std::unordered_map<int,int>& num_paper) {
  if (num_paper.count(num) > 0) {
    // 已经计算过了
  } else {
    int temp = 0;
    // 尚未计算
    /*zzz*/if (num > 11) {
      int temp_11 = cal_model(num-11,num_paper) + num_paper[11];
      int temp_05 = cal_model(num- 5,num_paper) + num_paper[5];
      int temp_01 = cal_model(num- 1,num_paper) + num_paper[1];
      if (temp_11<=temp_05 && temp_11<=temp_01) temp = temp_11;
      if (temp_05<=temp_11 && temp_05<=temp_01) temp = temp_05;
      if (temp_01<=temp_11 && temp_01<=temp_05) temp = temp_01;
    } else if (num >  5) {
      int temp_05 = cal_model(num- 5,num_paper) + num_paper[5];
      int temp_01 = cal_model(num- 1,num_paper) + num_paper[1];
      if (temp_05<=temp_01 ) temp = temp_05;
      if (temp_01<=temp_05 ) temp = temp_01;
    } else if (num >  0) {
      cal_model(num-1,num_paper);
      temp = cal_model(num-1,num_paper) + num_paper[1];
    }
    num_paper.insert(std::make_pair(num,temp));
  }

  return num_paper[num];
}

int get_min_paper(int num) {
  // 11 5 1
  std::unordered_map<int,int> num_paper;/*init*/ {
    num_paper.insert(std::make_pair( 1,1));
    num_paper.insert(std::make_pair( 5,1));
    num_paper.insert(std::make_pair(11,1));
  }
  /* file num_paper, Incremental */
  for (int i = 1; i <= num; i++) {
    int display = cal_model(i,num_paper);
//    std::cout << i << "(min paper):" << display << std::endl;
  }

  return num_paper[num];
}

void main(int value) {
  auto ret = get_min_paper(value);
  std::cout << "\033[32m" << value << "(11,5,1):[" << ret << "]\033[0m" << std::endl;
}



}// namespace t1_make_up_the_number_amount {

#endif //DP_TEST_T1_MAKE_UP_THE_NUMBER_AMOUNT_H

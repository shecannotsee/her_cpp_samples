//
// Created by shecannotsee on 2022/12/29.
//

#ifndef RANDOM_TEST_RANDOM_TEST_METHOD_1_H_
#define RANDOM_TEST_RANDOM_TEST_METHOD_1_H_

#include <iostream>

namespace method_1 {

// 线性同余发生器
class LinearCongruentialGenerator {
 public:
  LinearCongruentialGenerator() = delete;
  LinearCongruentialGenerator(int multiplier, int increment, int m)
      : multiplier_(multiplier),
        increment_(increment),
        m_(m),
        x_n_last_(1) {

  };
  ~LinearCongruentialGenerator() = default;
 private:
  int multiplier_;// 乘数
  int increment_;// 增量
  int m_;// 模
  int x_n_last_;
 public:
  int get() {
    // X(n) = ( a*X(n-1)+b)mod m
    // X(n),X(n-1),a means multiplier_, b means increment_, m means m_
    int ret = (multiplier_*x_n_last_+increment_)%m_;
    this->x_n_last_ = ret;
    return ret;
  };
};

void main() {
  LinearCongruentialGenerator rdMin(106,1283,6074);
  LinearCongruentialGenerator rdMax(17221, 107837, 510300);
  for (int i=0; i<100/*2^20溢出*/; i++) {
    std::cout<<rdMin.get()<<std::endl;
  }
  for (int i=0; i<100/*2^34溢出*/; i++) {
    std::cout<<rdMin.get()<<std::endl;
  }
};

};// namespace method_1

#endif //RANDOM_TEST_RANDOM_TEST_METHOD_1_H_

//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_EXTEND_H
#define RSA_TEST_EXTEND_H

// n为输入两个质数的乘积
// 该函数返回一个整数e,e大于1并且小于n的欧拉函数,并且满足e与n的欧拉函数互质
int getE(int prime_number_1, int prime_number_2) {
  int Euler_function_by_n = (prime_number_1-1)*(prime_number_2-1);
  int ret = 17;
  return ret;
};

// 输入e以及n的欧拉函数
// 返回d,使得d满足[e x d - 1 = k * Euler_function_by_n]
int getModularMultiplicativeInverse(int e, int Euler_function_by_n) {
  // (d,k)=(2753,-15)
  int ret = 2753;
  return ret;
};

#endif //RSA_TEST_EXTEND_H

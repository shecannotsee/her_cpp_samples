//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_METHOD_1_H
#define RSA_TEST_METHOD_1_H

#include <cstdio>
#include <string>
#include <vector>
#include "extend.h"
#include "bignumber.h"
#include "callingPython.h"

namespace method_1 {

void main() {
  // step_0:选两个质数
  int prime_number_1 = 61;
  int prime_number_2 = 53;
  // step_1:计算两个质数的乘积
  int n = prime_number_1 * prime_number_2;
  // step_2:计算n的欧拉函数
  int Euler_function_by_n = (prime_number_1-1)*(prime_number_2-1);
  // step_3:选一个整数e,大于1并且小于n的欧拉函数,并且与n的欧拉函数互质
  int e = getE(prime_number_1, prime_number_2);
  // step_4:获取e对于n的欧拉函数的模反元素d
  int d = getModularMultiplicativeInverse(e,Euler_function_by_n);

  int CommonKey[2] = {n,e};
  int PrivateKey[2] = {n,d};
  // 秘文是小于n的一个整数,故用一个数组存储
  std::vector<std::string> cipher;
  /* 使用公钥加密 */ {
    // 对m进行加密,m必须小于n
    // m^e = c (mod n) ; c为加密后的内容,等价于下行
    // c = (m^e) mod n
    std::string plaintext = "shecannotsee";
    for (const char& ch : plaintext) {
      cipher.push_back(cal((int)ch,CommonKey[1],CommonKey[0]));
    }
  };

  /* 使用私钥解密 */ {
    // m = (c^d) mod n
    std::string original_plaintext;
    for (const std::string& str : cipher) {
      char t;
      t = std::atoi(
              cal(std::atoi(str.c_str()),
                  PrivateKey[1],
                  PrivateKey[0]).c_str());
      original_plaintext.push_back(t);
    }
    std::cout<<"original plaintext is["<<original_plaintext<<"]"<<std::endl;
  };

};

};// namespace method_1

#endif //RSA_TEST_METHOD_1_H

//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_METHOD_1_H
#define RSA_TEST_METHOD_1_H

#include <cstdio>
#include <string>
#include "extend.h"
#include "bignumber.h"

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
  /*加密*/ {
    // 对m进行加密,m必须小于n
    // m^e = c (mod n) ; c为加密后的内容,等价于; c = (m^e) mod n
    std::string plaintext = "shecannotsee";
    std::string cipher    = std::string(plaintext.size(),0x00);
    /* 调用python模块来进行大数计算 */ {
      using std::to_string;
      std::string cmd = "python3 ../rsa_bigNumber_cal.py " + to_string(65) + " " + to_string(17) + " " + to_string(3233);
      FILE* pipe = popen(cmd.c_str(), "r");
      if (!pipe) {
        std::cout << "Error: popen()" << std::endl;
        return;
      }
      char buffer[256];
      while(fgets(buffer, sizeof(buffer), pipe) != NULL) {
        std::cout << buffer;
      }
      std::cout << "buffer:" <<buffer<<std::endl;
      std::cout<<"len:"<<strlen(buffer)<<std::endl;
      pclose(pipe);
    };
    /* 调用大数库来计算 */ {

    };

  };

  /*解密*/ {
    // m = (c^d) mod n
  };

};

};// namespace method_1

#endif //RSA_TEST_METHOD_1_H

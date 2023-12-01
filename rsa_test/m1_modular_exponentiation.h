//
// Created by shecannotsee on 23-12-1.
//

#ifndef MODULAR_EXPONENTIATION_H
#define MODULAR_EXPONENTIATION_H

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

namespace m1_modular_exponentiation {

// @param arg_1:在加密的时候是[明文],解密的时候是[]
// @param arg_2:在加密的时候是[与两质数的欧拉函数互质的一个数e],解密的时候是[e对于两质数的欧拉函数的模反元素]
// @param prime_product:两个质数的乘积
std::string call_python_to_cal(int arg_1,int arg_2,int prime_product) {
  using std::to_string;
  std::string cmd =
          "python3 ../rsa_bigNumber_cal.py "
          + to_string(arg_1) + " "
          + to_string(arg_2) + " "
          + to_string(prime_product);
  FILE* pipe = popen(cmd.c_str(), "r");
  if (!pipe) {
    std::cout << "Error: popen()" << std::endl;
    exit(1);
  }
  char buffer[256];
  while(fgets(buffer, sizeof(buffer), pipe) != NULL) {
    //std::cout << buffer;
  }
  pclose(pipe);
//  std::cout << "buffer:" <<buffer<<std::endl;
//  std::cout<<"len:"<<strlen(buffer)<<std::endl;
  return std::string(buffer,strlen(buffer));
};

std::string fast_cal(unsigned long long arg_1,unsigned long long arg_2,unsigned long long prime_product) {
  unsigned long long result = 1;
  arg_1 = arg_1 % prime_product;  // 对底数取模，防止溢出

  while (arg_2 > 0) {
    // 如果当前指数为奇数，累乘到结果中
    if (arg_2 % 2 == 1) {
      result = (result * arg_1) % prime_product;
    }

    // 将指数右移一位（相当于除以2）
    arg_2 = arg_2 / 2;

    // 底数平方取模
    arg_1 = (arg_1 * arg_1) % prime_product;
  }

  return std::to_string(result);
}

}

#endif //MODULAR_EXPONENTIATION_H

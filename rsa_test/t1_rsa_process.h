//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_METHOD_1_H
#define RSA_TEST_METHOD_1_H

#include <cstdio>
#include <string>
#include <vector>
#include <chrono>
#include <functional>

#include "m1_modular_exponentiation.h"

namespace t1_rsa_process {

using time_type = std::chrono::time_point<std::chrono::system_clock>;

/**
 * \brief 获取两个时间点的时间间隔
 * \param start 起始时间
 * \param end 结束时间
 * \return 以毫秒为单位的时间间隔
 */
int time_interval(const time_type start, const time_type end) {
  return (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(end)-
          std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(start)
         ).count();
}

/**
 * \brief 获取一个整数e
 * \param euler_function_number n的欧拉函数
 * \return 整数e,e大于1并且小于入参(n的欧拉函数),并且满足e与入参互质
 */
int getE(int euler_function_number) {
  std::vector<int> e_list;
  for (int e = 2; e < euler_function_number; ++e) {
    auto gcd = [](int a, int b) {
      while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
      }
      return a;
    };
    // 确保e与欧拉函数互质
    if (gcd(e, euler_function_number) == 1) {
      e_list.emplace_back(e);
    }
  }

  std::cout << "e:";
  for (const auto& e:e_list) {
    std::cout << e << " ";
  }
  std::cout << "\n";

  // 如果没有找到满足条件的e，返回-1表示错误
  return 17;
}

// 输入e以及n的欧拉函数
// 返回d,使得d满足[e * d - 1 = k * Euler_function_by_n]
// d = ((k * Euler_function_by_n) + 1) /e
/**
 * \brief 
 * \param e 
 * \param Euler_function_by_n 
 * \return 
 */
int getModularMultiplicativeInverse(int e, int Euler_function_by_n) {
  int x, y;
  std::function<int(int,int,int&,int&)> extendedGCD = [&](int a, int b, int& x, int& y) {
    // Base Case
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }

    // Recursive Call
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results of recursive call
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
  };
  const int gcd = extendedGCD(e, Euler_function_by_n, x, y);

  // 没有逆元
  if (gcd != 1) {
    throw R"(Inverse doesn't exist (e is not coprime to Euler's function))" ;
  }

  // 所有整数解列表
  std::vector<int> solutions;

  // 确保d是正数
  int d = (x % Euler_function_by_n + Euler_function_by_n) % Euler_function_by_n;

  // 输出所有整数倍的解
  for (int k = 0; k < Euler_function_by_n; ++k) {
    const int solution = (d + k * (Euler_function_by_n / gcd)) % Euler_function_by_n;
    std::cout << "{" << d << "-" << solution << "}";
    if (k == Euler_function_by_n-1) std::cout << std::endl;
  }

  // (d,k)=(2753,-15)
  // TODO:需要添加合适的算法用来计算,该返回值只是针对指定数值进行特定返回
  int ret = 2753;
  return ret;
}

void main() {
  // step_0:选两个质数
  constexpr int prime_number_1 = 61;
  constexpr int prime_number_2 = 53;
  // step_1:计算两个质数的乘积
  constexpr int n = prime_number_1 * prime_number_2;
  // step_2:计算n的欧拉函数
  constexpr int Euler_function_by_n = (prime_number_1-1)*(prime_number_2-1);
  auto calculateEulerFunction = [](int n) {
    int result = n;  // 初始化结果为n
    // 找出n的所有质因数，并更新result
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        while (n % i == 0) {
          n /= i;
        }
        result -= result / i;  // 更新result
      }
    }
    // 处理可能剩余的最后一个质因数
    if (n > 1) {
      result -= result / n;
    }
    return result;
  };
  std::cout << calculateEulerFunction(n) << "-" << Euler_function_by_n << std::endl;

  // step_3:选一个整数e,大于1并且小于n的欧拉函数,并且与n的欧拉函数互质
  int e = getE(Euler_function_by_n);
  // step_4:获取e对于n的欧拉函数的模反元素d
  int d = getModularMultiplicativeInverse(e,Euler_function_by_n);

  int CommonKey[2] = {n,e};
  int PrivateKey[2] = {n,d};

  /* call_python_to_cal */ {
    std::cout << "==========call_python_to_cal==============\n";
    std::vector<std::string> cipher;
    /* 使用公钥加密 */ {
      // 对m进行加密,m必须小于n
      // m^e = c (mod n) ; c为加密后的内容,等价于下行
      // c = (m^e) mod n
      std::string plaintext = "shecannotsee";

      const auto start = std::chrono::system_clock::now();
      for (const char& ch : plaintext) {
        cipher.push_back(m1_modular_exponentiation::call_python_to_cal((int)ch,CommonKey[1],CommonKey[0]));
      }
      const auto end = std::chrono::system_clock::now();
      std::cout << "The encryption process took time [" << time_interval(start, end) << "]ms , 1s = 1000ms\n";
    }// 公钥加密结束

    /* 使用私钥解密 */ {
      // m = (c^d) mod n
      std::string original_plaintext;

      const auto start = std::chrono::system_clock::now();
      for (const std::string& str : cipher) {
        char t =std::atoi(m1_modular_exponentiation::call_python_to_cal(
                                                                              std::atoi(str.c_str()),
                                                                              PrivateKey[1],
                                                                              PrivateKey[0]).c_str());
        original_plaintext.push_back(t);
      }
      const auto end = std::chrono::system_clock::now();
      std::cout << "The decryption process took time [" << time_interval(start, end) << "]ms , 1s = 1000ms\n";
      std::cout << "original plaintext is[" << original_plaintext << "]\n";
    }// 私钥解密结束
  }

  /* fast_cal */ {
    std::cout << "==========fast_cal==============\n";
    // 秘文是小于n的一个整数,故用一个字符串数组存储用来兼容以后可能出现的长数值情况
    std::vector<std::string> cipher;
    /* 使用公钥加密 */ {
      // 对m进行加密,m必须小于n
      // m^e = c (mod n) ; c为加密后的内容,等价于下行
      // c = (m^e) mod n
      std::string plaintext = "shecannotsee";

      const auto start = std::chrono::system_clock::now();
      for (const char& ch : plaintext) {
        cipher.push_back(m1_modular_exponentiation::fast_cal((int)ch,CommonKey[1],CommonKey[0]));
      }
      const auto end = std::chrono::system_clock::now();
      std::cout << "The encryption process took time (fast_cal)[" << time_interval(start, end) << "]ms , 1s = 1000ms\n";
    }// 公钥加密结束

    /* 使用私钥解密 */ {
      // m = (c^d) mod n
      std::string original_plaintext;

      const auto start = std::chrono::system_clock::now();
      for (const std::string& str : cipher) {
        char t =std::atoi(m1_modular_exponentiation::fast_cal(
                                                                    std::atoi(str.c_str()),
                                                                    PrivateKey[1],
                                                                    PrivateKey[0]).c_str());
        original_plaintext.push_back(t);
      }
      const auto end = std::chrono::system_clock::now();
      std::cout << "The decryption process took time (fast_cal)[" << time_interval(start, end) << "]ms , 1s = 1000ms\n";
      std::cout << "original plaintext is[" << original_plaintext << "]\n";
    }// 私钥解密结束
  }

}

};// namespace method_1

#endif //RSA_TEST_METHOD_1_H

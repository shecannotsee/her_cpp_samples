//
// Created by shecannotsee on 24-5-10.
//

#ifndef STRING_SUPPORT_H
#define STRING_SUPPORT_H

#include <algorithm>

inline std::string remove_spaces_and_new_lines(const std::string& str) {
  std::string result;
  // 使用标准库中的算法 remove_if 和 lambda 表达式来移除空格和回车
  std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result),
                      [](const char c) { return std::isspace(c); });
  return result;
}

inline unsigned int adler32(const std::string& data) {
  unsigned int a = 1, b = 0;

  for (const char c : data) {
    constexpr unsigned int MOD_ADLER = 65521;
    a = (a + c) % MOD_ADLER;
    b = (b + a) % MOD_ADLER;
  }

  return (b << 16) | a;
}

#endif //STRING_SUPPORT_H

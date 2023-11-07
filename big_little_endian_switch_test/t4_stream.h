//
// Created by shecannotsee on 23-11-7.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H

#include <string>

namespace t4_stream {

void main() {
  std::string _1;
  std::string _2;
  {
    std::string a = "1234567890";

    auto x1 = [&]() -> std::string {
      return std::string(a.begin() + 2, a.begin() + 4);
    }();// "34"
    _1 = std::move(x1);

    auto x2 = [&]() -> std::string {
      return "1" + std::string(a.begin() + 2, a.begin() + 4);
    }();// "34"
    _2 = std::move(x2);
  }
  _1;
  _2;

}

}// namespace t4_stream

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H

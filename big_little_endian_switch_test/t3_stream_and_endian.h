//
// Created by shecannotsee on 23-11-7.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T3_STREAM_AND_ENDIAN_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T3_STREAM_AND_ENDIAN_H

#include <iostream>
#include <cstdint>
#include <arpa/inet.h>

namespace t3_stream_and_endian {

void main() {
  std::uint8_t stream[2]={0xF0,0x0F};// 从左往右也就是0xF00F的十进制表示是61455,0x0FF0是4080
  std::uint16_t data = 0xF00F;
  std::cout << data << std::endl;
  std::uint16_t data_big = htons(data);
  std::cout << data_big << std::endl;

  std::uint16_t b = (static_cast<std::uint8_t>(stream[0]) << 8) | static_cast<std::uint8_t>(stream[1]);
  std::cout << b << std::endl;
}

}

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T3_STREAM_AND_ENDIAN_H

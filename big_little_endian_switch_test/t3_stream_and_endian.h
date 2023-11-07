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
  /* 16位的测试与处理 */ {
    std::cout << "\033[32m" << "16 bits test" << "\033[0m" << std::endl;
    std::uint8_t stream[2] = {0xF0, 0x0F};// 从左往右也就是0xF00F的十进制表示是61455,0x0FF0是4080
    std::uint16_t data = 0xF00F;
    std::cout << data << std::endl;
    std::uint16_t data_big = htons(data);
    std::cout << data_big << std::endl;

    // 小端处理法
    std::uint16_t b_little = (static_cast<std::uint8_t>(stream[0]) << 8) |
                             (static_cast<std::uint8_t>(stream[1]) << 0);
    std::cout << b_little << std::endl;
    // 大端处理法
    std::uint16_t b_big = (static_cast<std::uint8_t>(stream[1]) << 8) |
                          (static_cast<std::uint8_t>(stream[0]) << 0);
    std::cout << b_big << std::endl;
  }

  /* 32位的测试与处理 */ {
    std::cout << "\033[32m" << "32 bits test" << "\033[0m" << std::endl;
    std::uint8_t stream[4] = {0xF0, 0x0F, 0x00 ,0x00};// 从左往右也就是0xF00F0000的十进制表示是4027514880₁₀,0x00000FF0是4080
    std::uint32_t data = 0xF00F0000;
    std::cout << data << std::endl;
    std::uint32_t data_big = htonl(data);
    std::cout << data_big << std::endl;

    // 小端处理法
    std::uint32_t b_little = (static_cast<std::uint8_t>(stream[0]) << 24) |
                             (static_cast<std::uint8_t>(stream[1]) << 16) |
                             (static_cast<std::uint8_t>(stream[2]) <<  8) |
                             (static_cast<std::uint8_t>(stream[3]) <<  0);
    std::cout << b_little << std::endl;
    // 大端处理法
    std::uint32_t b_big = (static_cast<std::uint8_t>(stream[3]) << 24) |
                          (static_cast<std::uint8_t>(stream[2]) << 16) |
                          (static_cast<std::uint8_t>(stream[1]) <<  8) |
                          (static_cast<std::uint8_t>(stream[0]) <<  0);
    std::cout << b_big << std::endl;
  }


}

}

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T3_STREAM_AND_ENDIAN_H

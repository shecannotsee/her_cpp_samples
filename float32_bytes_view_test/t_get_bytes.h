//
// Created by shecannotsee on 23-9-27.
//

#ifndef FLOAT32_BYTES_VIEW_TEST_T_GET_BYTES_H
#define FLOAT32_BYTES_VIEW_TEST_T_GET_BYTES_H

#include <cstring>
#include <bitset>

namespace t_get_bytes {

void main() {
  float float32 = 173.8125;

  // 将float数的内存表示解释为字节数组
  constexpr int size_of_float = sizeof(float32);
  unsigned char bytes[size_of_float];
  std::memcpy(bytes, &float32, size_of_float);

  // [0][1][2][3]
  {
    for (int i = 0; i < size_of_float; i++) {
      for (int j = 7; j >= 0; j--) { // 从最高位开始遍历到最低位
        unsigned char bit = (bytes[i] >> j) & 0x01; // 通过右移和位与操作获取每个位的值
        if (bit == 0) {
          std::cout << "0";
        } else if (bit == 1) {
          std::cout << "1";
        }
      }
    }
    std::cout << std::endl;
    // 打印每个字节的二进制表示
    for (int i = 0; i < size_of_float; ++i) {
      std::bitset<8> byteBits(bytes[i]);
      std::cout << "字节 " << i << ": " << byteBits << std::endl;
    }
  }

  // [3][2][1][0]
  {
    for (int i = size_of_float - 1; i >= 0; i--) {
      for (int j = 7; j >= 0; j--) { // 从最高位开始遍历到最低位
        unsigned char bit = (bytes[i] >> j) & 0x01; // 通过右移和位与操作获取每个位的值
        if (bit == 0) {
          std::cout << "0";
        } else if (bit == 1) {
          std::cout << "1";
        }
      }
    }
    std::cout << std::endl;
    // 打印每个字节的二进制表示
    for (int i = size_of_float - 1; i >= 0; i--) {
      std::bitset<8> byteBits(bytes[i]);
      std::cout << "字节 " << i << ": " << byteBits << std::endl;
    }
  }

}

}

#endif //FLOAT32_BYTES_VIEW_TEST_T_GET_BYTES_H

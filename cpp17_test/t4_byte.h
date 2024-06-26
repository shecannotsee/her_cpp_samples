#ifndef T4_BYTE_H
#define T4_BYTE_H

#include <t4_byte.h>

#include <bitset>
#include <cstddef>
#include <iostream>

namespace t4_byte {

constexpr int byte_bits = 8;    // 通常一个byte有多少位
constexpr int byte_min  = 0;    // byte最小值
constexpr int byte_max  = 255;  // byte最大值

/**
 * @brief 打印byte的bits, 类似 [0  :00000000]
 * @param tmp 需要进行展示的byte
 */
inline void display(const std::byte tmp) {
  std::cout << std::to_integer<int>(tmp) << "\t:";
  // 用 bitset 展示输出
  std::cout << std::bitset<sizeof(std::byte) * 8>(std::to_integer<int>(tmp)) << std::endl;
}

inline void run() {
  std::cout << "t4_byte start---------------------------------------------------------------------------------------\n";

  std::byte min{byte_min};
  display(min);

  std::byte max{byte_max};
  display(max);
  std::cout << "==============\n";
  std::byte bits_array{1};
  display(bits_array);
  std::cout << "==============\n";
  for (int i = 0; i < 10; i++) {
    bits_array <<= 1;
    display(bits_array);
  }
  std::cout << "==============\n";
  for (int i = 0; i < 10; i++) {
    bits_array |= std::byte{1};  //+1
    bits_array <<= 1;
    bits_array |= std::byte{1};  // +1
    display(bits_array);
  }

  std::cout << "t4_byte done\n";
}

}  // namespace t4_byte

#endif  // T4_BYTE_H

#ifndef T6_ENDIAN_H
#define T6_ENDIAN_H

#include <iostream>
#include <bit>

namespace t6_endian {

inline void run() {
  std::cout << "t6_endian start-------------------------------------------------------------------------------------\n";

  if constexpr (std::endian::native == std::endian::big) {
    std::cout << "大端\n";
  }
  else if constexpr (std::endian::native == std::endian::little) {
    std::cout << "小端\n";
  }
  else {
    std::cout << "混合端序\n";
  }

  std::cout << "t6_endian done\n";
}

}

#endif //T6_ENDIAN_H

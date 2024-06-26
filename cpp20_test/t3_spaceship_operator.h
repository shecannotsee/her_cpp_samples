#ifndef T3_SPACESHIP_OPERATOR_H
#define T3_SPACESHIP_OPERATOR_H

#include <compare>
#include <iostream>

namespace t3_spaceship_operator {

inline void run() {
  std::cout << "t3_spaceship_operator start-------------------------------------------------------------------------\n";

  for (int i = 0; i < 3; i++) {
    constexpr int b = 1;
    const std::strong_ordering result = i <=> b;

    if (result == std::strong_ordering::less) {
      std::cout << "a is less than b" << std::endl;
    } else if (result == std::strong_ordering::equal) {
      std::cout << "a is equal to b" << std::endl;
    } else if (result == std::strong_ordering::greater) {
      std::cout << "a is greater than b" << std::endl;
    }

    if (result < 0) {
      std::cout << "a is less than b" << std::endl;
    } else if (result == 0) {
      std::cout << "a is equal to b" << std::endl;
    } else if (result > 0) {
      std::cout << "a is greater than b" << std::endl;
    }
  }

  std::cout << "t3_spaceship_operator done\n";
}
}  // namespace t3_spaceship_operator

#endif  // T3_SPACESHIP_OPERATOR_H

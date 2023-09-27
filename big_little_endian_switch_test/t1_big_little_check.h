//
// Created by shecannotsee on 23-9-27.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T1_BIG_LITTLE_CHECK_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T1_BIG_LITTLE_CHECK_H

namespace t1_big_little_check {

void main() {
  union {
    int i;
    char c[sizeof(int)];
  } endianness = {1};

  if (endianness.c[0] == 1) {
    std::cout << "Little endian" << std::endl;
  } else {
    std::cout << "Big endian" << std::endl;
  }
}

}// namespace t1_big_little_check

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T1_BIG_LITTLE_CHECK_H

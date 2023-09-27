//
// Created by shecannotsee on 23-9-27.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T1_BIG_LITTLE_CHECK_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T1_BIG_LITTLE_CHECK_H

enum class endian {
  little = 0,
  big    = 1
};

endian endian_check() {
  //  0x1234567(example)
  //  0x00 0x01 0x10 0x11 ......(memory address)
  //  01   23   45   67 ......(big endian)
  //  67   45   23   01 ......(little endian)
  // 对于unsigned int a = 1 => 0x00 00 00 01
  //  00   00   00   01
  //  01   00   00   00
  endian ret = endian::little;
  unsigned int a = 1;
  void* p = &a;
  if (
  ((unsigned char*)p)[0] == 0
    ) {
    ret = endian::big;
  }
  else {
    ret = endian::little;
  }

  return ret;
}

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

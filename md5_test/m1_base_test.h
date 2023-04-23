//
// Created by shecannotsee on 23-4-23.
//

#ifndef CMAKE_TEST_MD5_TEST_M1_BASE_TEST_H_
#define CMAKE_TEST_MD5_TEST_M1_BASE_TEST_H_


#include <string>
#include <valarray>

namespace m1_base_test {
// f(x,y,z) = (x [and] y) [or] ( ([not]x) [and] z)
// g(x,y,z) = (x [and] z) [or] ( y [and]  ([not]z) )
// h(x,y,z) = x [xor] y [xor] z
// i(x,y,z) = y [xor] (x [or] ([not]z) )

auto FF(unsigned char x,unsigned char y, unsigned z) -> unsigned char {
  unsigned char ret = 0x00;

  return ret;
}

void main() {
  unsigned char group[64];/* init */ {
    for (unsigned char & i : group) {
      i = 0x00;
    }
  }
  unsigned int M[16];/* init */ {
    for (unsigned int & i : M) {
      i = 0;
    }
  }
  for (int i = 0; i < 16; ++i) {
    M[i] += static_cast<unsigned int>(group[i*4+0]) << 3;
    M[i] += static_cast<unsigned int>(group[i*4+1]) << 2;
    M[i] += static_cast<unsigned int>(group[i*4+2]) << 1;
    M[i] += static_cast<unsigned int>(group[i*4+3]) << 0;
  }

  for (int i = 0; i < 64; ++i) {
    unsigned int T_i = (unsigned int) (4294967296 * abs(sin(i + 1)));
  }


  static const unsigned char A = 0x67452301;
  static const unsigned char B = 0xefcdab89;
  static const unsigned char C = 0x98badcfe;
  static const unsigned char D = 0x10325476;


};

};// namespace m1_base_test

#endif //CMAKE_TEST_MD5_TEST_M1_BASE_TEST_H_

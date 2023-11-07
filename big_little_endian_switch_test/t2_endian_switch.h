//
// Created by shecannotsee on 23-9-27.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T2_ENDIAN_SWITCH_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T2_ENDIAN_SWITCH_H

namespace t2_endian_switch {

enum class endian {
  little = 0,
  big    = 1
};

static endian endian_check() {
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

#define ENDIAN_SWAP16(A) ((((uint16_t)(A) & 0xff00) >> 8)      | \
                          (((uint16_t)(A) & 0x00ff) << 8))

#define ENDIAN_SWAP32(A) ((((uint32_t)(A) & 0xff000000)  >> 24) | \
                          (((uint32_t)(A)  & 0x00ff0000) >>  8) | \
                          (((uint32_t)(A)  & 0x0000ff00) <<  8) | \
                          (((uint32_t)(A)  & 0x000000ff) << 24))
/*
 * htonl/ntohl/htons/ntohs impl
*/
#define hton32(h) (endian_check() == endian::big) ? h : ENDIAN_SWAP32(h))
#define ntoh32(n) (endian_check() == endian::big) ? n : ENDIAN_SWAP32(n))
#define hton16(h) (endian_check() == endian::big) ? h : ENDIAN_SWAP16(h))
#define ntoh16(n) (endian_check() == endian::big) ? n : ENDIAN_SWAP16(n))

// The network is always the big endian
#define HOST_TO_NETWORK_32(net)   htonl(net)
#define NETWORK_TO_HOST_32(host)  ntohl(host)
#define HOST_TO_NETWORK_16(net)   htons(net)
#define NETWORK_TO_HOST_16(host)  ntohs(host)

void main() {
  (endian_check()==endian::big)?
  [](){
    std::cout << "big endian" << std::endl;
  }() :
  [](){
    std::cout << "little endian" << std::endl;
  }();
}

}// namespace t2_endian_switch

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T2_ENDIAN_SWITCH_H

//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_BIGNUMBER_TEST_H
#define RSA_TEST_BIGNUMBER_TEST_H

#include "bignumber.h"

namespace bignumber_test {

void main() {
  std::string a = BigNumber("2").pow(3).getString();
  std::cout<<a<<std::endl;

};

};// namespace bignumber_test

#endif //RSA_TEST_BIGNUMBER_TEST_H

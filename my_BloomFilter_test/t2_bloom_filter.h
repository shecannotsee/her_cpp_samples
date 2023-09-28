//
// Created by shecannotsee on 23-9-28.
//

#ifndef MY_BLOOMFILTER_TEST_T2_BLOOM_FILTER_H
#define MY_BLOOMFILTER_TEST_T2_BLOOM_FILTER_H

#include "bloom_filter.h"

namespace t2_bloomfilter {

void main() {
  BloomFilter bf;

  bf.add("function_use1");
  bf.add("function_use2");
  bf.add("function_use3");

  std::cout<<bf.find("function_use1")<<"\n";
  std::cout<<bf.find("function_use2")<<"\n";
  std::cout<<bf.find("function_use3")<<"\n";

  std::cout<<bf.find("functionuse1")<<"\n";

  bf.debug();

}

}// namespace t2_bloomfilter

#endif //MY_BLOOMFILTER_TEST_T2_BLOOM_FILTER_H

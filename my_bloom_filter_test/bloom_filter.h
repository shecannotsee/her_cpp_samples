//
// Created by shecannotsee on 23-9-28.
//

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#define __SHE_TEST_
#ifdef  __SHE_TEST_
#include <iostream>
#endif//!__SHE_TEST_

#include "bit_map.h"
#include "hash.h"

class bloom_filter
{
 public:
  bloom_filter(){
    m_bitmap = new bit_map(1024);
  };

  ~bloom_filter(){
    delete m_bitmap;
    m_bitmap = nullptr;
  };

  void add(const char *str){
    m_bitmap->turnOn(HashBKDR<char>(str)%1024);
    m_bitmap->turnOn(HashAP<char>(str)%1024);
    m_bitmap->turnOn(HashDEK<char>(str)%1024);
  };

  int find(const char *str){
    if(m_bitmap->find(HashBKDR<char>(str)%1024)&&
       m_bitmap->find(HashAP<char>(str)%1024)&&
       m_bitmap->find(HashDEK<char>(str)%1024)
      ){
      return 1;
    }
    else{
      return 0;
    }
  };

  void debug(){
#ifdef __SHE_TEST_
    std::cout<<"Bloom Fliter Debug.\n";
#endif//!__SHE_TEST_
  };

 private:
  bit_map *m_bitmap;

};

#endif // BLOOM_FILTER_H

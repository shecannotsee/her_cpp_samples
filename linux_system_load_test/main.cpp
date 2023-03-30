//
// Created by shecannotsee on 2022/12/9.
//
#include <iostream>
//#include "getMemory.h"
//#include "getCpu.h"
#include "get_process_cpu_memory.h"

int main (int argc,char* argv[],char* env[]) {
  for (int i = 0; i < argc; i++) {
    std::cout<<argv[i]<<"\n";
  }

  for (int i = 0; env[i] != nullptr; i++) {
    //std::cout << env[i] << std::endl;
  }
//  getMemory::main();
//  getCpu::main();
  get_process_cpu_memory::main();
  return 0;
}

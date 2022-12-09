//
// Created by shecannotsee on 2022/12/9.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETMEMORY_H_
#define LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETMEMORY_H_

#include <iostream>
#include <sys/sysinfo.h>

#define sell_param 1000
#define comp_param 1024

namespace getMemory {

void main() {
  // 获取系统信息
  struct sysinfo info;
  sysinfo(&info);

  // 获取总内存大小
  std::cout << "Total memory: " << (unsigned long long)info.totalram<<" B" << std::endl;
  std::cout << "Total memory: " << (info.totalram)/(double)(1024)<<" KB" << std::endl;
  std::cout << "Total memory: " << (info.totalram)/(double)(1024*1024)<<" MB" << std::endl;
  std::cout << "Total memory: " << (info.totalram)/(double)(comp_param*comp_param*comp_param)<<" GB" << std::endl;


  // 获取已使用的内存大小
  std::cout << "Used memory: " << info.totalram - info.freeram << std::endl;

  // 获取可用的内存大小
  std::cout << "Available memory: " << info.freeram << std::endl;

  // 获取平均负载
  std::cout << "Average load: " << info.loads[0] / 65536.0 << std::endl;
};

};

#endif //LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETMEMORY_H_

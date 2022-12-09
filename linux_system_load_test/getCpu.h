//
// Created by shecannotsee on 2022/12/9.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETCPU_H_
#define LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETCPU_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <unistd.h>

namespace getCpu {

double get_cpu_usage(int cpu_id) {
  // 打开/proc/stat文件
  std::ifstream stat_file("/proc/stat");
  if (!stat_file.is_open()) {
    std::cerr << "Failed to open /proc/stat" << std::endl;
    return 0.0;
  }

  // 读取文件中的内容
  std::string line;
  while (std::getline(stat_file, line)) {
    // 如果找到了指定的核心
    if (line.find("cpu" + std::to_string(cpu_id) + " ") == 0) {
      // 解析该行内容
      std::istringstream iss(line);
      std::vector<unsigned long long> values(10);
      for (int i = 0; i < 10; i++) {
        iss >> values[i];
      }

      // 计算核心的使用情况
      if (values[1] + values[2] + values[3] == 0)
      {
        return 0.0;
      }
      else {
        return (values[1] + values[2] + values[3]) /
            static_cast<double>(values[1] + values[2] + values[3] + values[4]);
      }
    }
  }

  return 0.0;
}

void main() {
  // 获取CPU的核心数
  int ncpus = sysconf(_SC_NPROCESSORS_ONLN);
  std::cout << "Number of CPUs: " << ncpus << std::endl;

  // 获取每个核心的使用情况
  for (int i = 0; i < ncpus; i++)
  {
    std::cout << "CPU " << i << ": " << get_cpu_usage(i) << std::endl;
  }

};

};

#endif //LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GETCPU_H_

//
// Created by shecannotsee on 2023/2/16.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GET_PROCESS_CPU_MEMORY_H_
#define LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GET_PROCESS_CPU_MEMORY_H_

#include <stdio.h>
#include <stdlib.h>// exit
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

namespace get_process_cpu_memory {

int get_pid(const std::string& process_name) {
  char command[256];
  int pid = 0;
  // 构造pidof命令
  snprintf(command, sizeof(command), "pidof %s", process_name.c_str());

  // 执行pidof命令并获取输出结果
  FILE *fp = popen(command, "r");
  if (!fp) {
    fprintf(stderr, "Failed to execute command: %s\n", command);
    exit(1);
  }

  // 读取pidof命令输出的PID
  if (fscanf(fp, "%d", &pid) != 1) {
    fprintf(stderr, "Failed to read PID from command output.\n");
    exit(1);
  }

  // 关闭进程
  pclose(fp);

  // 打印PID
  printf("PID of %s: %d\n", process_name.c_str(), pid);

  return pid;
};

void main() {
  int pid = get_pid("mosquitto");

  std::ifstream memInfo("/proc/<pid>/status");
  int vmRSS = 0;
  std::string line;
  while (std::getline(memInfo, line)) {
    if (line.find("VmRSS:") != std::string::npos) {
      std::sscanf(line.c_str(), "VmRSS: %d kB", &vmRSS);
      break;
    }
  }
  memInfo.close();
  std::cout << "Memory usage: " << vmRSS * 1024 << " bytes" << std::endl;

  std::ifstream stat("/proc/<pid>/stat");
  long long utime, stime;
  stat >> utime >> stime;
  stat.close();
  std::cout << "CPU usage: " << static_cast<double>(utime + stime) / sysconf(_SC_CLK_TCK) << " seconds" << std::endl;
};

};// namespace get_process_cpu_memory

#endif //LINUX_SYSTEM_LOAD_TEST_LINUX_SYSTEM_LOAD_TEST_GET_PROCESS_CPU_MEMORY_H_

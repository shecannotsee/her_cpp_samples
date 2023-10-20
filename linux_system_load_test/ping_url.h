//
// Created by shecannotsee on 23-10-20.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_PING_URL_H
#define LINUX_SYSTEM_LOAD_TEST_PING_URL_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

namespace ping_url {

int main() {
  const char* host = "www.example12345.com";  // 默认要ping的主机名或IP地址
  int pingCount = 4;  // 默认ping的数量
  int pingInterval = 1;  // 默认ping的间隔

  // 构建ping命令
  std::string pingCmd = "ping -c " + std::to_string(pingCount) + " -i " + std::to_string(pingInterval) + " " + host;

  // 使用system系统调用执行ping命令
  int pingResult = system(pingCmd.c_str());

  // 检查ping的返回值
  if (WIFEXITED(pingResult)) {
    int exitStatus = WEXITSTATUS(pingResult);
    if (exitStatus == 0) {
      std::cout << "Ping succeeded." << std::endl;
    } else {
      std::cout << "Ping failed with exit status: " << exitStatus << std::endl;
    }
  } else {
    std::cerr << "Ping command execution failed." << std::endl;
  }

  return 0;
}

}// namespace ping_url

#endif //LINUX_SYSTEM_LOAD_TEST_PING_URL_H

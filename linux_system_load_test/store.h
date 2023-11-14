//
// Created by shecannotsee on 23-11-14.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_STORE_H
#define LINUX_SYSTEM_LOAD_TEST_STORE_H

#include <iostream>
#include <iomanip>
#include <sys/statvfs.h>
#include <cmath>

namespace store {

std::string formatBytes(long long bytes) {
  const int unit = 1024;
  if (bytes < unit) return std::to_string(bytes) + " B";
  int exp = static_cast<int>(std::log2(bytes) / std::log2(unit));
  const char* units[] = {"KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
  return std::to_string(bytes / std::pow(unit, exp)) + " " + units[exp - 1];
}

bool checkStorageSpace() {
  struct statvfs buffer;

  if (statvfs("/", &buffer) == 0) {
    double freePercentage = static_cast<double>(buffer.f_bavail) / buffer.f_blocks * 100.0;

    std::cout << "Total blocks: " << buffer.f_blocks << std::endl;
    std::cout << "Free blocks: " << buffer.f_bfree << std::endl;
    std::cout << "Available blocks for non-root: " << buffer.f_bavail << std::endl;
    std::cout << "Block size: " << buffer.f_frsize << " bytes" << std::endl;
    std::cout << "Free space: " << formatBytes(buffer.f_bavail * buffer.f_frsize) << std::endl;
    std::cout << "Free space percentage: " << std::fixed << std::setprecision(2) << freePercentage << "%" << std::endl;

    return (freePercentage > 5.0);
  } else {
    perror("statvfs");
  }

  return true;
}

int main() {
  if (checkStorageSpace()) {
    std::cout << "There is enough storage space." << std::endl;
    return 0;
  } else {
    std::cout << "Insufficient storage space." << std::endl;
    return 1;
  }
}

}

#endif //LINUX_SYSTEM_LOAD_TEST_STORE_H

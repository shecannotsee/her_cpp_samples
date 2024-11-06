#ifndef T1_OS_H
#define T1_OS_H

#include <iostream>

static void t1_os() {
  std::cout << "The operating system is :";

#ifdef __linux__
  std::cout << "Linux.\n";
#elif defined(_WIN32) || defined(_WIN64)
  std::cout << "Windows.\n";
#elif defined(__APPLE__)
  std::cout << "Mac.\n";
#else
  // If run here, compilation will be terminated
#error "Unknown platform"
#endif
}

#endif //T1_OS_H

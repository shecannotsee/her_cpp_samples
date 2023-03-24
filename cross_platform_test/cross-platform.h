//
// Created by shecannotsee on 2023/3/24.
//

#ifndef BENCHMARK_TEST_CROSS_PLATFORM_TEST_CROSS_PLATFORM_H_
#define BENCHMARK_TEST_CROSS_PLATFORM_TEST_CROSS_PLATFORM_H_

#include <iostream>

static void os_display() {
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

};

static void compiler_display() {
  std::cout << "The compiler used is \t:";
  #ifdef __GNUC__
    std::cout << "GNUC.\n";
  #elif defined(__MINGW32__) || defined(__MINGW64__)
    std::cout << "Mingw.\n";
  #elif defined(__clang__)
    std::cout << "Clang.\n";
  #elif defined(_MSC_VER)
    std::cout << "MSVC.\n";
  #else
    // If run here, compilation will be terminated
    #error "Unknown compiler"
  #endif

};

#endif //BENCHMARK_TEST_CROSS_PLATFORM_TEST_CROSS_PLATFORM_H_

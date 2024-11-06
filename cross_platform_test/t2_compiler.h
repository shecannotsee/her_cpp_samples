#ifndef T2_COMPILER_H
#define T2_COMPILER_H

#include <iostream>

static void t2_compiler() {
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
}

#endif //T2_COMPILER_H

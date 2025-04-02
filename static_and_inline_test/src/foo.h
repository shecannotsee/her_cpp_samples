#ifndef FOO_H
#define FOO_H

#include <iostream>

inline void foo_inline() {
  static int _ = 0;
  _++;
  std::cout << "foo_inline: " << _ << std::endl;
}

static void foo_static() {
  static int _ = 0;
  _++;
  std::cout << "foo_static:" << _ << std::endl;
}

#endif  // FOO_H

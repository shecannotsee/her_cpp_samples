#include <iostream>

#include "t1_qwidget_display_test.h"

int main(int argc, char *argv[]) {
  std::cout << "\033[33m" << "test start" << "\033[0m" << std::endl;

  t1_qwidget_display_test::main(argc, argv);


  std::cout << "\033[33m" << "test end" << "\033[0m" << std::endl;
  return 0;
}

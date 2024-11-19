#include <iostream>

#include "t2_use_template.h"

using namespace t2_use_template;

TEST1(test_name1) {
  std::cout << "test_name1" << std::endl;
}

TEST2(test_name1, test_name2) {
  std::cout << "test_name1,test_name2" << std::endl;
}
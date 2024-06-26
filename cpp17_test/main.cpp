#include <iostream>
#include "t1_filesystem.h"
#include "t2_optional.h"
#include "t3_variant.h"
#include "t4_byte.h"
#include "t5_structured_binding.h"
#include "t6_init_if.h"
#include "t7_attribute.h"

int main() {
  std::cout << "cpp17_test start------------------------------------------------------------------------------------\n";

  t1_filesystem::run();
  t2_optional::run();
  t3_variant::run();
  t4_byte::run();
  t5_structured_binding::run();
  t6_init_if::run();
  t7_attribute::run();

  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "cpp17_test done\n";
  return 0;
}

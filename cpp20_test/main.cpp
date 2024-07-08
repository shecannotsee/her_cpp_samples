#include <iostream>
#include "t1_concept.h"
#include "t2_requires.h"
#include "t3_spaceship_operator.h"
#include "t4_jthread.h"
#include "t5_chrono.h"
#include "t6_endian.h"
#include "t7_source_location.h"

int main() {
  std::cout << "cpp20_test start------------------------------------------------------------------------------------\n";

  t1_concept::run();
  t2_requires::run();
  t3_spaceship_operator::run();
  t4_jthread::run();
  t5_chrono::run();
  t6_endian::run();
  t7_source_location::main();

  std::cout << "cpp20_test done\n";
  return 0;
}

#include <iostream>
#include "t1_concept.h"
#include "t2_requires.h"

int main() {
  std::cout << "concept_and_requires_test start---------------------------------------------------------------------\n";

  t1_concept::run();
  t2_requires::run();

  std::cout << "concept_and_requires_test done\n";
  return 0;
}

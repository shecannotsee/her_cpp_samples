//
// Created by shecannotsee on 2023/2/2.
//

#include <iostream>
#include "method_1_base.h"

//int main() {
//  std::cout<<"benchmark test start.\n";
//  method_1_base::main();
//  std::cout<<"benchmark test end.\n";
//  return 0;
//};
static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    [](){int i=0;};
  }
}

BENCHMARK(BM_SomeFunction);
BENCHMARK_MAIN();

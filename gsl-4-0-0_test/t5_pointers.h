//
// Created by shecannotsee on 24-2-1.
//

#ifndef T5_POINTERS_H
#define T5_POINTERS_H

#include "global_test_set.h"

namespace t5_pointers {

gsl::owner<int*> allocateResource() {
  return new int(42);
}

void useResource(gsl::owner<int*> resource) {
  // 使用资源
  // ...

  // 资源将在函数结束时释放，调用方不再拥有它
  delete resource;
}


void run() noexcept {
  auto p = allocateResource();
  useResource(p);
}

}  // namespace t5_pointers

#endif  // T5_POINTERS_H

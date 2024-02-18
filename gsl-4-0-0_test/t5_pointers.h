//
// Created by shecannotsee on 24-2-1.
//

#ifndef T5_POINTERS_H
#define T5_POINTERS_H

#include "global_test_set.h"

namespace t5_pointers {

// 使用 gsl::owner 作为函数返回类型
gsl::owner<int*> createInt() {
  return new int(42);
}

// 使用 gsl::not_null 作为函数参数类型
void printValue(gsl::not_null<int*> ptr) {
  std::cout << "Value: " << *ptr << std::endl;
}

void run() noexcept {
  std::cout << YELLOW_COLOR << "[t5_pointers::run] >>> start" << RESET_COLOR << std::endl;
  gsl::final_action<std::function<void()>> _(
      []() { std::cout << GREEN_COLOR << "[t5_pointers::run] >>> done" << RESET_COLOR << "\n\n"; });

  // 使用 gsl::owner 作为指针类型
  gsl::owner<int*> ptr = createInt();

  // 使用 gsl::not_null 作为指针类型
  gsl::not_null<int*> notNullPtr = gsl::make_not_null(ptr);

  // 使用 gsl::strict_not_null 作为指针类型
  gsl::strict_not_null<int*> strictNotNullPtr = gsl::make_strict_not_null(ptr);

  // 使用 not_null 指针调用函数
  printValue(notNullPtr);

  // 使用 strict_not_null 指针调用函数
  printValue(strictNotNullPtr);

  // 释放指针内存
  delete ptr;
}

}  // namespace t5_pointers

#endif  // T5_POINTERS_H

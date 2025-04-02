#include <iostream>

namespace library {

inline namespace V1 {
void foo() {
  std::cout << "V1::foo()" << std::endl;
}
}// namespace V1

namespace V2 {  // 新版本，但不是 inline
void foo() { std::cout << "V2::foo()" << std::endl; }
} // namespace V2

} // namespace library

int main() {
  library::foo();   // 直接访问 V1::foo()
  library::V2::foo(); // 需要显式指定 V2
  library::V1::foo(); // 访问 V1::foo()

  return 0;
}

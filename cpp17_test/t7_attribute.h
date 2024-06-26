#ifndef T7_ATTRIBUTE_H
#define T7_ATTRIBUTE_H
#include <t7_attribute.h>

namespace t7_attribute {

// attribute:[[nodiscard]] 当出现警告的时候意味着该接口的返回值没有被使用,会导致内存泄漏
[[nodiscard]] inline int* create() {
  auto p = new int(10);
  return p;
}

// attribute:[[nodiscard]] 当出现警告的时候意味着需要通过返回值来检查是否已经释放了内存
[[nodiscard]] inline bool release(const int* p) {
  delete p;
  return true;
}

// attribute:[[maybe_unused]] 修饰一个可能不会被用到的返回值或者是参数
template <bool debug>
[[maybe_unused]] inline bool foo(int val, const std::string& msg) {
  if (debug) {
    std::cout << "debug:" << msg << std::endl;
  }
  return true;
}

// attribute:[[deprecated]] 表示弃用一个命名空间
namespace [[deprecated]] DraftAPI {
int a{10};
}

inline void run() {
  std::cout << "t7_attribute start----------------------------------------------------------------------------------\n";

  // [[nodiscard]]
  {
    std::cout << "--[[nodiscard]]:";
    int* p = create();
    release(p);  // 没有用到返回值,编译阶段会出现警告
    std::cout << "\n";
  }
  // [[maybe_unused]]
  {
    std::cout << "--[[maybe_unused]]:";
    foo<false>(1, "input 1");
    foo<true>(1, "input 1");
  }

  // [[fallthrough]]
  {
    std::cout << "--[[fallthrough]]:";
    switch (1) {
      case 1:
        std::cout << "very ";
        // attribute:[[fallthrough]] 可以避免编译器在 switch 语句中某一个标签缺少 break 语句时发出警告
        [[fallthrough]];
      case 2:
        std::cout << "well\n";
        break;
      default:
        std::cout << "OK\n";
    }
  }
  // [[deprecated]]
  {
    DraftAPI::a;
  }

  std::cout << "t7_attribute done\n";
}

}  // namespace t7_attribute

#endif  // T7_ATTRIBUTE_H

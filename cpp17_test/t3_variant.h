#ifndef T3_VARIANT_H
#define T3_VARIANT_H

#include <iostream>
#include <variant>

namespace t3_variant {

inline void run() {
  std::cout << "t3_variant start------------------------------------------------------------------------------------\n";

  std::variant<int, float> v1 = 42;
  // get
  {
    int get_v1 = 0;
    get_v1     = std::get<int>(v1);
    std::cout << get_v1 << " ";
    get_v1 = std::get<0>(v1);
    std::cout << get_v1 << "\n";
    try {
      std::get<float>(v1);  // v1 含 int 而非 float：会抛出异常
    } catch (const std::bad_variant_access& ex) {
      std::cout << ex.what() << '\n';
    }
  }

  //  std::get<double>(v); // 错误：[int, float] 中无 double
  //  std::get<3>(v);      // 错误：有效索引值为 0 与 1


  // int 用 float 替代
  v1.emplace<float>(11.2);
  // get
  {
    float get_v1 = 0.0;
    get_v1     = std::get<float>(v1);
    std::cout << get_v1 << " ";
    get_v1 = std::get<1>(v1);
    std::cout << get_v1 << "\n";
    try {
      std::get<int>(v1);  // v1 此时含 floag 而非 int：会抛出异常
    } catch (const std::bad_variant_access& ex) {
      std::cout << ex.what() << '\n';
    }
  }

  std::cout << "t3_variant done\n";
}

}  // namespace t3_variant

#endif  // T3_VARIANT_H

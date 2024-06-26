#ifndef T2_OPTIONAL_H
#define T2_OPTIONAL_H

#include <iostream>
#include <optional>

namespace t2_optional {

/**
 * @brief 测试接口
 * @param return_str 是否返回一个带值的std::optional
 * @return 返回一个std::optional
 */
inline std::optional<std::string> get_string(bool return_str) {
  if (return_str) {
    return std::make_optional(std::string("hello world"));
  } else {
    return std::nullopt;
  }
}

inline void run() {
  std::cout << "t2_optional start-----------------------------------------------------------------------------------\n";

  auto ret = get_string(true);
  if (ret.has_value()) {
    std::cout << "--has value:" << ret.value() << "\n";
  } else {
    std::cout << "--no value!\n";
  }

  ret = get_string(false);
  if (ret.has_value()) {
    std::cout << "--has value:" << ret.value() << "\n";
  } else {
    std::cout << "--no value!\n";
  }

  std::cout << "t2_optional done\n";
}

}  // namespace t2_optional

#endif  // T2_OPTIONAL_H

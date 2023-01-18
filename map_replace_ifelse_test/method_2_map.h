//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H
#define MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H

#include <string>
#include <unordered_map>
#include <functional>
#include <type_traits>

namespace method_2_map {

enum class if_branch : unsigned int {
  b_1 = 1,
  b_2,
  b_3,
  b_4,
  b_5
};

void main() {
  std::unordered_map<if_branch, std::string> hashMapError;
  hashMapError.insert(std::make_pair(if_branch::b_1, "function_1"));

  std::unordered_map<std::underlying_type<if_branch>::type , std::string> hashMap;
  hashMap.insert(std::make_pair(static_cast<std::underlying_type<if_branch>::type>(if_branch::b_1),"function"));


};

};// namespace method_2_map

#endif //MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H

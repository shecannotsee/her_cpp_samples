//
// Created by  shecannotsee on 2023/1/14.
//

#ifndef MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H
#define MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
namespace method_2_map {

template<typename branch_name>
class Function_map {
 private:
  std::unordered_map<branch_name, std::function<void(void*)>> functions_;
 public:
  Function_map() {
    branch_name branch_1;
    functions_.insert(std::make_pair(branch_1,std::bind(&FunctionMap::case_1, this, std::placeholders::_1)));
    branch_name branch_2;
    functions_.insert(std::make_pair(branch_2,std::bind(&FunctionMap::case_2, this, std::placeholders::_1)));
    branch_name branch_3;
    functions_.insert(std::make_pair(branch_3,std::bind(&FunctionMap::case_3, this, std::placeholders::_1)));
  };
 public:
  void find(branch_name input_branch, void* params) {
    auto it = functions_.find(input_branch);
    if (it != functions_.end()) {
      it->second(params);
    } else {
      std::cout << "Unknown branch" << std::endl;
    }
  };
 private:
  void case_1(void* params) {
    std::cout<<static_cast<int>(*params);
  };
  void case_2(void* params) {

  };
  void case_3(void* params) {

  };

};

void main() {

};

};// namespace method_2_map

#endif //MAP_REPLACE_IFELSE_TEST_METHOD_2_MAP_H

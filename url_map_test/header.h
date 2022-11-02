//
// Created by shecannotsee on 2022/11/2.
//

#ifndef STL_TEST_URL_MAP_TEST_HEAD_H_
#define STL_TEST_URL_MAP_TEST_HEAD_H_

#include <string>
#include <map>
#include <tuple>

namespace method1 {
using std::map;
using std::string;
using std::tuple;

static const map<string, tuple<string,string>> route = {
    {"interface name",      {"POST","url"}},
    {"1",                   {"POST","1url"}},
    {"end",                 {"POST","url"}}
};

void main() {
  // 接口名称
  std::string i = "end";

  if (route.find(i)==route.end()) {//没有该接口
    std::cout<< "can not find interface["<<i<<"].\n";
  }
  else { // 有该接口
    std::cout << "method:["
              << std::get<0>(route.find(i)->second)
              << "]\npath:["
              << std::get<1>(route.find(i)->second)
              << "]" <<std::endl;
  }
};

}; // namespace method1

#endif //STL_TEST_URL_MAP_TEST_HEAD_H_

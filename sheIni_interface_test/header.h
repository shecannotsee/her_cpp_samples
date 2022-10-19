//
// Created by shecannotsee on 2022/10/19.
//

#ifndef SPDLOG_TEST_SHEINI_INTERFACE_TEST_HEADER_H_
#define SPDLOG_TEST_SHEINI_INTERFACE_TEST_HEADER_H_
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "DataStructure/Section.h"
#include "Parse/Parse.h"

namespace method1{

void getConfig(std::vector<std::string>& t) {
  std::vector<sheIni::Section> config;
  /* get config from file */ {
    sheIni::IniFile config_file("test.config");
    config_file.parse(config);
  };

  std::unordered_set<std::string> hash_set;
  for (int i=1;i<t.size();++i)
    hash_set.insert(t[i]);

  //std::vector<std::string>::iterator it = std::find(t.begin(),t.end(),t.size());
  auto find_key = [&](std::string key){
    return std::find(t.begin(),t.end(),key);
  };

  for (auto& e:config) {
    // get section
    if (e.getSection() == t[0]) {
      // get the key-value under the section
      for (auto& ee: e.getAllKV() ) {
        if (hash_set.count(std::get<0>(ee))==1) {
          auto it = find_key(std::get<0>(ee));
          if (it != t.end())
            (*it) = std::get<1>(ee);
        }
      }
    }
  }
}

void main() {
  std::vector<std::string> _p_ = {"mysql","ip","port","today","eat_dinner"};
  for (std::string& e:_p_) std::cout<<e<<",";
  std::cout<<std::endl;
};
};//namespace method1

#endif //SPDLOG_TEST_SHEINI_INTERFACE_TEST_HEADER_H_

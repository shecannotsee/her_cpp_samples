//
// Created by  shecannotsee on 2022/11/4.
//

#ifndef SQLITE3_TEST_HEADER_H
#define SQLITE3_TEST_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

namespace method1 {
void main() {
  /* base test */ {
    std::cout<<"base test:\n";
    std::string str1 = "{ \"happy\": true, \"pi\": 3.141 }";
    std::string str2 = R"({"happy": true, "pi": 3.141})";
    std::cout<<"std::string :"<<str1<<std::endl;
    // 从字符串转化成json
    nlohmann::json json = nlohmann::json::parse(str1);
    std::cout<<"nlohmann json :"<<json<<std::endl;
    // 将nlohmann json 转换为std::string
    std::string str3 = json.dump(4);
    std::cout<<"nlohmann json to std::string :"<<str3<<std::endl;
  };
  /* get json key value */ {
    std::cout<<"\nget json key value test:\n";
    std::string str1 = "{ \"happy\": true, \"pi\": 3.141 }";
    nlohmann::json json = nlohmann::json::parse(str1);
    std::cout<<"json[\"happy\"] :"<<json["happy"]<<std::endl;
    std::cout<<"json[\"pi\"] :"<<json["pi"]<<std::endl;
    auto a = json["unknown"];
    if(json["unknown"].empty())
      std::cout<<"no json key is unknown.\n";
    else
      std::cout<<"has json-key is unknown\n";
  };

};
};// namespace method1

namespace method2 {
void main() {
  /* get json from json.file */ {
    std::cout<<"\nget json from json.file test:\n";
    std::ifstream json_file("../user_request.json");// 注意读取文件的位置
    nlohmann::json json_request;
    json_file>>json_request;
    std::cout<<json_request<<std::endl;
    for (auto e : json_request) {
    }

  };
};

};// namespace method2

#endif //SQLITE3_TEST_HEADER_H

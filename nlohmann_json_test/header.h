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
    std::cout<<"json[\"unknown\"]:"<<json["unknown"]<<std::endl;
    std::cout<<"json.at(\"unknown\"):"<<json.at("unknown")<<std::endl;
    if(json["unknown"].empty())
      std::cout<<"no json key is unknown.\n";
    else
      std::cout<<"has json-key is unknown\n";
  };
  /* push array */ {
    std::cout<<"\npush array test:\n";
    nlohmann::json data1 = nlohmann::json::parse("{ \"happy\": true, \"pi\": 3.141 }");
    nlohmann::json json;
    json["data"].push_back(data1);
    data1["pi"] = 2.2222;
    json["data"].push_back(data1);
    std::cout<<"after push array :"<<json.dump(4)<<std::endl;
    std::cout<<"json data[] size :"<<json["data"].size()<<std::endl;
    for (auto& e:json["data"]) {
      std::cout<<e["happy"]<<","<<e["pi"]<<std::endl;
    }
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
    std::cout<<json_request.dump(4)<<std::endl;
    nlohmann::json user;
    user["name"] = "Carry";
    user["age"]  = 25;
  };
};

};// namespace method2

#endif //SQLITE3_TEST_HEADER_H

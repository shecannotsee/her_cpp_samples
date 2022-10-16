//
// Created by pc on 2022/10/17.
//
#include <iostream>
#include <string>
#include <map> // std::map
#include <map> // std::multimap can have [java]:10,[java]:9
#include <unordered_map> //std::unordered_map-> hash map,not red black tree//c++11
#include <unordered_map> //std::unordered_multimap-> hash map, //c++11

int main() {
  std::cout<<"start.\n";

  /* base */ {
    std::map<std::string, int> data_1;
    auto traversal_map = [&](){
      for (const auto& e:data_1)
        std::cout<<e.first<<":"<<e.second<<"\n";
      std::cout<<std::endl;
    };
    data_1["java"] = 10; // add java:10
    data_1["java"] = 9;  // modify java: 10 ->9
    traversal_map();
    data_1.insert(std::make_pair("cpp",12));
    data_1.insert(std::make_pair("lisp",321));
    traversal_map();
    // find key[]
    std::cout<<"============== find key[golang] ==============\n";
    if (data_1.find("golang") == data_1.end())
      std::cout<<"can not find key[golang]\n";
    std::cout<<"golang has :"<<data_1.count("golang")<<"\n";
    std::cout<<"cpp has :"<<data_1.count("cpp")<<"\n";
    // move element
    std::cout<<"============== move element ==============\n";
    traversal_map();
    data_1.erase("cpp");
    traversal_map();
  }


  std::cout<<"end.\n";
  return 0;
}


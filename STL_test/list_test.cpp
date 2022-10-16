//
// Created by pc on 2022/10/17.
// using c++ 11
// Double linked list structure
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <forward_list>//std::forward_list:Single linked list

int  main() {
  std::cout<<"start.\n";

  /* base */ {
    std::list<std::string> data_1;
    auto traversal_list = [&](){
      for (const std::string& e:data_1)
        std::cout<<e<<";";
      std::cout<<std::endl;
    };
    data_1.emplace_back("3");// -3-
    data_1.emplace_back("4");// -3-4-
    data_1.push_front("2");// -2-3-4-
    data_1.push_front("1");// -1-2-3-4-
    std::cout<<"-1-2-3-4-\t";traversal_list();
    data_1.pop_back();// -1-2-3-
    data_1.pop_back();// -1-2-
    std::cout<<"-1-2-\t";traversal_list();
    data_1.pop_front();// -2-
    std::cout<<"-2-\t";traversal_list();
    data_1.push_front("1");// -1-2-
    data_1.emplace_back("3");// -1-2-3-
    data_1.emplace_back("4");// -1-2-3-4-
    std::cout<<"-1-2-3-4-\t";traversal_list();

    std::string str_1 = std::move(data_1.front());// -?-2-3-4
    std::cout<<"-?-2-3-4\t";traversal_list();
    data_1.pop_front();// -2-3-4-
    std::cout<<"-2-3-4-\t";traversal_list();

    std::string str_4 = std::move(data_1.back());// -2-3-?-
    data_1.pop_back();// -2-3-
    std::cout<<"-2-3-\t";traversal_list();

  }

  std::cout<<"\nend.\n";
  return 0;
}

//
// Created by pc on 2022/10/16.
// using c++ 11
#include <stdio.h>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::cout<<"start.\n";

  /* simple get and set */ {
    std::tuple<int, std::string> data_1;
    data_1 = std::make_tuple(1, "java"); // set
    int id = std::get<0>(data_1);// get
    std::string str = std::get<1>(data_1); // get
    printf("id[%d];str[%s]\n",id,str.c_str());
  }
  /* sql example */ {
    // user: [id] [name] [password] [create_time]
    using id = unsigned int;
    using name = std::string;
    using password  = std::string;
    using create_time = std::string;
    using user_tuple = std::tuple<id, name, password, create_time>;
    std::vector<user_tuple> dataFromDB;
    // set data
    dataFromDB.emplace_back(1,
                            "shecannotsee",
                            "password",
                            "2022-10-17 00:06:23");
    dataFromDB.emplace_back(2,
                            "harry",
                            "123456",
                            "2022-10-17 00:06:88");
    // get data
    for (user_tuple& e: dataFromDB)
      printf("id[%d];name[%s];password[%s];create_time[%s]\n",
             std::get<0>(e),
             std::get<1>(e).c_str(),
             std::get<2>(e).c_str(),
             std::get<3>(e).c_str());

  }

  std::cout<<"end.\n";
  return 0;
}


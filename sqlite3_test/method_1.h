//
// Created by shecannotsee on 2022/9/30.
//

#ifndef LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_
#define LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_

#include <string>
#include <iostream>
#include <sqlite3.h>

void method_1() {
  /* Open database */
  sqlite3* db;
  if (sqlite3_open("", &db))
    std::cout<<"\n";

};


#endif //LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_

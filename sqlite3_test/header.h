//
// Created by shecannotsee on 2022/9/30.
//

#ifndef LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_
#define LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_

#include <string>
#include <iostream>
#include <sqlite3.h>

namespace method1 {

int sql_run_over_display(void *NotUsed, int argc, char **argv, char **azColName){
  std::cout<<"=============sql_run_over_display=============\n";
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  std::cout<<"=============sql_run_over_display=============\n";
  return 0;
};

void main() {
  sqlite3 *db;
  char* error = NULL;

  /* Open database,and get handle */
  if (sqlite3_open("../test.db", &db)) {
    std::cout << "open db failed, " << sqlite3_errmsg(db) << std::endl;
  } else {
    std::cout << "open db success\n";
  }

  /* run sql */
  std::string sql_insert = "INSERT INTO user (id,name,product_type,create_time,update_time) VALUES (2,'Carry','???','2022-10-31 15:59:00','2022-10-31 15:59:00');";
  std::string sql_select = "select * from user;";

  if (SQLITE_OK != sqlite3_exec(db,sql_select.c_str(),sql_run_over_display,NULL,&error)) {
    std::cout<<"sql failed : "<<error<<std::endl;
    sqlite3_free(error);
  }
  else {
    std::cout<<"sql exec success."<<std::endl;
  }

  /* close db handle */
  sqlite3_close(db);

};
};// namespace method1


#endif //LIBEVENT_TEST_TEST_SQLITE3_TEST_METHOD_1_H_

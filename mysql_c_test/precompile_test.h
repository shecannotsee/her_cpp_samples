//
// Created by shecannotsee on 2022/9/27.
//

/*
-- test_environment.test_user definition
CREATE TABLE `test_user` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `create_time` datetime NOT NULL,
  `update_time` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
 */

#ifndef MYSQL_C_TEST_TEST_MYSQL_C_TEST_PRECOMPILE_TEST_H_
#define MYSQL_C_TEST_TEST_MYSQL_C_TEST_PRECOMPILE_TEST_H_
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <memory>
#include <mysql.h>

void baseInit(MYSQL& mysql) {
  if(mysql_init(&mysql) == NULL) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
  if (NULL == mysql_real_connect(&mysql,"127.0.0.1",
                                 "root","123456",
                                 "test_environment",0,
                                 NULL,0)) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
}

void method_1() {
  MYSQL mysql;
  baseInit(mysql);

  // init,return MYSQL_STMT*
  MYSQL_STMT* handle = mysql_stmt_init(&mysql);
  if (handle == nullptr)
    std::cout<<"init failed.\n";
  else
    std::cout<<"init success.\n";

  // just exec sql
  std::string sql_1 = "select * from test_user";
  int res = mysql_stmt_prepare(handle, sql_1.c_str(), static_cast<unsigned long>(sql_1.size()));
  if (res != 0)
    std::cout<<"sql exec error.\n";
  else
    std::cout<<"sql exec success.\n";

  mysql_stmt_close(handle);
  mysql_close(&mysql);
};

//insert
void method_2() {
  MYSQL mysql;
  baseInit(mysql);

  /* init,return MYSQL_STMT* */
  MYSQL_STMT* handle = mysql_stmt_init(&mysql);
  if (handle == nullptr)
    std::cout<<"init failed.\n";
  else
    std::cout<<"init success.\n";

  /* bind sql template */
  std::string insert_sql = "insert into test_user (name,password,create_time,update_time) values (?,?,?,?)";
  if (mysql_stmt_prepare(handle, insert_sql.c_str(), insert_sql.size())!=0)
    std::cout<<"mysql_stmt_prepare() failed,the reason is ["
             <<mysql_stmt_error(handle)
             <<"]\n";
  else
    std::cout<<"mysql_stmt_prepare success.\n";

  MYSQL_BIND test_user_field[4];
  memset(test_user_field, 0, sizeof(test_user_field));// important
  std::string name = "zhangDong";
  std::string password = "ami520";
  std::string create_time = "2022-09-27 00:00:00";
  std::string update_time = "2022-09-27 00:00:00";
  char name_[1024];
  char password_[1024];
  char create_time_[1024];
  char update_time_[1024];
  bool can_set_null = false;
  test_user_field[0].buffer_type = MYSQL_TYPE_STRING;
  test_user_field[0].is_null = &can_set_null;
  test_user_field[0].buffer_length = name.size();
  test_user_field[0].buffer = name_;
  test_user_field[1].buffer_type = MYSQL_TYPE_STRING;
  test_user_field[1].is_null = &can_set_null;
  test_user_field[1].buffer_length = password.size();
  test_user_field[1].buffer = password_;
  test_user_field[2].buffer_type = MYSQL_TYPE_STRING;
  test_user_field[2].is_null = &can_set_null;
  test_user_field[2].buffer_length = create_time.size();
  test_user_field[2].buffer = create_time_;
  test_user_field[3].buffer_type = MYSQL_TYPE_STRING;
  test_user_field[3].is_null = &can_set_null;
  test_user_field[3].buffer_length = update_time.size();
  test_user_field[3].buffer = update_time_;

  if (mysql_stmt_bind_param(handle, test_user_field)!=0)
    std::cout<<"bind sql failed,the reason is ["
             <<mysql_stmt_error(handle)
             <<"]\n";
  else
    std::cout<<"bind sql success.\n";


  strncpy(name_,name.c_str(),name.size());
  strncpy(password_,password.c_str(),password.size());
  strncpy(create_time_,create_time.c_str(),create_time.size());
  strncpy(update_time_,update_time.c_str(),update_time.size());

  /* insert,update,delete */
  if (mysql_stmt_execute(handle) !=0)
    std::cout<<"sql exec failed,the reason is ["
             <<mysql_stmt_error(handle)
             <<"]\n";
  else
    std::cout<<"sql exec success.\n"
             // just get insert,update,delete's result
             <<mysql_stmt_affected_rows(handle)<<" pieces of data are changed.\n";;

  mysql_stmt_close(handle);
  mysql_close(&mysql);
};

// select
void method_3() {
  MYSQL mysql;
  baseInit(mysql);

  /* init,return MYSQL_STMT* */
  MYSQL_STMT* handle = mysql_stmt_init(&mysql);
  if (handle == nullptr)
    std::cout<<"init failed.\n";
  else
    std::cout<<"init success.\n";




  mysql_stmt_close(handle);
  mysql_close(&mysql);
};


#endif //MYSQL_C_TEST_TEST_MYSQL_C_TEST_PRECOMPILE_TEST_H_

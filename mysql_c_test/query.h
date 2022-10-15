//
// Created by shecannotsee on 2022/9/27.
//

#ifndef MYSQL_C_TEST_TEST_MYSQL_C_TEST_QUERY_H_
#define MYSQL_C_TEST_TEST_MYSQL_C_TEST_QUERY_H_

#include <mysql.h>
#include <vector>
#include <string>
#include <iostream>

namespace SQL {

std::vector<std::vector<std::string>> select(const std::string sql, MYSQL mysql) {
  std::vector<std::vector<std::string>> row_column;
  std::vector<std::string> row_insert;
  std::cout<<"sql is:["<<sql<<"]\n";
  if( mysql_real_query( &mysql, sql.c_str(), sql.size() ) !=0 ) {
    std::cout<<mysql_error(&mysql);
    return row_column;
  }
  MYSQL_RES* res = mysql_store_result( &mysql );
  MYSQL_ROW row;

  while( (row=mysql_fetch_row(res)) != nullptr ) {
    row_insert.clear();
    for( int i=0; i<2; i++ )
      row_insert.push_back(row[i]);
    row_column.push_back(row_insert);
  }
  return row_column;

};

};//namespace SQL

void program() {
  MYSQL mysql;
//初始化句柄mysql
  if(mysql_init(&mysql) == NULL) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
//初始化mysql数据库
  if (mysql_library_init(0, NULL, NULL) != 0) {
    fprintf(stderr, "could not initialize MySQL client library\n");
    exit(1);
  }
//与mysql服务器建立连接
//mysql表示一个现存mysql结构的地址，host表示MYSQL服务器的主机名或IP，
//user用户名，passwd登录的密码，
//db表示要连接的数据库，port表示MySQL服务器的TCP/IP端口
//unix_socket表示连接类型，client_flag表示MySQL运行ODBC数据库的标记
  if (NULL == mysql_real_connect(&mysql,"127.0.0.1",
                                 "root","123456",
                                 "test_enviroment",0,
                                 NULL,0)) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
//设置中文字符集
  if(mysql_set_character_set(&mysql, "utf8") != 0) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
  printf("connect success!\n");

  std::string sql = "select * from param_pool where _key = 'fds' ";
  auto rev = SQL::select(sql,mysql);
  if( rev.size()>0 ) {
    std::cout<<"数据条数为:["<<rev.size()<<"]\n";
    for( auto e : rev )
      std::cout<<"\123n";
  }
  else
    std::cout<<"没有查到对应数据\n";


/*********************************
//增删改
std::string sql = "oinsert into param_pool (_key,_value) values ('141133','ccc')";
// std::string sql = "update param_pool set _key = '1',_value = 'aaa'";
// std::string sql = "delete from param_pool where _key = '333'";
if(mysql_real_query( &mysql,sql.c_str(),sql.size() ) != 0 ) {
std::cout<<"Run sql:["
<<sql<<"]error,reason = "
<<mysql_error(&mysql)<<std::endl;
} else {
std::cout<<"Run sql:["
<<sql<<"]success."<<std::endl;
}

//查
std::string query = "select * from param_pool";
if(mysql_real_query( &mysql,query.c_str(),query.size() ) != 0 ) {
std::cout<<"Run sql:["
<<query<<"]error,reason = "
<<mysql_error(&mysql)<<std::endl;
} else {
std::cout<<"Run sql:["
<<query<<"]success."<<std::endl;
MYSQL_RES* res = mysql_store_result(&mysql);
MYSQL_ROW row;
std::vector<std::string> one_row;
while( (row=mysql_fetch_row(res)) != nullptr ) {
//row[0]表示查出来的第一个参数，[1]表示第二个
//std::cout<<row[0]<<","<<row[1]<<std::endl;
one_row.clear();
for( int i=0; i<2; i++){
one_row.push_back(row[i]);
std::cout<<one_row[i]<<"\t";
}
std::cout<<std::endl;
}
}
//中间部分为程序的主题部分
//
std::cout<<"result:["<<mysql_real_query( &mysql,query.c_str(),query.size() )<<"]"<<std::endl;
*/

  mysql_close(&mysql);
  mysql_library_end();
};

#endif //MYSQL_C_TEST_TEST_MYSQL_C_TEST_QUERY_H_

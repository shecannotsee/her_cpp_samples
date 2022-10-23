//
// Created by pc on 2022/10/23.
//

#ifndef BUFFER_DESIGN_TEST_MYSQL5_7_C_TEST_HEADER_H_
#define BUFFER_DESIGN_TEST_MYSQL5_7_C_TEST_HEADER_H_

#include <mysql.h>

namespace method1 {
void baseInit(MYSQL& mysql) {
  if(mysql_init(&mysql) == NULL) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
  if (NULL == mysql_real_connect(&mysql,"127.0.0.1",
                                 "root","",
                                 "test_environment",0,
                                 NULL,0)) {
    printf("%d : error : %s\n", __LINE__, mysql_error(&mysql));
    exit(1);
  }
}

void main() {
  MYSQL mysql;
  baseInit(mysql);
};
};//namespace method1

#endif //BUFFER_DESIGN_TEST_MYSQL5_7_C_TEST_HEADER_H_

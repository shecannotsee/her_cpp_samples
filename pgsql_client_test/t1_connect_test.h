//
// Created by shecannotsee on 23-10-9.
//

#ifndef PGSQL_CLIENT_TEST_T1_CONNECT_TEST_H
#define PGSQL_CLIENT_TEST_T1_CONNECT_TEST_H

#include <libpq-fe.h>
#include <iostream>
#include <netinet/in.h>

namespace t1_connect_test {

static void exit_nicely(PGconn *conn) {
  PQfinish(conn);
  exit(1);
}

void main() {
  // create db name
  std::string db_name = "main_db";
  std::string conninfo = "dbname = " + db_name;
  // make connect
  PGconn* conn = PQconnectdb(conninfo.c_str());/* check connect */ {
    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK) {
      std::cout << "\033[31m" << "connect failed:" << PQerrorMessage(conn) << "\033[0m" << std::endl;
      exit_nicely(conn);
    } else {
      std::cout << "\033[32m" << "connect success" << "\033[0m" << std::endl;
    }
  }

  PGresult* res = nullptr;
  /* 设置始终安全的搜索路径，这样恶意用户就无法控制 */
  res = PQexec(conn,"SET search_path = private");/* check set */ {
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
      std::cout << "\033[31m" << "SET failed:" << PQerrorMessage(conn) << "\033[0m" << std::endl;
      PQclear(res);
      exit_nicely(conn);
    } else {
      std::cout << "\033[32m" << "set safe search path success" << "\033[0m" << std::endl;
    }
    /* clear res to avoid memory leaks */
    PQclear(res);
  }

//  /* Start a transaction block */
//  res = PQexec(conn, "BEGIN");/* check */ {
//    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
//      std::cout << "\033[31m" << "BEGIN command failed:" << PQerrorMessage(conn) << "\033[0m" << std::endl;
//      PQclear(res);
//      exit_nicely(conn);
//    }
//    PQclear(res);
//  }

  /* Fetch rows from pg_database, the system catalog of databases */
  res = PQexec(conn, "select * from private.book");/* check success */ {
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
      fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
    PQclear(res);
  }

//  res = PQexec(conn, "FETCH ALL in myportal");/* check success */ {
//    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
//      fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
//      PQclear(res);
//      exit_nicely(conn);
//    }
//    PQclear(res);
//  }

  /* 打印属性行 */
  int nFields = PQnfields(res);
  for (int i = 0; i < nFields; i++) {
//    std::cout << PQfname(res, i) << std::endl;
    printf("%-15s", PQfname(res, i));
  }
  printf("\n\n");

  /* output row data */
  for (int i = 0; i < PQntuples(res); i++) {
    for (int j = 0; j < nFields; j++) {
//      std::cout << PQgetvalue(res, i, j) << std::endl;
      printf("%-15s", PQgetvalue(res, i, j));
    }
    printf("\n");
  }

  /* close the portal ... we don't bother to check for errors ... */
  res = PQexec(conn, "CLOSE myportal");
  PQclear(res);

  /* end the transaction */
  res = PQexec(conn, "END;");
  PQclear(res);

  /* close the connection to the database and cleanup */
  PQfinish(conn);
}


}// namespace t1_connect_test

#endif //PGSQL_CLIENT_TEST_T1_CONNECT_TEST_H

//
// Created by shecannotsee on 23-10-8.
//

#include "login.h"
#include <string>
#include <iostream>

namespace t3_login_test {

login::login(QObject *parent) : QObject(parent) {

}

void login::validateLogin(const QString &username, const QString &password) {
  this->validateLogin(username.toStdString(),password.toStdString());
}

void login::validateLogin(const std::string &username, const std::string &password) {
  if (username == "admin" && password == "123456") {
    std::cout << "pass" <<std::endl;
  } else {
    std::cout << "not pass" <<std::endl;
  }
}

} // t3_login_test
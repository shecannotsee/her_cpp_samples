//
// Created by shecannotsee on 23-10-8.
//

#include "login.h"
#include <string>
#include <iostream>

namespace t3_login_test {

login::login(QObject *parent) : QObject(parent) {

}

bool login::validateLogin(const QString &username, const QString &password) {
  return this->validateLogin(username.toStdString(),password.toStdString());
}

bool login::validateLogin(const std::string &username, const std::string &password) {
  if (username == "admin" && password == "123456") {
    std::cout << "pass" <<std::endl;
    return true;
  } else {
    std::cout << "not pass" <<std::endl;
    return false;
  }
}

} // t3_login_test
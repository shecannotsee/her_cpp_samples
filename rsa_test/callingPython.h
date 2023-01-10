//
// Created by  shecannotsee on 2023/1/10.
//

#ifndef RSA_TEST_CALLINGPYTHON_H
#define RSA_TEST_CALLINGPYTHON_H

#include <cstdio>
#include <string>
#include <iostream>

std::string cal(int arg_1,int arg_2,int prime_product) {
  using std::to_string;
  std::string cmd =
          "python3 ../rsa_bigNumber_cal.py "
          + to_string(arg_1) + " "
          + to_string(arg_2) + " "
          + to_string(prime_product);
  FILE* pipe = popen(cmd.c_str(), "r");
  if (!pipe) {
    std::cout << "Error: popen()" << std::endl;
    exit(1);
  }
  char buffer[256];
  while(fgets(buffer, sizeof(buffer), pipe) != NULL) {
    //std::cout << buffer;
  }
  pclose(pipe);
  std::cout << "buffer:" <<buffer<<std::endl;
  std::cout<<"len:"<<strlen(buffer)<<std::endl;
  return std::string(buffer,strlen(buffer));
};


#endif //RSA_TEST_CALLINGPYTHON_H

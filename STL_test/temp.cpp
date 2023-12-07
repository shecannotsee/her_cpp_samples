//
// Created by shecannotsee on 2023/3/2.
//
#include <stdio.h>
#include <string.h>
#include <iostream>

int main() {
  char s[] = {'1','2','3','0','0','4','5'};
  std::cout<<strlen(s)<<"\n";
  printf("[%s]\n",s);
  std::cout << "#[" << __TIME__<< "]\n";
  std::cout << "#[" << __TIMESTAMP__ << "]\n";
  std::cout << "#[" << __func__ << "]\n";
  std::cout << "#[" << __FUNCTION__ << "]\n";
  std::cout << "#[" << __LINE__ << "]\n";

  std::cout<<s;
  std::cout<<"|||\n";
  return 0;
};

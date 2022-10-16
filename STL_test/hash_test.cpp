//
// Created by pc on 2022/10/16.
// hash_test using c++11 standard
//
#include <iostream>
#include <string>// hash


int main() {
  std::cout<<"start.\n";

  /* Simple usage */ {
    std::string str = "hello world";
    std::hash<std::string> myStringHash;
    size_t stringHashVal = myStringHash(str);
    std::cout << "std::string hash val : " << stringHashVal << std::endl;

    const char* a = "hello world";
    std::hash<const char*> myCharHash;
    size_t intHashVal = myCharHash(a);
    std::cout << "char* hash val : " << intHashVal <<std::endl;
  };

  /* define user's hash */ {

  };


  std::cout<<"end.\n";
  return 0;
}

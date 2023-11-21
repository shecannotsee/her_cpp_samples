//
// Created by shecannotsee on 23-11-21.
//
#include <iostream>
#include <string>
#include <sstream>

int main() {
  // 输入的字符串
  std::string inputString = "aaaaaaaaaa;bbbbbbbbbbb;cccccccccccc";

  // 使用 std::istringstream 进行字符串分隔
  std::istringstream iss(inputString);
  std::string token;

  // 使用 getline 和分号作为分隔符逐个提取数据
  std::getline(iss, token, ';');
  std::string part1 = token;

  std::getline(iss, token, ';');
  std::string part2 = token;

  std::getline(iss, token, ';');
  std::string part3 = token;

  // 打印提取的数据
  std::cout << "Part 1: " << part1 << std::endl;
  std::cout << "Part 2: " << part2 << std::endl;
  std::cout << "Part 3: " << part3 << std::endl;

  return 0;
}

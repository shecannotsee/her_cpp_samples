//
// Created by shecannotsee on 2023/3/13.
//
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::priority_queue<int,std::vector<int>> temp;
  auto traversal_priority_queue = [&](){
    std::priority_queue<int,std::vector<int>> temp_copy = temp;
    while (!temp_copy.empty()) {
      int current = temp_copy.top();
      // 处理 current
      temp_copy.pop();
      std::cout << current << ",";
    }
    std::cout << std::endl;
  };
  temp.push(1);
  temp.push(10);
  temp.push(5);
  traversal_priority_queue();
  temp.pop();
  traversal_priority_queue();
  auto a = temp.top();
  std::cout << "auto a = temp.top(); a:" <<a << std::endl;
  traversal_priority_queue();

  return 0;
};


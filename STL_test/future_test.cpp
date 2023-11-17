//
// Created by shecannotsee on 23-11-15.
//
#include <iostream>
#include <thread>
#include <future>
#include <unistd.h>

int main() {
  // 创建 std::promise 对象，用于在一个线程中设置共享状态的值
  std::promise<bool> resultPromise;
  // 获取与 promise 关联的 std::future 对象
  std::future<bool> resultFuture = resultPromise.get_future();
  // 启动一个新线程，执行计算并设置 promise 共享状态的值
  std::thread myThread([=, &resultPromise]() {
    bool result = [](){
      for (int i = 0; i < 10; ++i) {
        sleep(1);
      }
      return true;
    }();
    // 设置 promise 共享状态的值
    resultPromise.set_value(result);
  });

  int result = resultFuture.get();
  while (1) {
    std::cout << "not done" << result << std::endl;
    sleep(1);
  }


  std::cout << "done." << std::endl;
  return 0;
}
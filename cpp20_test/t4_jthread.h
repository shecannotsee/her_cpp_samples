#ifndef T4_THREAD_STOP_H
#define T4_THREAD_STOP_H

#include <functional>
#include <iostream>
#include <thread>

namespace t4_jthread {

inline void run() {
  std::cout << "t4_thread_stop start--------------------------------------------------------------------------------\n";

  // destructor join test
  std::cout << "destructor join test...................................\n";
  {
    std::jthread auto_join_thread([]() {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "auto_join_thread done(in ~jthread())\n";
    });
  }
  // use std::stop_token to stop jthread
  std::cout << "use std::stop_token...................................\n";
  {
    std::jthread auto_join_thread(
        [](const std::stop_token& stop_token, int value) {
          // 用于外界传递结束信号来结束线程
          while (!stop_token.stop_requested()) {
            std::cout << value++ << "-loop\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
          }
        },
        /* 不用传stop_token参数的原因是在创建jthread的时候会自动给他创建一个stop_token */ 10);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto_join_thread.request_stop();
    std::cout << "stop jthread\n";
  }
  // use std::stop_source
  std::cout << "use std::stop_source...................................\n";
  {
    std::stop_source source;
    /* 这里是thread */
    std::thread th(
        [token = source.get_token()](int value) {
          while (!token.stop_requested()) {
            std::cout << value++ << "-loop\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
          }
        },
        10);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto request_stop_ret = source.request_stop();
    std::cout << "request_stop_ret:" << (request_stop_ret ? std::string("true") : std::string("false")) << std::endl;
    th.join();
  }
  // use std::stop_callback
  std::cout << "use std::stop_callback................................\n";
  {
    std::jthread auto_join_thread(
        [](const std::stop_token& stop_token, int value) {
          std::stop_callback callback(stop_token,
                                      []() { std::cout << "Stop request received. Executing callback...\n"; });
          // 用于外界传递结束信号来结束线程
          while (!stop_token.stop_requested()) {
            std::cout << value++ << "-loop\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
          }
          std::cout << "jump loop\n";
        },
        /* 不用传stop_token参数的原因是在创建jthread的时候会自动给他创建一个stop_token */ 10);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto_join_thread.request_stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "stop jthread\n";
  }

  std::cout << "t4_thread_stop done\n";
}

}  // namespace t4_jthread

#endif  // T4_THREAD_STOP_H

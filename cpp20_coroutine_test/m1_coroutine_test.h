//
// Created by shecannotsee on 2023/3/21.
//

#ifndef CPP_20_TEST__M1_COROUTINE_TEST_H_
#define CPP_20_TEST__M1_COROUTINE_TEST_H_

#include <coroutine>
#include <iostream>
#include <stdexcept>
#include <thread>

namespace m1_coroutine_test {

auto switch_to_new_thread(std::jthread& out) {
  struct awaitable {
    std::jthread* p_out;
    bool await_ready() {
      return false;
    };

    void await_suspend(std::coroutine_handle<> h) {
      std::jthread& out = *p_out;
      if (out.joinable())
        throw std::runtime_error("jthread 输出参数非空");
      out = std::jthread([h] { h.resume(); });
      // 潜在的未定义行为：访问潜在被销毁的 *this
      // std::cout << "新线程 ID：" << p_out->get_id() << '\n';
      std::cout << "新线程 ID：" << out.get_id() << '\n'; // 这样没问题
    };

    void await_resume() {}
  };// struct awaitable

  return awaitable{&out};
}

struct task {
  struct promise_type {
    task get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
  };// struct promise_type
};// struct task

task resuming_on_new_thread(std::jthread& out) {
  std::cout << "协程开始，线程 ID：" << std::this_thread::get_id() << '\n';
  co_await switch_to_new_thread(out);
  // 等待器在此销毁
  std::cout << "协程恢复，线程 ID：" << std::this_thread::get_id() << '\n';
}

int main() {
  std::jthread out;
  resuming_on_new_thread(out);
}

};// namespace m1_coroutine_test {

#endif //CPP_20_TEST__M1_COROUTINE_TEST_H_

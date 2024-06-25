//
// Created by shecannotsee on 24-6-25.
//

#ifndef T3_SAMPLE_H
#define T3_SAMPLE_H

#include <coroutine>
#include <iostream>

namespace t3_sample {

/**
 *  返回 std::suspend_never 表示不挂起,协程函数继续执行
 *  返回 std::suspend_always 表示将当前函数,也就是保存帧并且返回,并且将控制权交给调用方
 */

// The caller-level type
struct frame {
  // The coroutine level type
  struct promise_type {
    frame get_return_object() {
      return frame{std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() {
      // return std::suspend_always -> break up
      return {};
    }

    void return_void() {
    }
    std::suspend_never final_suspend() noexcept {
      return {};
    }
    void unhandled_exception() {
      // 程序中止
      std::terminate();
    }
  };

  explicit frame(std::coroutine_handle<promise_type> coro) : coro_(coro) {
  }
  void destroy() {
    printf("frame::destory\n");
    coro_.destroy();
  }
  void resume() {
    printf("frame::resume\n");
    coro_.resume();
  }
  bool exec() {
    coro_.resume();
    return coro_.done();
  }

 private:
  std::coroutine_handle<promise_type> coro_;
};

// 协程函数
frame my_coroutine() {
  printf("start co_return\n");
  for (int i = 0; true; i++) {
    std::cout << i << "\n";
    co_await std::suspend_always{};
  }
}

inline void run() {
  std::cout << "t3_sample start-------------------------------------------------------------------------------------\n";

  frame coro_1 = my_coroutine();
  frame coro_2 = my_coroutine();

  coro_1.resume();
  coro_2.resume();

  coro_1.resume();
  coro_2.resume();

  coro_1.resume();
  coro_2.resume();

  coro_1.destroy();
  coro_2.destroy();
  std::cout << "t3_sample done\n";
}
}  // namespace t3_sample

#endif  // T3_SAMPLE_H

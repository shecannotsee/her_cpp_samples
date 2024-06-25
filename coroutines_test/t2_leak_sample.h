//
// Created by shecannotsee on 24-6-25.
//

#ifndef T2_LEAK_SAMPLE_H
#define T2_LEAK_SAMPLE_H

namespace t2_leak_sample {

struct simple_awaiter {
  constexpr bool await_ready() const noexcept {
    printf("----simple_awaiter::await_ready\n");
    return false;
  }

  constexpr void await_suspend(std::coroutine_handle<>) const noexcept {
    printf("----simple_awaiter::await_suspend\n");
  }

  constexpr void await_resume() const noexcept {
    printf("----simple_awaiter::await_resume\n");
  }
};

// The caller-level type
struct frame {
  // 固定名称
  struct promise_type {
    // 固定名称:step1
    static frame get_return_object() {
      printf("--get_return_object\n");
      return {};
    }
    // 固定名称:step2
    static simple_awaiter initial_suspend() {
      printf("--initial_suspend\n");
      return {};
    }
    // function start......
    // ......

    // 固定名称,在co_return后调用step1
    static void return_void() {
      printf("--return_void\n");
    }

    // 固定名称,在co_return后调用step2
    static simple_awaiter final_suspend() noexcept {
      printf("--final_suspend\n");
      return {};
    }
    // 固定名称
    static void unhandled_exception() {
      printf("--unhandled_exception\n");
    }
  };

  frame() {
    printf("[frame]\n");
  }

  ~frame() {
    printf("[~frame]\n");
  }
};

// 协程函数
frame my_coroutine() {
  printf("start co_return\n");
  co_return;  // make it a coroutine
}

inline void run() {
  printf("t2_leak_sample start-------------------------------------------------------------------------------\n");
  frame x = my_coroutine();
  printf("t2_leak_sample done\n");
}

}// namespace t2_leak_sample

#endif //T2_LEAK_SAMPLE_H

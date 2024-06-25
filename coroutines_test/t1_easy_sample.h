#ifndef EASY_SAMPLE_H
#define EASY_SAMPLE_H

#include <coroutine>

namespace t1_easy_sample {

struct simple_awaiter {
  constexpr bool await_ready() const noexcept {
    printf("----simple_awaiter::await_ready\n");
    return true;
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
  printf("t1_easy_sample start-------------------------------------------------------------------------------\n");
  frame x = my_coroutine();
  printf("t1_easy_sample done\n");
}

}  // namespace t1_easy_sample

#endif  // EASY_SAMPLE_H

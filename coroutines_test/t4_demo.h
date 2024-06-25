//
// Created by shecannotsee on 24-6-25.
//

#ifndef T4_DEMO_H
#define T4_DEMO_H

#include <coroutine>
#include <iostream>

namespace t4_demo {

template <typename T>
class coro_package {
 public:
  class promise_type;

  explicit coro_package(std::coroutine_handle<promise_type> handle) : coroutine_handle_(handle) {
  }
  ~coro_package() {
    if (coroutine_handle_) {
      coroutine_handle_.destroy();
    }
  }

  /**
   * @brief 该接口获取协程恢复并且运行的结果
   * @return true:协程恢复并且运行成功; false:协程恢复运行失败
   */
  bool resume() {
    if (coroutine_handle_.done()) {  // 当协程到达结束点或被显式销毁时, done方法会返回 true, 表示已经结束了
      return false;
    }
    coroutine_handle_.resume();  // 1:与2等价
    // coroutine_handle_();// 2:与1等价

    return true;
  }

  /**
   * @brief 该接口获取携程的值
   * @return 返回值
   */
  T get_value() const {
    return coroutine_handle_.promise().value_;
  }

 private:
  std::coroutine_handle<promise_type> coroutine_handle_;

 public:
  class promise_type {
   public:
    T value_{};  // 值保存在promise_type中

    coro_package<T> get_return_object() {
      return coro_package<T>{std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    auto initial_suspend() {
      return std::suspend_always{};  // 初始化的时候总是挂起
    }
    // 结束的时候不挂起
    auto final_suspend() noexcept {
      printf("final\n");
      return std::suspend_always{};
    }
    // 处理协程中的异常
    void unhandled_exception() {
      // 程序中止
      std::terminate();
    }

    // co_yield的时候触发
    // 定制:赋值,然后让协程挂起,执行控制回到调用者
    std::suspend_always yield_value(T value) {
      value_ = value;
      return {};
    };
    // co_return的时候触发,与return_void之间只能声明一个
    void return_value(T value) {
      value_ = value;
    };
    // void return_void() {
    // };
  };
};

template <typename T>
coro_package<T> function() {
  co_await std::suspend_always{};  // 挂起
  co_yield __LINE__;
  co_yield __LINE__;
  co_return __LINE__;
}

inline void run() {
  std::cout << "t4_demo start---------------------------------------------------------------------------------------\n";
  bool ret = false;

  auto coro_frame = function<int>();
  std::cout << coro_frame.get_value() << std::endl;  // 初始挂起
  ret = coro_frame.resume();
  std::cout << coro_frame.get_value() << std::endl;  // function的co_await挂起

  ret = coro_frame.resume();
  std::cout << coro_frame.get_value() << std::endl;  // 第一次co_yield

  ret = coro_frame.resume();
  std::cout << coro_frame.get_value() << std::endl;  // 第二次co_yield

  ret = coro_frame.resume();
  std::cout << coro_frame.get_value() << std::endl;  // co_return

  ret = coro_frame.resume();
  std::cout <<coro_frame.get_value() << std::endl;// out of range

  std::cout << "t4_demo done\n";
}

}  // namespace t4_demo

#endif  // T4_DEMO_H

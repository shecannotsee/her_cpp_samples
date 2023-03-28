//
// Created by shecannotsee on 2023/3/21.
//

#ifndef CPP_20_TEST__M1_DOCS_TEST_H_
#define CPP_20_TEST__M1_DOCS_TEST_H_

#include <iostream>
#include <coroutine>

namespace m2_docs_test {

// auto result = co_await 表达式
// ============================等价于
// auto&& __a = 表达式;
// if (!__a.await_ready()) {//
//  __a.await_suspend(协程句柄);
//   // 挂起/恢复点
// }
// auto result = __a.await_resume();

// ci_yield 表达式
// ====================================等价于
// co_await promise.yield_value(表达式);

// 永远需要挂起
struct suspend_always{
  // 是否挂起
  // return true  直接调用await_resume()进行返回
  // return false 执行await_suspend()之后挂起,然后等待恢复,最后调用await_resume()返回结果
  bool await_ready() const noexcept {
    std::cout << "suspend_always::await_ready().\n";
    return false;
  };

  //
  void await_suspend(std::coroutine_handle<>) noexcept {
    std::cout << "suspend_always::await_suspend().\n";
  };

  //
  void await_resume() const noexcept{
    std::cout << "suspend_always::await_resume().\n";
  };
};

// 永远不需要挂起
struct suspend_never {
  bool await_ready() const noexcept {
    std::cout << "suspend_never::await_ready().\n";
    return true;
  }
  void await_suspend(std::coroutine_handle<>) noexcept {
    std::cout << "suspend_never::await_suspend().\n";

  };
  void await_resume() const noexcept {
    std::cout << "suspend_never::await_resume().\n";
  };
};

template <typename T>
class coro_ret {
 public:
  struct promise_type;
  using coro_handle = std::coroutine_handle<promise_type>;
 public:
  explicit coro_ret(coro_handle handle) : handle_(handle) {
  };
  coro_ret(const coro_ret&) = delete;
  coro_ret(coro_ret&&) = delete;

  ~coro_ret() {
    if (handle_) {
      handle_.destroy();
    }
  };

 private:
  coro_handle handle_;

 public:

  // 恢复协程，返回是否结束
  bool move_next() {
    handle_.resume();
    return handle_.done();
  };

  T get(){
    return handle_.promise().value_;
  };

 public:
  struct promise_type {
    T value_;

    // 定制:调用协程的返回值
    auto get_return_object() -> coro_ret<T> {
      std::cout << "promise_type::get_return_object().\n";
      return coro_ret<T>{coro_handle::from_promise(*this)};
    };

    // 协程函数将返回值对象传给调⽤者之前执⾏,也就是新协程被创建之后，是⽴刻挂起还是不挂起
    // 定制:使得协程立刻挂起,调用者马山得到get_return_object()的结果
    auto initial_suspend() {
      std::cout << "promise_type::initial_suspend().\n";
      return suspend_always{};
    };

    // 协程函数结束后，调⽤这个，让⽤户释放资源
    // 执行到co_return语句，协程仍处于挂起状态
    auto final_suspend() noexcept {
      std::cout << "promise_type::final_suspend().\n";
      return suspend_always{};
    };

    // co_yield的时候触发
    // 定制:赋值,然后让协程挂起,执行控制回到调用者
    auto yield_value(T value) {
      std::cout << "promise_type::yield_value().\n";
      value_ = value;
      return suspend_always{};
    };

    // co_return的时候触发
    // 定制:永不返回
    void return_value(T value) {
      value_ = value;
      std::cout << "promise_type::return_void().\n";
      return;
    };

    // 协程抛异常，会传递到这
    // 定制:异常处理
    void unhandled_exception() {
      std::cout << "promise_type::unhandled_exception().\n";
      std::terminate();
    };

  };


};// class

coro_ret<int> test() {
  std::cout << "Coroutine co_await std::suspend_never" << std::endl;
  //co_await std::suspend_never{} 不会挂起
  co_await std::suspend_never{};
  std::cout << "Coroutine co_await std::suspend_always" << std::endl;
  co_await std::suspend_always{};

  std::cout << "Coroutine stage 1 ,co_yield" << std::endl;
  co_yield 101;
  std::cout << "Coroutine stage 2 ,co_yield" << std::endl;
  co_yield 202;
  std::cout << "Coroutine stage 3 ,co_yield" << std::endl;
  co_yield 303;
  std::cout << "Coroutine stage end, co_return" << std::endl;
  co_return 808;
};

int main() {
  bool done = false;
  std::cout << "Start coroutine_7in7out ()\n";
  //调用协程,得到返回值c_r，后面使用这个返回值来管理协程。
  auto c_r = test();
  //第一次停止因为initial_suspend 返回的是suspend_always
  //此时没有进入Stage 1
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ") << "ret =" << c_r.get() << std::endl;
  done = c_r.move_next();
  //此时是，co_await std::suspend_always{}
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ")<< "ret =" << c_r.get() << std::endl;
  done = c_r.move_next();
  //此时打印Stage 1
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ")<< "ret =" << c_r.get() << std::endl;
  done = c_r.move_next();
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ")<< "ret =" << c_r.get() << std::endl;
  done = c_r.move_next();
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ")<< "ret =" << c_r.get() << std::endl;
  done = c_r.move_next();
  std::cout << "Coroutine " << (done ? "is done " : "isn't done ")<< "ret =" << c_r.get() << std::endl;

  return 0;
};

};// namespace m1_docs_test

#endif //CPP_20_TEST__M1_DOCS_TEST_H_

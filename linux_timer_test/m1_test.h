//
// Created by shecannotsee on 23-5-12.
//

#ifndef ASIO_TEST_LINUX_TIMER_TEST_M1_TEST_H_
#define ASIO_TEST_LINUX_TIMER_TEST_M1_TEST_H_

#include <sys/timerfd.h>
#include <unistd.h>
#include <chrono>
#include <functional>
#include <thread>

namespace m1_test {

class Timer {
  using TimerCallback = std::function<void()>;
 private:
  int fd_ = -1;
  TimerCallback callback_;
  std::thread thread_;

 public:
  Timer() {
    /**
     *  @brief timerfd_create
     *  @param clock_id CLOCK_REALTIME (使用系统实时时钟，该时钟会受到系统时间变化的影响)
     *                  CLOCK_MONOTONIC (使用系统单调时钟，该时钟不受系统时间变化的影响)
     *  @param flags
     *  @return 返回一个整数值，表示定时器描述符。如果返回值为-1，
     */
    fd_ = timerfd_create(CLOCK_MONOTONIC, 0);
  };

  ~Timer() {
    if (fd_ != -1) {
      close(fd_);
    }
  };

  void start(int interval, const TimerCallback& callback) {
    struct itimerspec new_timer{};/* init */ {
      // 定时器的间隔值
      new_timer.it_interval.tv_sec = interval / 1000;
      new_timer.it_interval.tv_nsec = (interval % 1000) * 1000000;
      // 定时器的初始值
      new_timer.it_value.tv_sec = interval / 1000;
      new_timer.it_value.tv_nsec = (interval % 1000) * 1000000;
    }
    /**
     *  @param ufd   定时器描述符
     *  @param flags 用于指定操作的选项。对于TFD_TIMER_ABSTIME:
     *                  表示new_value指定的超时时间为绝对时间（从1970年1月1日开始算起的秒数）,
     *                  否则new_value指定的超时时间为相对时间（从当前时间开始算起的秒数）。
     *  @param utmr  用于指定新的超时时间和超时次数
     *  @param otmr  用于返回之前的超时时间和超时次数。如果不需要这个返回值，可以传入NULL
     */
    timerfd_settime(fd_, 0, &new_timer, nullptr);
    // 设置回调
    callback_ = callback;
    thread_ = std::thread(&Timer::run, this);
  }

  void stop() {
    thread_.join();
  }

 private:
  void run() {
    while (true) {
      uint64_t exp;
      /**
       *    @param fd       文件描述符
       *    @param buf      读取数据的缓冲区
       *    @param nbytes   要读取的字节数
       *    @return
       */
      ssize_t n = read(fd_, &exp, sizeof(exp));
      if (n != sizeof(exp)) {
        break;
      }

      if (callback_) {
        callback_();
      }
    }// while true
  };

};

void main() {
  Timer timer;
  timer.start(1000, []() {
    std::cout << "Timer expired1\n";
  });
  std::this_thread::sleep_for(std::chrono::seconds(5));
  timer.stop();

};

};// namespace m1_test

#endif //ASIO_TEST_LINUX_TIMER_TEST_M1_TEST_H_

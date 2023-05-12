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
    fd_ = timerfd_create(CLOCK_MONOTONIC, 0);
  };

  ~Timer() {
    if (fd_ != -1) {
      close(fd_);
    }
  };

  void start(int interval, const TimerCallback& callback) {
    struct itimerspec new_timer{};
    new_timer.it_interval.tv_sec = interval / 1000;
    new_timer.it_interval.tv_nsec = (interval % 1000) * 1000000;
    new_timer.it_value.tv_sec = interval / 1000;
    new_timer.it_value.tv_nsec = (interval % 1000) * 1000000;

    timerfd_settime(fd_, 0, &new_timer, nullptr);
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
    std::cout << "Timer expired\n";
  });
  std::this_thread::sleep_for(std::chrono::seconds(5));
  timer.stop();

};

};// namespace m1_test

#endif //ASIO_TEST_LINUX_TIMER_TEST_M1_TEST_H_

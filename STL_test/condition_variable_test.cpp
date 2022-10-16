//
// Created by pc on 2022/10/17.
//
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

int main() {
  std::cout<<"start.\n";

  /* base */ {
    std::condition_variable cv;
    //std::mutex mx;//one by one
    auto work = [&](){
      std::mutex mx;
      std::unique_lock<std::mutex> lock(mx);
      std::cout<<"waiting...\n";
      cv.wait(lock);
      std::cout<<time(nullptr)<<"\twork.\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
    };

    auto leader = [&](){
      std::this_thread::sleep_for(std::chrono::seconds(3));
      cv.notify_all();
    };

    std::thread t1(work),t2(work),t3(work);//,t4(leader);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"not\n";
    cv.notify_all();

    t1.join();t2.join();
    t3.join();//t4.join();
  }

  std::cout<<"end.\n";
  return 0;
}

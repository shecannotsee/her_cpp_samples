//
// Created by shecannotsee on 23-11-30.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

int main() {
  std::cout << "Start.\n";
  /*  */ {
    std::mutex mtx;

    std::thread try_async_thread([&]() {
       if (mtx.try_lock()) {
         std::cout << "try_lock11111111111111:try_async_thread\n";
         sleep(5);
         std::cout << "free\n";
         sleep(1);
         mtx.unlock();
       } else {
         std::cout << "try_lock failed2222222:try_async_thread\n";
       }
    });
    sleep(1);
    std::thread block_thread([&]() {
        mtx.lock();
        std::cout << "block_thread\n";
        // sleep(10);
        mtx.unlock();
    });
    try_async_thread.join();
    block_thread.join();
  }


  std::cout << "Done.\n";
  return 0;
}

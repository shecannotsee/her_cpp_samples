//
// Created by shecannotsee on 24-6-26.
//

#ifndef T5_CHRONO_H
#define T5_CHRONO_H

#include <iostream>
#include <chrono>
#include <iomanip>

namespace t5_chrono {

inline void run() {
  std::cout << "t5_choro start--------------------------------------------------------------------------------------\n";

  {
    using namespace std::chrono;

    // 获取当前时间（UTC）
    auto now = system_clock::now();

    // gcc11.4尚未支持
    // // 转换为系统时间
    // auto current_time = zoned_time{current_zone(), now};
    //
    // // 输出当前时间（带时区信息）
    // std::cout << "Current time (local time zone): " << current_time << '\n';
    //
    // // 转换为纽约时间
    // auto ny_time = zoned_time{"America/New_York", now};
    // std::cout << "Current time (New York time zone): " << ny_time << '\n';
    //
    // // 转换为东京时间
    // auto tokyo_time = zoned_time{"Asia/Tokyo", now};
    // std::cout << "Current time (Tokyo time zone): " << tokyo_time << '\n';
  }

  std::cout << "t5_choro done\n";
}

}  // namespace t5_chrono

#endif  // T5_CHRONO_H

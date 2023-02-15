//
// Created by shecannotsee on 2023/2/14.
//

#ifndef MQTT_LIB_TEST_COMMON_ALGORITHM_SNOWFLAKE_ALGORITHM_HPP_
#define MQTT_LIB_TEST_COMMON_ALGORITHM_SNOWFLAKE_ALGORITHM_HPP_

#include <chrono>

/* get_milliseconds_from_specific_time */
uint64_t get_milliseconds_from_specific_time(int year,int month,int day,int hour,int minute,int second) {
  year  = year-1900; // std::chrono default set
  month = month-1;   // std::chrono default set
  tm tm_target = {second, minute, hour, day, month, year};
  auto target = std::chrono::system_clock::from_time_t(std::mktime(&tm_target));
  auto now = std::chrono::system_clock::now();
  if (now<=target) {
    throw std::invalid_argument("[The input time is greater than the current time]");
  }
  auto duration = now - target;
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  std::cout<< "2023-02-14 10:32:00 to now (ms) :" << milliseconds <<std::endl;
  return milliseconds;
};

namespace test {

void main() {
  uint64_t id = 0;
  uint64_t tt = 0;
  /* 63 (1 bits): 符号位 */ {
    tt = 0;
    tt = 1; // 1
    tt = tt << 63;
    id += tt;
  };

  /* 62-22 (41 bits): 时间戳*/ {
    tt = 0;
    tt = get_milliseconds_from_specific_time(2023,2,15,15,05,0);
    tt = 1;
    tt = tt << 22;
    id += tt;
  };

  /* 21-12 (10 bits): 机器序号*/ {
    tt = 0;
    tt = 1; // 1
    tt = tt <<12;
    id += tt;
  };

  /* 11-0 (12 bits): 本机序列号 */ {
    tt = 0;
    tt = 1; // 1
    tt = tt << 0;
    id += tt;
  };


  std::cout<< "id :[" << id  <<"]\n";

};

};// namespace test



#endif //MQTT_LIB_TEST_COMMON_ALGORITHM_SNOWFLAKE_ALGORITHM_HPP_

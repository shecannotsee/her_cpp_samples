//
// Created by shecannotsee on 2023/2/15.
//

#ifndef COMMON_ALGORITHM_TEST_COMMON_ALGORITHM_SNOWFLAKE_HPP_
#define COMMON_ALGORITHM_TEST_COMMON_ALGORITHM_SNOWFLAKE_HPP_

#include <chrono>
#include <stdexcept>

/* get_milliseconds_from_specific_time */
uint64_t get_milliseconds_from_specific_time(int year=1999,int month=10,int day=24,int hour=0,int minute=0,int second=0) {
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
  return milliseconds;
};

uint64_t snowflake(int machine_id = 1,int serial_number = 1) {
  uint64_t id = 0;
  uint64_t temp = 0;
  temp = 1; // easy to debug
  id += (temp<<63);
  temp = get_milliseconds_from_specific_time();
  id += (temp<<22);
  temp = machine_id;
  id += (temp<<12);
  id += serial_number;
  return id;
};

#endif //COMMON_ALGORITHM_TEST_COMMON_ALGORITHM_SNOWFLAKE_HPP_

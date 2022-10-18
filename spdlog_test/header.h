//
// Created by shecannotsee on 2022/10/18.
//
#ifndef SHETESTCODE_SPDLOG_TEST_HEADER_H_
#define SHETESTCODE_SPDLOG_TEST_HEADER_H_

#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace method1 {

void main() {
  // Create a daily logger - a new file is created every day on 2:30am
  auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 0, 0);
  // write to logfile every 5s
  spdlog::flush_every (std::chrono::seconds(5));
  // 按照指定级别实时刷新到日志系统中
  logger->flush_on(spdlog::level::trace);
  //普通信息
  logger->info("Welcome to spdlog!");
  //浮点数
  logger->warn("Support for floats {:03.2f}", 1.23456);
  //多个字符串参数
  logger->warn("Positional args are {1} {0}..", "too", "supported");
  //单个参数
  logger->error("Some error message with arg: {}", 1);
  //左对齐
  logger->error("{:<30}", "left aligned");
  //整形的十进制，十六进制，八进制，二进制
  logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  //会在同一个日志文件下添加日志
  auto logger2 = spdlog::daily_logger_mt("other","logs/daily.txt",0,0);
  logger2->info("Welcome to spdlog!");
}

};//namespace method1

namespace method2 {

void main() {

};

};//namespace method2

#endif //SHETESTCODE_SPDLOG_TEST_HEADER_H_

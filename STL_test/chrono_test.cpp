//
// Created by shecannotsee on 2022/10/17.
//
#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <unistd.h>

int main() {
  std::cout<<"start.\n";
  /* base-1 */ {
    auto start = std::chrono::steady_clock::now();
    sleep(3);
    auto end   = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>(end-start);
    std::cout<<"sleep(3) has spend: "<<elapsed_seconds.count()<<std::endl;
  }

  /* base-2 */ {
    auto start = std::chrono::system_clock::now();
    sleep(1);
    auto end = std::chrono::system_clock::now();
    std::cout<<"sleep(1) has spent ["<<(end-start).count()/* return us,1s=1000000us*/
             <<"]μs , 1s = 1000000us"<<std::endl;
  }
  /* base-3 */ {
    auto start = std::chrono::system_clock::now();
    sleep(2);
    auto end = std::chrono::system_clock::now();
    std::cout<<"sleep(2) has spent ["<<
      (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(end)-
       std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(start)).count()/* return ms,1s=1000ms*/
       <<"]ms , 1s = 1000ms"<<std::endl;
  }

  /* data */ {
    std::cout<<"=================data format=================\n";
    auto now = std::chrono::system_clock::now();
    std::time_t tm_1 = std::chrono::system_clock::to_time_t(now);
    std::string today = std::ctime(&tm_1);
    std::cout<<today;//Mon Oct 17 14:22:09 2022
  }

  /* Time Zone Map(part) */ {
    std::map<std::string, int> Time_Zone = {
        {"KLT",   1400}, // +14:00
        {"CCT",    800}, // +08:00
        {"AFT",    430}, // +04:30
        {"GMT",      0},{"UT",0},{"UTC",0},{"ZULU",0},{"WET",0},
        {"NDT",   -230}, // -02:30
        {"PST",   -800}, // -08:00
        {"IDLE", -1200}  // -12:00
    };
  }
  /* Time Zone test */ {
    std::cout<<"=================Time Zone=================\n";
    std::chrono::duration<int, std::ratio<60*60>> one_hour(1);
    std::chrono::duration<int, std::ratio<60*30>> half_an_hour(1);
    auto now = std::chrono::system_clock::now();
    auto now_hour_ago = now-one_hour;
    auto now_of_half_an_hour_age = now-half_an_hour;
    std::time_t tm_1 = std::chrono::system_clock::to_time_t(now_hour_ago);
    std::time_t tm_2 = std::chrono::system_clock::to_time_t(now_of_half_an_hour_age);
    std::cout<<"    one hour ago : "<<std::ctime(&tm_1);//std::ctime has \n
    std::cout<<"half an hour ago : "<<std::ctime(&tm_2);
  }

  std::cout<<"end.\n";
  return 0;
}

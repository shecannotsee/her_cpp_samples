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

  /* base-4 */ {
    auto start = std::chrono::system_clock::now();
    sleep(2);
    auto end = std::chrono::system_clock::now();
    std::cout<<"sleep(2) has spent ["<<
             (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1>>>(end)-
                 std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1>>>(start)).count()/* return ms,1s=1000ms*/
             <<"]s , 1s = 1s"<<std::endl;
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

  /* get_milliseconds_from_specific_time */ {
    std::cout<<"=================Time Zone=================\n";
    int year    = 2023;    year  = year-1900; // std::chrono default set
    int month   = 2;       month = month-1;   // std::chrono default set
    int day     = 14;
    int hour    = 10;
    int minute  = 32;
    int second  = 0;
    // 2023-02-14 10:32:00
    tm tm_target = {second, minute, hour, day, month, year};
    auto target = std::chrono::system_clock::from_time_t(std::mktime(&tm_target));
    auto now = std::chrono::system_clock::now();
    if (now<=target) {
      throw std::invalid_argument("[The input time is greater than the current time]");
    }
    auto duration = now - target;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::cout<< "2023-02-14 10:32:00 to now (ms) :" << milliseconds <<std::endl;
  };


  std::cout<<"end.\n";
  return 0;
}

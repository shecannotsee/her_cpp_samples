//
// Created by shecannotsee on 2022/10/21.
//

#ifndef PROTOBUF_TEST_BUFFER_DESIGN_TEST_HEADER_H_
#define PROTOBUF_TEST_BUFFER_DESIGN_TEST_HEADER_H_

#include <string.h>
#include <iostream>
#include <string>

namespace method1 {

struct package_stream {
  unsigned int flag   : 1;
  unsigned int length : 31;
};

void main() {
  package_stream a;/* init and test */{
    std::cout << sizeof(a) << std::endl;
    a.flag = 3;
    a.length = 2147483647;//max = 2147483647
    std::cout << a.flag /*1*/<< "," << a.length << std::endl;
    a.flag = 0;
    a.length = 0;
  }


  std::string data = "hello world dadsasdsdsa  ddddddddddasssssssss ddddddddd";
  package_stream data_head;/* init */ {
    data_head.flag = 0;
    data_head.length = data.size();
  }
  char buff[1024];/* init */ {
    memset(buff, 0x00, sizeof(buff));
  }
  // 将包头加入到缓冲区
  memcpy(buff+0,&data_head,sizeof(data_head));
  // 将真实数据加入到缓冲区
  memcpy(buff+sizeof(data_head),//param1:从包头结束往后加
         data.c_str()+0,  // param2:数据头(考虑到数据过长可能拆分,故+0)
         data.size());  // param3:实际的数据长度(可能会做拆开发送,所以这里并不一定是数据的总长度)

  /* recv */ {
    package_stream head;
    // 获取此次缓冲区中的包头信息(若拆包,则会在buffer里进行偏移)
    memcpy(&head,buff, sizeof(package_stream));
    char* display = new char[head.length];// 临时的接受数据的变量,若拆包,实际长度会有变化
    // 根据包头获取实际数据并放入接收buffer中
    memcpy(display, //接收buffer
           buff+ sizeof(package_stream), // 真实数据的起始位置
           head.length);// 数据的长度
    std::cout<<"recv : ["<<display<<"]"<<std::endl;
    std::string test(display,head.length); //简单做一个char*到std::string的转换
    delete[] display;display = nullptr;
    std::cout<<"str test:["<<test<<"]"<<std::endl;
  }

}
};//namespace method1

#endif //PROTOBUF_TEST_BUFFER_DESIGN_TEST_HEADER_H_

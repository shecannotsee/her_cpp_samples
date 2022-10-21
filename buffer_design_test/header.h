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
  memcpy(buff+0,&data_head,sizeof(data_head));
  memcpy(buff+sizeof(data_head),data.c_str()+0,data.size());

  /* recv */ {
    package_stream head;
    memcpy(&head,buff, sizeof(package_stream));
    char* display = new char[head.length];
    memcpy(display, buff+ sizeof(package_stream), head.length);
    std::cout<<"recv : ["<<display<<"]"<<std::endl;
    std::string test(display,head.length);
    delete[] display;display = nullptr;
    std::cout<<"str test:["<<test<<"]"<<std::endl;
  }

}
};//namespace method1

#endif //PROTOBUF_TEST_BUFFER_DESIGN_TEST_HEADER_H_

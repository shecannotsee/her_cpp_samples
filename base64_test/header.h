//
// Created by shecannotsee on 2022/10/24.
//

#ifndef BUFFER_DESIGN_TEST_BASE64_TEST_HEADER_H_
#define BUFFER_DESIGN_TEST_BASE64_TEST_HEADER_H_

#include "base64.h"

namespace method1 {
using std::cout;
using std::endl;
void main() {
  cout<<"fds:"<<sheBase64::encode("fds");     //-> ZmRz (3->4)
  cout<<endl<<"fdss:"<<sheBase64::encode("fdss");    //-> ZmRzcw==  (4->8)
  cout<<endl<<"fdssa:"<<sheBase64::encode("fdssa");   //-> ZmRzc2E= (5->8)
  cout<<endl<<"fdssafff:"<<sheBase64::encode("fdssafff");//-> ZmRzc2FmZmY=  (8->12) // 12/3=3, 3*3 -1('=') = 8
  cout<<endl;

  cout<<"ZmRz:"<<sheBase64::decode("ZmRz");     //-> ZmRz (3->4)
  cout<<endl<<"ZmRzcw==:"<<sheBase64::decode("ZmRzcw==");    //-> ZmRzcw==  (4->8)
  cout<<endl<<"ZmRzc2E=:"<<sheBase64::decode("ZmRzc2E=");   //-> ZmRzc2E= (5->8)
  cout<<endl<<"ZmRzc2FmZmY=:"<<sheBase64::decode("ZmRzc2FmZmY=");//-> ZmRzc2FmZmY=  (8->12) // 12/3=3, 3*3 -1('=') = 8
  cout<<endl;
};

};// namespace method1

#endif //BUFFER_DESIGN_TEST_BASE64_TEST_HEADER_H_

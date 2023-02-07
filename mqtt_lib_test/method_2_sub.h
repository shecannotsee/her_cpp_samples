//
// Created by shecannotsee on 2023/2/7.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_2_SUB_H_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_2_SUB_H_

#include <iostream>
#include <string>
#include <MQTTClient.h>

namespace method_2_sub {
using ::std::string;
using ::std::cout;
using ::std::endl;
// 使用方法1中的结果处理函数
using ::method_1_base::processing_results;

void main() {
//////////////////////////////////////mqtt异步订阅///////////////////////////////////////////////////////////////////////
  string address = "tcp://localhost:1883";
  string client_id = "ExampleClientSub";

  MQTTClient client;
  MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
  int return_code = 0;

  return_code = MQTTClient_create(&client, address.c_str(), client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL); {
    processing_results(return_code, "MQTTClient_create");
  }



};

};// namespace method_2_sub

#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_2_SUB_H_

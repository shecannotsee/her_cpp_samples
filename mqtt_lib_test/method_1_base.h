//
// Created by shecannotsee on 2023/2/7.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_METHOD_1_BASE_TEST_H_
#define MQTT_LIB_TEST_MQTT_LIB_METHOD_1_BASE_TEST_H_

#include <string.h>
#include <iostream>
#include <string>
#include <MQTTClient.h>

namespace method_1_base {
using ::std::cout;
using ::std::endl;
using ::std::string;

enum : int {
  Message_pass_at_least_once = 1
};

void processing_results(int return_code, const string& method_name) {
  if ( return_code != MQTTCLIENT_SUCCESS ) {
    cout<<"Failed to["<<method_name<<"],return code"<<return_code<<endl;
    exit(EXIT_FAILURE);
  }
};


void main() {
//////////////////////////////////////////mqtt同步发布///////////////////////////////////////////////////////////////////
  MQTTClient client;
  MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer; {
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
  };
  MQTTClient_message pubmsg = MQTTClient_message_initializer; {
    char msg[] = "Hello World!";
    pubmsg.payload = static_cast<void*>(msg);
    pubmsg.payloadlen = static_cast<int>((int)strlen(msg));
    pubmsg.qos = Message_pass_at_least_once;// please the notes
    pubmsg.retained = false;// please the notes
  };
  MQTTClient_deliveryToken token;
  int return_code = 0;
  return_code = MQTTClient_create(&client,"tcp://mqtt.eclipseprojects.io:1883","ExampleClientPub",
                                 MQTTCLIENT_PERSISTENCE_NONE,NULL); {
    processing_results(return_code,"MQTTClient_create");
  };

  return_code = MQTTClient_connect(client, &conn_opts); {
    processing_results(return_code,"MQTTClient_connect");
  };

  return_code = MQTTClient_publishMessage(client, "MQTT Examples", &pubmsg, &token); {
    processing_results(return_code,"MQTTClient_publishMessage");
  };


  printf("Waiting for up to %d seconds for publication of [%s]\n"
         "on topic %s for client with ClientID: %s\n",
         (int)(10000L/1000), "Hello World!", "MQTT Examples", "ExampleClientPub");
  return_code = MQTTClient_waitForCompletion(client, token, 10000L);
  printf("Message with delivery token %d delivered\n", token);

  return_code = MQTTClient_disconnect(client, 10000); {
    processing_results(return_code, "MQTTClient_disconnect");
  }

  MQTTClient_destroy(&client);
};

};// namespace method_1_base

#endif //MQTT_LIB_TEST_MQTT_LIB_METHOD_1_BASE_TEST_H_

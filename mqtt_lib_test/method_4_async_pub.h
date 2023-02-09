//
// Created by shecannotsee on 2023/2/9.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_4_ASYNE_PUB_H_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_4_ASYNE_PUB_H_

#include <iostream>
#include <string>
#include <atomic>
#include <MQTTAsync.h>

namespace method_4_async_pub {
using ::std::cout;
using ::std::endl;
using ::std::string;

std::atomic<int> finished {0};

void main() {
///////////////////////////////////mqtt异步发布//////////////////////////////////////////////////////////////////////////
  static string server_url = "tcp://localhost:1883";
  static string client_id = "async_publisher_client";
  static string topic_name = "MQTT_example";
  static char msg[] = "4_hello_world";
  // 返回值处理函数
  static auto processing_results = [](int return_code, const string& method_name) {
    if ( return_code != MQTTCLIENT_SUCCESS ) {
      cout<<"Failed to["<<method_name<<"],return code"<<return_code<<endl;
      exit(EXIT_FAILURE);
    } else {
      //cout<<method_name<<" success"<<endl;
    }
  };

  int return_code = 0;

  MQTTAsync client;/* mqtt客户端初始化 */ {
    return_code = MQTTAsync_create(&client, server_url.c_str(), client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL);
    processing_results(return_code, "MQTTAsync_create");
  }

  /* 对client设置操作相应的回调函数 */ {
    // 连接失败处理函数
    auto connlost = [](void *context, char *cause) -> void {
      MQTTAsync client = (MQTTAsync) context;
      MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
      int return_code;
      printf("\nConnection lost\n");
      printf("     cause: %s\n", cause);
      printf("Reconnecting\n");
      conn_opts.keepAliveInterval = 20;
      conn_opts.cleansession = 1;

      if ((return_code = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS) {
        cout << "Failed to start connect, return code" << return_code << endl;
        finished = 1;
      }
      processing_results(return_code, "MQTTAsync_connect");

    };
    // 消息处理函数
    auto messageArrived = [](void *context, char *topicName, int topicLen, MQTTAsync_message *m) -> int {
      // not expecting any messages
      return 1;
    };
    return_code = MQTTAsync_setCallbacks(client, NULL, connlost, messageArrived, NULL);
    processing_results(return_code, "MQTTAsync_setCallbacks");
  }

  // 连接选项设置
  MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;/* init */ {
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    auto onConnect = [](void* context, MQTTAsync_successData* response) -> void {
      MQTTAsync client = (MQTTAsync)context;
      MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
      MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
      int rc;

      printf("Successful connection\n");
      /* onSend & onSendFailure 的依赖*/
      static auto onDisconnectFailure = [](void* context, MQTTAsync_failureData* response) {
        printf("Disconnect failed\n");
        finished = 1;
      };
      static auto onDisconnect = [](void* context, MQTTAsync_successData* response) {
        printf("Successful disconnection\n");
        finished = 1;
      };
      /* onSend & onSendFailure 的依赖*/
      auto onSend = [](void* context, MQTTAsync_successData* response) -> void {
        MQTTAsync client = (MQTTAsync)context;
        MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
        int rc;

        printf("Message with token value %d delivery confirmed\n", response->token);
        opts.onSuccess = onDisconnect;
        opts.onFailure = onDisconnectFailure;
        opts.context = client;
        if ((rc = MQTTAsync_disconnect(client, &opts)) != MQTTASYNC_SUCCESS)
        {
          printf("Failed to start disconnect, return code %d\n", rc);
          exit(EXIT_FAILURE);
        }
      };
      opts.onSuccess = onSend;
      auto onSendFailure = [](void* context, MQTTAsync_failureData* response) ->void {
        MQTTAsync client = (MQTTAsync)context;
        MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
        int rc;

        printf("Message send failed token %d error code %d\n", response->token, response->code);
        opts.onSuccess = onDisconnect;
        opts.onFailure = onDisconnectFailure;
        opts.context = client;
        if ((rc = MQTTAsync_disconnect(client, &opts)) != MQTTASYNC_SUCCESS)
        {
          printf("Failed to start disconnect, return code %d\n", rc);
          exit(EXIT_FAILURE);
        }
      };
      opts.onFailure = onSendFailure;
      opts.context = client;
      pubmsg.payload = msg;
      pubmsg.payloadlen = (int)strlen(msg);
      pubmsg.qos = 1;
      pubmsg.retained = 0;
      if ((rc = MQTTAsync_sendMessage(client, topic_name.c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
      {
        printf("Failed to start sendMessage, return code %d\n", rc);
        exit(EXIT_FAILURE);
      }
    };
    conn_opts.onSuccess = onConnect;

    auto onConnectFailure = [](void* context, MQTTAsync_failureData* response) -> void {

    };
    conn_opts.onFailure = onConnectFailure;

    conn_opts.context = client;
  };
  /* 连接mqtt服务 */ {
    return_code = MQTTAsync_connect(client, &conn_opts);
    processing_results(return_code, "MQTTAsync_connect");
  }

  /* log */{
    cout << "Waiting for publication of [" << msg << "]\n";
    cout << "on topic [" << topic_name << "] for client with ClientID: [" << client_id << "]\n";
  }
  /*run*/ while (!finished) {
    usleep(10000L);
  }

  MQTTAsync_destroy(&client);

};


};// namespace method_4_async_pub

#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_4_ASYNE_PUB_H_

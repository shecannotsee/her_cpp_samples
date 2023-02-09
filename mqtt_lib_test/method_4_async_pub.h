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

  MQTTAsync client;/* mqtt客户端初始化 */ {
    processing_results(MQTTAsync_create(&client,
                                        server_url.c_str(),
                                        client_id.c_str(),
                                        MQTTCLIENT_PERSISTENCE_NONE,
                                        NULL),
                       "MQTTAsync_create");
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
    processing_results(MQTTAsync_setCallbacks(client, NULL, connlost, messageArrived, NULL),
                       "MQTTAsync_setCallbacks");
  }

  /* 连接选项设置 */
  MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;/* set */ {
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    // 连接成功所对应的回调函数
    auto onConnect = [](void* context, MQTTAsync_successData* response) -> void {
      cout << "Successful connection\n";
      MQTTAsync client = (MQTTAsync)context;
      MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;/* set */ {
        // 发送消息成功对应的回调函数
        auto onSend = [](void* context, MQTTAsync_successData* response) -> void {
          cout << "Message with token value ["<< response->token <<"] delivery confirmed\n" << endl;
          MQTTAsync client = (MQTTAsync)context;
          MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;/* set */ {
            auto onDisconnect = [](void* context, MQTTAsync_successData* response) {
            printf("Successful disconnection\n");
            finished = 1;
          };
            opts.onSuccess = onDisconnect;

            static auto onDisconnectFailure = [](void* context, MQTTAsync_failureData* response) {
            printf("Disconnect failed\n");
            finished = 1;
          };
            opts.onFailure = onDisconnectFailure;

            opts.context = client;
          };
          processing_results(MQTTAsync_disconnect(client, &opts), "MQTTAsync_disconnect");

        };
        opts.onSuccess = onSend;

        // 发送消息失败对应的回调函数
        auto onSendFailure = [](void* context, MQTTAsync_failureData* response) ->void {
          cout << "Message send failed token ["<< response->token <<"] error code ["<< response->code <<"]\n";
          MQTTAsync client = (MQTTAsync)context;
          MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;/* set */ {
            auto onDisconnect = [](void* context, MQTTAsync_successData* response) {
            printf("Successful disconnection\n");
            finished = 1;
          };
            opts.onSuccess = onDisconnect;

            static auto onDisconnectFailure = [](void* context, MQTTAsync_failureData* response) {
            printf("Disconnect failed\n");
            finished = 1;
          };
            opts.onFailure = onDisconnectFailure;

            opts.context = client;
          }
          processing_results(MQTTAsync_disconnect(client, &opts), "MQTTAsync_disconnect");
        };
        opts.onFailure = onSendFailure;

        opts.context = client;
      };
      MQTTAsync_message pubmsg = MQTTAsync_message_initializer;/* init */ {
        pubmsg.payload = msg;
        pubmsg.payloadlen = (int)strlen(msg);
        pubmsg.qos = 1;
        pubmsg.retained = 0;
      };
      processing_results(MQTTAsync_sendMessage(client, topic_name.c_str(), &pubmsg, &opts), "MQTTAsync_sendMessage");
    };
    conn_opts.onSuccess = onConnect;

    // 连接失败对应的回调函数
    auto onConnectFailure = [](void* context, MQTTAsync_failureData* response) -> void {
      cout<<"Connect failed, return code ["<< response->code <<endl;
      finished = 1;
    };
    conn_opts.onFailure = onConnectFailure;

    conn_opts.context = client;
  };

  /* 连接mqtt服务器 */
  processing_results(MQTTAsync_connect(client, &conn_opts), "MQTTAsync_connect");

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

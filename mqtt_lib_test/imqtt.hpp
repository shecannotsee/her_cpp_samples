//
// Created by shecannotsee on 2023/2/13.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_

#include <string>
#include <MQTTAsync.h>
//

class MqttService {
 public:
  MqttService() = delete;
  explicit MqttService(std::string server_url,std::string client_id);
  virtual ~MqttService() ;
 private:
  MQTTAsync client_;
  int return_code_;
 public:
  // 连接服务器
  void connect(std::string server_url);
  // 主动断开然后连接
  void re_connect(std::string new_server_url);
  // 订阅主题
  void sub_topic(std::string topic);
  // 发布信息
  void send_message(std::string message);

 public:
  // 连接失败处理函数,该函数更多出现在客户端和服务器连上后,然后心跳消失时调用
  virtual void connlost(void *context, char *cause) {
    /* log */ {
      std::cout << "\nConnection lost\n";
      std::cout << "     cause: " << cause << "\n";
      std::cout << "Reconnecting\n";
    };
    MQTTAsync client = (MQTTAsync) context;
    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;/* set */ {
      conn_opts.onSuccess = [](void* context, MQTTAsync_successData* response) -> void {};
      conn_opts.onFailure = [](void* context, MQTTAsync_failureData* response) -> void {};
      conn_opts.keepAliveInterval = 20;
      conn_opts.cleansession = 1;
    };
    // 重新连接一次
    MQTTAsync_connect(client, &conn_opts);
  };

  // 消息处理函数
  virtual int messageArrived(void *context, char *topicName, int topicLen, MQTTAsync_message *m){
    // not expecting any messages
    return 1;
  };

};


MqttService::MqttService(std::string server_url, std::string client_id)
    : return_code_(0) {
  return_code_ = MQTTAsync_create(&client_,server_url.c_str(),client_id.c_str(),MQTTCLIENT_PERSISTENCE_NONE,NULL);
  return_code_ = MQTTAsync_setCallbacks(client_, NULL, this->connlost, this->messageArrived, NULL);

};

#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_

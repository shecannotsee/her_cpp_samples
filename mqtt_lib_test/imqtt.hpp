//
// Created by shecannotsee on 2023/2/13.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_

#include <MQTTAsync.h>

class MqttService {
 private:
  MQTTAsync client_;
 public:
  MqttService() = delete;
  explicit MqttService(string server_url,string client_id) {
    process_results(MQTTAsync_create(&client_,server_url.c_str(),client_id.c_str(),MQTTCLIENT_PERSISTENCE_NONE,NULL),
                    "MQTTAsync_create");
  };
  virtual ~MqttService() {
    MQTTAsync_destroy(&(this->client_));
  }
 public:
  void connect(string server_url) {};
  void sub_topic(string topic) {};
  void send_message(string message) {};
 private:
  static void process_results(int return_code, const string& method_name) {
    if ( return_code != MQTTCLIENT_SUCCESS ) {
      throw "Failed to["+method_name+"],return code";
    }
  };
};


#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_IMQTT_HPP_

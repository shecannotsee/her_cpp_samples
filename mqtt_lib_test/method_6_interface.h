//
// Created by shecannotsee on 2023/2/10.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_6_INTERFACE_H_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_6_INTERFACE_H_

#include <string>
#include <MQTTAsync.h>

namespace method_6_interface {
using ::std::string;

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

void main() {

};

};// namespace method_6_interface {

#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_6_INTERFACE_H_

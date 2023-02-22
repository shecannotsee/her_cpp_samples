//
// Created by shecannotsee on 2023/2/22.
//

#ifndef MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_12_CPP_PUB_SUB_H_
#define MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_12_CPP_PUB_SUB_H_

#include <iostream>
#include <string>
#include <vector>
#include <future>
#include <mqtt/async_client.h>

namespace method_12_cpp_pub_sub {

using UpCallback = std::function<void(const std::string& topic, const std::string& message)>;

class mqttCallbacks : public virtual mqtt::callback,
                      public virtual mqtt::iaction_listener {
 public:
  mqttCallbacks(mqtt::async_client& client, mqtt::connect_options& connect_options)
      : client_(client),
        connect_options_(connect_options) {};
 private:
  mqtt::async_client& client_;
  mqtt::connect_options& connect_options_;
 public:
  void reconnect();

  // Re-connection failure
  void on_failure(const mqtt::token& tok) override;

  // (Re)connection success
  // Either this or connected() can be used for callbacks.
  void on_success(const mqtt::token& tok) override;

  // (Re)connection success
  void connected(const std::string& cause) override;

  // Callback for when the connection is lost.
  // This will initiate the attempt to manually reconnect.
  void connection_lost(const std::string& cause) override;

  // Callback for when a message arrives.
  void message_arrived(mqtt::const_message_ptr msg) override;

  // Callback for send message suucess
  void delivery_complete(mqtt::delivery_token_ptr token) override {
    int tokenNum = (token ? token->get_message_id() : -1);
    std::cout << "Delivery complete for token:["<<tokenNum<< "]\n";
  };

};// class callback

void main() {
  std::vector<std::string> topics{"topic_1","topic_2","topic_3"};
  std::vector<int>         QOS   {1,1,1};

  std::string serverAddress = "tcp://localhost:1883";
  std::string clientId = "method12_client";

  mqtt::async_client client(serverAddress,clientId);

  bool set_ssl = false;
  mqtt::ssl_options ssl_options{};/* set */ {
    ssl_options.set_trust_store("");
    ssl_options.set_key_store("");
    ssl_options.set_error_handler([](const std::string& msg) {
      std::cerr << "SSL Error: " << msg << std::endl;
    });
  };
  mqtt::connect_options connect_options{};/* set */ {
    connect_options.set_user_name("");
    connect_options.set_password("");
    connect_options.set_clean_session(false);
    if (set_ssl) connect_options.set_ssl(std::move(ssl_options));
    mqtt::message will_message = mqtt::message("","",/*QOS*/1, false);
    connect_options.set_will_message(std::move(will_message));
  }

  try {
    mqtt::token_ptr connect_token = client.connect(connect_options);
    connect_token->wait();// block to connect until success
    // connect_success_ = true;
  }
  catch (const mqtt::exception& exc) {
    std::cerr << "publish set or connect error:" << exc.what() << std::endl;
  };


  mqttCallbacks cb(client,connect_options);
  client.set_callback(cb);

  std::async(std::launch::async,[&](){
    for (int i=0;i<topics.size();i++) {
      client.subscribe(topics[i],QOS[i]);
    }
  });

  std::async(std::launch::async,[&](){
    for (int i=0;i<topics.size();i++) {
      client.publish(topics[i],topics[topics.size()-1],QOS[i], false);
    }
  });

  sleep(100);






};

};// namespace method_12_cpp_pub_sub

#endif //MQTT_LIB_TEST_MQTT_LIB_TEST_METHOD_12_CPP_PUB_SUB_H_

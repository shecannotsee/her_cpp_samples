//
// Created by shecannotsee on 2022/9/29.
//

#ifndef LIBEVENT_TEST_TEST_LIBEVENT_TEST_BASE_H_
#define LIBEVENT_TEST_TEST_LIBEVENT_TEST_BASE_H_

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <arpa/inet.h>
#include <unistd.h>
#include <event.h>

namespace method1 {
int tcp_base() {
  // base start
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = PF_INET;//ipv4
  serverAddr.sin_port = htons(8996);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.8.180");

  int server_socket_id = socket(PF_INET, SOCK_STREAM, 0);
  if (server_socket_id>=0)
    std::cout << "socket create success.\n";
  else
    std::cout << "socket create failed.\n";

  int bind_result = bind(server_socket_id, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  if (bind_result==0)
    std::cout << "bind success.\n";
  else
    std::cout << "bind failed.\n";

  int listen_result = listen(server_socket_id, 5);
  if (listen_result==0)
    std::cout << "start to listen,\n";
  else
    std::cout << "listen failed.\n";
  // base end
  return server_socket_id;
};

void rread(evutil_socket_t fd, short what, void *arg) {
  const char *data = (char*)arg;
  printf("Got an event on socket %d:%s%s%s%s [%s]",
         (int) fd,
         (what&EV_TIMEOUT) ? " timeout" : "",
         (what&EV_READ)    ? " read" : "",
         (what&EV_WRITE)   ? " write" : "",
         (what&EV_SIGNAL)  ? " signal" : "",
         data);
}

void main() {
  // event_base
  struct event_base* reactor = event_base_new();// or use:event_init()
  if (reactor == nullptr)
    std::cout<<"create failed.\n";
  else
    std::cout<<"create success.\n";
  // event
  int fd = tcp_base();
  struct event* someThingHappen = event_new(reactor, fd, EV_READ|EV_PERSIST, rread, (char*)"step rread");
  event_add(someThingHappen, NULL);

  event_base_loop(reactor, EVLOOP_ONCE);
  //event_base_dispatch(reactor);

  event_free(someThingHappen);
  event_base_free(reactor);
  close(fd);
};

};//namespace method1

namespace method2 {

void f_io(int fd, short event, void* args) {

  bufferevent* buff = (bufferevent*)args;
  std::string message = "123321";
  /* write to buff,example 1(add to tail) */ {
    bufferevent_write(buff, message.c_str(), message.size());
  }
  /* wirte to buff,example 2(clear and add) */ {
    evbuffer *evbuff_1 = evbuffer_new();
    evbuffer_add(evbuff_1, message.c_str(), message.size());
    bufferevent_write_buffer(buff,evbuff_1);
    evbuffer_free(evbuff_1);
  }
  char read[1024];
  /* read from buff,example 1(remove N char in buff) */ {
    int len = bufferevent_read(buff, read, 1024);
    read[len] = '\0';
    std::cout<<"read is :["<<*read<<"]\n";
  }
  /* read from buff,example 2(read and clear) */ {
    evbuffer* evbuff_2 = evbuffer_new();
    int len = bufferevent_read_buffer(buff,evbuff_2);
    read[len] = '\0';
    std::cout<<"evbuffer is :["<<evbuff_2<<"]\n";
    evbuffer_free(evbuff_2);
  }
}

void accept_client (int fd, short events, void* args) {
  evutil_socket_t client_socket_id;
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  client_socket_id = accept(fd, (struct sockaddr*)&client, &len );
  evutil_make_socket_nonblocking(client_socket_id);
  printf("accept a client %d\n", client_socket_id);

  event_base* container_father = (event_base*)args;
//  bufferevent* buff = bufferevent_socket_new(container_father,client_socket_id,BEV_OPT_CLOSE_ON_FREE);
//  if (buff==NULL) {
//    std::cout << "create buffer_event failed.\n";
//    return;
//  }
  event* client_io;
  client_io = event_new(container_father, client_socket_id, EV_READ , f_io, NULL);
  event_add(client_io, NULL);

}

void main() {
  int listen_socket_id;
  /* tcp init */ {
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(9476);

    listen_socket_id = socket(PF_INET, SOCK_STREAM, 0);//return -1 means error
    if (listen_socket_id == -1) {
      std::cout<<"create server socket failed.\n";
      return;
    }
    int bind_result = bind(listen_socket_id, (struct sockaddr *) &serverAddr, sizeof(serverAddr));//return -1 means error,0 means success
    if (bind_result == -1) {
      std::cout<<"bind failed.\n";
      return;
    }
    int listen_result = listen(listen_socket_id, 5);//return -1 means error,0 means success
    if (listen_result == -1) {
      std::cout<<"listen port failed.\n";
      return;
    }
    std::cout<<"server start listen...\n";
  }

  event_base* container_1;
  /* init */ {
    bool autoConfig = true;
    if (autoConfig) {
      event_config *config = event_config_new();
      // add config
      event_config_avoid_method(config, "select");
      event_config_avoid_method(config, "poll");// just can use epoll

      event_config_require_features(config, EV_FEATURE_ET);
      event_config_set_flag(config, EVENT_BASE_FLAG_NOLOCK);

      container_1 = event_base_new_with_config(config);
      event_config_free(config);
    } else
      container_1 = event_base_new();

    /* check config */
    const char **methods = event_get_supported_methods();
    printf("Starting Libevent %s.  Available methods are:\n",
           event_get_version());
    for (int i = 0; methods[i] != nullptr; ++i) {
      printf("    %s\n", methods[i]);
    }
  }

  int listen_fd = listen_socket_id;
  event* accept_event;
  /* set event */ {
    accept_event = event_new(container_1, listen_fd, EV_READ | EV_PERSIST, accept_client, container_1);
    event_add(accept_event,NULL);
  }

  /* set loop */ {
    bool autoConfigLoopParam = true;
    if (autoConfigLoopParam)
      event_base_dispatch(container_1);
    else
      assert(event_base_loop(container_1, EVLOOP_NO_EXIT_ON_EMPTY) == -1);
  }

  /* Destructor */ {
    event_free(accept_event);
    event_base_free(container_1);
  }
};//main

};//namespace method2

#endif //LIBEVENT_TEST_TEST_LIBEVENT_TEST_BASE_H_

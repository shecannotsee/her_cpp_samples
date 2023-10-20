//
// Created by shecannotsee on 23-10-20.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_GET_IP_H
#define LINUX_SYSTEM_LOAD_TEST_GET_IP_H

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>

namespace get_ip {

void main() {
  const char* interfaceName = "enx00e04c361b8f";  // 用您要查询的以太网卡的名称替换这里

  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock == -1) {
    perror("socket");
    return;
  }

  struct ifreq ifr;
  std::memset(&ifr, 0, sizeof(ifr));
  std::strncpy(ifr.ifr_name, interfaceName, IFNAMSIZ - 1);

  if (ioctl(sock, SIOCGIFADDR, &ifr) == -1) {
    perror("ioctl");
    close(sock);
    return;
  }

  close(sock);

  struct sockaddr_in* addr = (struct sockaddr_in*)&(ifr.ifr_addr);
  char ip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &(addr->sin_addr), ip, sizeof(ip));

  std::cout << "IP Address of " << interfaceName << ": " << std::string(ip,INET_ADDRSTRLEN) << std::endl;
}

}

#endif //LINUX_SYSTEM_LOAD_TEST_GET_IP_H

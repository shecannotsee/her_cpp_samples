//
// Created by shecannotsee on 23-10-20.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_GETALLIP_H
#define LINUX_SYSTEM_LOAD_TEST_GETALLIP_H

#include <iostream>
#include <cstring>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace get_all_ip {

int main() {
  struct ifaddrs *ifap, *ifa;
  char host[NI_MAXHOST];

  if (getifaddrs(&ifap) == -1) {
    perror("getifaddrs");
    return 1;
  }

  for (ifa = ifap; ifa != nullptr; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == nullptr) {
      continue;
    }
    if (ifa->ifa_addr->sa_family == AF_INET) {
      int s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, nullptr, 0, NI_NUMERICHOST);
      if (s == 0) {
        std::cout << "Interface:[" << std::string(ifa->ifa_name) << "],IP Address:[" << std::string(host,NI_MAXHOST) << "]" <<std::endl;
      }
    }
  }

  freeifaddrs(ifap);

  return 0;
}

}// namespace get_all_ip

#endif //LINUX_SYSTEM_LOAD_TEST_GETALLIP_H

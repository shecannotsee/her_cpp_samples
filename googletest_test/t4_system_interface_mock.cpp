//
// Created by shecannotsee on 23-12-25.
//

#include "global_test_set.h"

#include <dlfcn.h>
#include <sys/socket.h>

typedef int (*connect_func_t)(int sockfd,
                             const struct sockaddr * addr,
                             socklen_t addrlen);

connect_func_t connect_func = reinterpret_cast<connect_func_t>(dlsym(RTLD_NEXT,"connect"));

bool mock_connet = true;
int mock_connet_errno = 1;
// mock connect
extern "C" int connect(int sockfd,
                       const struct sockaddr * addr,
                       socklen_t addrlen) {
  if (mock_connet) {
    errno = mock_connet_errno;
    return errno == 0 ? 0 : -1;
  } else {
    return connect_func(sockfd, addr, addrlen);
  }
}


// typedef FILE* (fopen_func_t)(
//   const char *__restrict __filename,
//   const char *__restrict __modes);
//
// fopen_func_t fopen_func = dlsym(RTLD_NEXT,"fopen");
// bool mock_fopen;
// int mock_fopen_errno;
// extern "C" FILE* fopen(const char *__restrict __filename,
//                      const char *__restrict __modes) {
//   if (mock_fopen) {
//     errno = mock_fopen_errno;
//     return nullptr;
//   } else {
//     return fopen_func(__filename, __modes);
//   }
// }

TEST(t4_system_interface_mock, linux_system_interface) {
  // file pathty
  const std::string file_path = "../README.md";

  // open file
  FILE* file_handle = fopen(file_path.c_str(), "r");
  if (file_handle == nullptr) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // close file
  if (fclose(file_handle) != 0) {
    perror("Error closing file");
    exit(EXIT_FAILURE);
  }
}

TEST(t4_system_interface_mock, std_interface) {

}

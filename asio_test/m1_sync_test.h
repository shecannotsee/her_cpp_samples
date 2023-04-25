//
// Created by shecannotsee on 23-4-25.
//

#ifndef ASIO_TEST_ASIO_TEST_M1_SYNC_TEST_H_
#define ASIO_TEST_ASIO_TEST_M1_SYNC_TEST_H_

#include <asio.hpp>

namespace m1_sync_test {

void main() {
  asio::io_context io;
  asio::steady_timer t(io, asio::chrono::seconds(5));
  t.wait();
  std::cout << "Hello, world!" << std::endl;
};

};

#endif //ASIO_TEST_ASIO_TEST_M1_SYNC_TEST_H_

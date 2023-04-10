//
// Created by shecannotsee on 2023/4/10.
//

#ifndef T_M_TEST_MEMORY_SHARE_TEST_M1_MEMORY_SHARE_TEST_H_
#define T_M_TEST_MEMORY_SHARE_TEST_M1_MEMORY_SHARE_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define SHARE_NAME "/my_shared_memory"
#define SHARE_SIZE_4K 4096

namespace m1_memory_share_test {

int main() {
  int fd;
  char *addr;
  char buf[SHARE_SIZE_4K];

  // 通过名称创建共享内存区域
  fd = shm_open(SHARE_NAME, O_CREAT | O_RDWR, 0666);
  if (fd == -1) {
    perror("shm_open");
    exit(1);
  }

  // 设置共享内存区域大小
  if (ftruncate(fd, SHARE_SIZE_4K) == -1) {
    perror("ftruncate");
    exit(1);
  }

  // 映射共享内存到进程地址空间
  addr = static_cast<char*>(mmap(NULL, SHARE_SIZE_4K, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
  if (addr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  // 向共享内存写入数据
  sprintf(buf, "Hello, shared memory!");
  memcpy(addr, buf, strlen(buf) + 1);

  // 从共享内存读取数据并输出
  printf("%s\n", addr);

  // 解除共享内存映射
  if (munmap(addr, SHARE_SIZE_4K) == -1) {
    perror("munmap");
    exit(1);
  }

  // 关闭共享内存文件描述符
  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  // 删除共享内存对象
  if (shm_unlink(SHARE_NAME) == -1) {
    perror("shm_unlink");
    exit(1);
  }


  return 0;
};

};// namespace m1_memory_share_test

#endif //T_M_TEST_MEMORY_SHARE_TEST_M1_MEMORY_SHARE_TEST_H_

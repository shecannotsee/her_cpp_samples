//
// Created by shecannotsee on 2023/4/10.
//

#ifndef MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_2_TEST_H_
#define MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_2_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>

#define SHM_SIZE 4096
#define SEM_NAME "/my_semaphore"


namespace m2_display_2_test {

int main() {
  int shm_fd;
  char *shm_ptr;
  sem_t *semaphore;

  // 打开共享内存区域
  shm_fd = shm_open("/my_shm", O_RDONLY, 0666);

  // 映射共享内存
  shm_ptr = (char *)mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  // 打开信号量
  semaphore = sem_open(SEM_NAME, 0);

  // 读取共享内存中的数据
  sem_wait(semaphore); // 等待信号量
  printf("Message received: %s\n", shm_ptr);
  sem_post(semaphore); // 释放信号量

  // 清理资源
  sem_close(semaphore);
  munmap(shm_ptr, SHM_SIZE);

  return 0;
};

};// namespace m2_display_2_test

#endif //MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_2_TEST_H_

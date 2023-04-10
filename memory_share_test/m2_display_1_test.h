//
// Created by shecannotsee on 2023/4/10.
//

#ifndef MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_1_TEST_H_
#define MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_1_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>

#define SHM_SIZE 4096
#define SEM_NAME "/my_semaphore"

namespace m2_display_1_test {

int main() {
  int shm_fd;
  char *shm_ptr;
  sem_t *semaphore;

  // 创建共享内存区域
  shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, SHM_SIZE);

  // 映射共享内存
  shm_ptr = (char *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  // 创建信号量
  semaphore = sem_open(SEM_NAME, O_CREAT, 0666, 1);

  // 写入数据到共享内存
  sem_wait(semaphore); // 等待信号量
  sprintf(shm_ptr, "Hello, World!");
  sem_post(semaphore); // 释放信号量

  // 等待用户输入，以便演示多进程共享内存
  printf("Press any key to continue...");
  getchar();

  // 清理资源
  sem_close(semaphore);
  sem_unlink(SEM_NAME);
  munmap(shm_ptr, SHM_SIZE);
  shm_unlink("/my_shm");

  return 0;
};

};// namespace m2_display_1_test

#endif //MEMORY_SHARED_TEST_MEMORY_SHARE_TEST_M2_DISPLAY_1_TEST_H_

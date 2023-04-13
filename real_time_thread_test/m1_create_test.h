//
// Created by shecannotsee on 23-4-13.
//

#ifndef REAL_TIME_THREAD_TEST_REAL_TIME_THREAD_TEST_M1_CREATE_TEST_H_
#define REAL_TIME_THREAD_TEST_REAL_TIME_THREAD_TEST_M1_CREATE_TEST_H_

#include <pthread.h>

namespace m1_create_test {

void* thread_func(void* arg) {
  // 线程逻辑
  return nullptr;
};

int main() {
  pthread_t tid;
  pthread_attr_t attr;
  struct sched_param param{};
  // 初始化线程属性
  pthread_attr_init(&attr);
  // 设置线程为实时线程
  pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
  // 设置线程优先级
  param.sched_priority = 99;
  pthread_attr_setschedparam(&attr, &param);
  // 创建线程
  pthread_create(&tid, &attr, thread_func, NULL);
  // 等待线程结束
  pthread_join(tid, NULL);
};

};// namespace m1_create_test

#endif //REAL_TIME_THREAD_TEST_REAL_TIME_THREAD_TEST_M1_CREATE_TEST_H_

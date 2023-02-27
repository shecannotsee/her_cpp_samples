//
// Created by shecannotsee on 2022/10/10.
//

#include <stdio.h>
#include <iostream>
#include <functional>
#include <future>
#include <thread>

namespace method1{
int add(int a,int b) {
  printf("lambda : %d+%d=%d\n",a,b,a+b);
  return a+b;
};

void task_lambda() {
  std::cout<<"=================packaged_task lambda test(2,9)=================\n";
  std::packaged_task<int(int,int)> task1([](int a,int b) ->int {
    printf("lambda : %d+%d=%d\n",a,b,a+b);
    return a+b;
  });
  std::future<int> res1 = task1.get_future();//
  task1(2,9);
  std::cout<<"packaged_task lambda result\t"<<res1.get()<<"\n";
}
void task_bind() {
  std::cout<<"=================packaged_task bind test(10,10)=================\n";
  std::packaged_task<int(int,int)> task2(std::bind(add,10,10));
  std::future<int> res2 = task2.get_future();
  task2(1,2);
  std::cout<<"packaged_task bind result\t"<<res2.get()<<"\n";
}
void task_thread() {
  std::cout<<"=================packaged_task thread test(20,20)=================\n";
  std::packaged_task<int(int,int)> task(add);
  std::future<int> result = task.get_future();

  // std::thread t([](){});//link to thread(lib?), otherwise, an error will be reported during running
  std::thread task_td(std::move(task), 20, 20);
  task_td.join();

  std::cout << "task_thread:\t" << result.get() << '\n';
}

};//namespace method1

int main(){
  std::cout<< "Test start.\n";
  task_lambda();
  task_bind();
  task_thread();

  std::cout<< "Done.\n";
};


#endif //VLPT_TEST_TEST_SHETHREADPOOL_TEST_STD_PACKAGED_TASK_SRC_TEMP_H_

//
// Created by shecannotsee on 24-5-10.
//

#ifndef M2_MOCK_TEST_H
#define M2_MOCK_TEST_H

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>
#include <stdexcept>

namespace m2_mock_test {

class MyStub {
public:
  MyStub() : m_pageSize(sysconf(_SC_PAGE_SIZE)) {
    if (m_pageSize < 0) {
      m_pageSize = 4096; // 默认页面大小
    }
  }

  template<typename FuncType, typename StubType>
  void set(FuncType originalFunc, StubType stubFunc) {
    char* originalFn = reinterpret_cast<char*>(originalFunc);
    char* stubFn = reinterpret_cast<char*>(stubFunc);

    char* pageAddr = pageof(originalFn);

    if (mprotect(pageAddr, m_pageSize, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
      throw std::runtime_error("Failed to set memory protection.");
    }

    // 使用原始函数的前几个字节来跳转到替换函数
    const size_t jumpSize = 5; // jmp指令的长度
    std::memset(originalFn, 0xE9, jumpSize); // JMP指令
    *reinterpret_cast<int*>(originalFn + 1) = stubFn - originalFn - jumpSize;

    if (mprotect(pageAddr, m_pageSize, PROT_READ | PROT_EXEC) == -1) {
      throw std::runtime_error("Failed to restore memory protection.");
    }
  }

private:
  long m_pageSize;

  char* pageof(char* addr) {
    return reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(addr) & ~(m_pageSize - 1));
  }
};


int func() {
  return 0;
}

int func_mock() {
  return -1;
}


// 测试函数，不修改其内部代码
bool test() {
  // 创建 MyStub 实例
  MyStub stub;

  // 替换函数逻辑
  stub.set(func, func_mock);

  if (func() == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // 执行测试
  printf("Test result: %s\n", test() ? "Passed" : "Failed");

  return 0;
}
}


#endif //M2_MOCK_TEST_H

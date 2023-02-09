//
// Created by shecannotsee on 2023/2/9.
//

#ifndef CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_TEST_CLASS_H_
#define CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_TEST_CLASS_H_

class test_class {
 private:
  int data_;
  int no_;

 public:
  test_class() = delete;
  explicit test_class(int);
  ~test_class() = default;

 public:
  void set_data(const int&) noexcept;
  int get_data();
};

#endif  // CLANG_FORMAT_TEST_CLANG_FORMAT_TEST_SRC_TEST_CLASS_H_

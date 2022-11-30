//
// Created by shecannotsee on 2022/11/30.
//

#ifndef SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_
#define SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_

#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

// simple use
namespace method1{

inline int add(int a, int b) {
  return a+b;
}

TEST(add_test, 1_2) {
  EXPECT_EQ(add(1,2),3);
};

TEST(add_test, other) {
  EXPECT_EQ(add(1,2),3);
  EXPECT_EQ(add(3,4),7);
  EXPECT_EQ(add(1,5),6);
};


void main_r_void() {
  std::string intStr = std::to_string(101);
  std::string str = "100";
  ASSERT_STREQ(intStr.c_str(), str.c_str());// compare string( std::string->c_str() )
};

int main_r_int() {
  testing::InitGoogleTest();;
  return RUN_ALL_TESTS();// 运行所有测试单元
}

};// namespace method1

#endif //SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_

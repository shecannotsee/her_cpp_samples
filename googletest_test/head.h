//
// Created by shecannotsee on 2022/11/30.
//

#ifndef SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_
#define SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_

#include <assert.h>
#include <string>
#include <exception>
#include <gtest/gtest.h>

// simple use
namespace method1{

int return_0() {return 0;}
int return_9() {return 9;}

// 单独的测试语句
void main_r_void() {
  std::string intStr = std::to_string(101);
  std::string str = "100";
  // ASSERT_系列：如果当前点检测失败则退出当前函数
  // EXPECT_系列：如果当前点检测失败则继续往下执行
  /* 字符串检查 */ {
    std::cout<<"\n########### str test: ###########\n";
    EXPECT_STREQ(intStr.c_str(), str.c_str());// c风格字符串检查,相等(返回true)则通过测试
    EXPECT_STRNE(intStr.c_str(),intStr.c_str());// 不相等才返回true
    std::cout<<"=========== str test end. ===========\n";
  }
  /* 数值型数据检查 */ {
    std::cout<<"\n########### value test: ###########\n";
    EXPECT_EQ(return_0(),return_9());// 检查是否相等,相等(返回ture)则通过测试
    EXPECT_NE(return_0(),return_0());// 不相等才返回true
    EXPECT_LT(return_9(),return_0());// 参数1小于参数2才返回true
    EXPECT_LE(return_9(),return_0());// 小于等于
    EXPECT_GT(return_0(),return_9());// 参数1大于参数2才返回true
    EXPECT_GE(return_0(),return_9());// 大于等于
    std::cout<<"=========== value test end. ===========\n";
  }
  /* bool检查 */ {
    std::cout<<"\n########### bool test: ###########\n";
    EXPECT_TRUE(false)<<"EXPECT_TRUE(condition):want to condition is true";// 期待结果是true,并添加额外的日志信息
    EXPECT_FALSE(true)/*<<"EXPECT_false(condition):want to condition is false\""*/;// 期待结果是false
    std::cout<<"=========== bool test end. ===========\n";
  }
  /* 程序崩溃或者异常测试 */ {
    std::cout<<"\n########### error test: ###########\n";
    EXPECT_DEATH([]{
        exit(1);
      }, "123");
    EXPECT_EXIT([]{
        exit(1);
      },::testing::ExitedWithCode(0),"quit");// ASSERT_EXIT
    EXPECT_THROW([]{
//      throw "error";
      },std::exception);
    std::cout<<"=========== error test end. ===========\n";
  }
  /* ASSERT_*测试 */ {
    ASSERT_STREQ(intStr.c_str(), str.c_str());
    ASSERT_EQ(return_0(), return_9());
  }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline int add(int a, int b) {
  return a+b;
}

TEST(/*父模板名*/add_test,/*具体父模块下实际子模块名*/1_2) {
  EXPECT_EQ(add(1,2),3);
};

TEST(/**/add_test, other) {
  EXPECT_EQ(add(1,2),3);
  EXPECT_EQ(add(3,4),7);
  EXPECT_EQ(add(1,5),6);
};

// 运行测试单元
int main_r_int() {
  testing::InitGoogleTest();;
  return RUN_ALL_TESTS();// 运行所有测试单元
}

};// namespace method1

#endif //SQLITE_ORM_TEST_GOOGLETEST_TEST_HEAD_H_

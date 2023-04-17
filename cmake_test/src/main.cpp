#include <glog/logging.h>
#include <gtest/gtest.h>

inline int add(int a, int b) {
  return a+b;
}

TEST(/*父模板名*/add_test,/*具体父模块下实际子模块名*/1_2) {
EXPECT_EQ(add(1,2),3);
};

int main(int argc, char** argv) {
  testing::InitGoogleTest();;
  // 初始化 glog 库
  google::InitGoogleLogging(argv[0]);

  // 设置日志输出级别
//  FLAGS_log_level = google::INFO;

  // 设置日志输出路径
  FLAGS_log_dir = "./";

  // 输出日志
  LOG(INFO) << "This is an info message.";
  LOG(WARNING) << "This is a warning message.";
  LOG(ERROR) << "This is an error message.";

  // 关闭 glog 库
  google::ShutdownGoogleLogging();

  return RUN_ALL_TESTS();// 运行所有测试单元
}

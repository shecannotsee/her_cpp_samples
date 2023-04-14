#include <glog/logging.h>

int main(int argc, char** argv) {
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

  return 0;
}

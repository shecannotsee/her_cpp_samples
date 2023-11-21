//
// Created by shecannotsee on 23-11-21.
//

#ifndef GET_FILE_INFO_H
#define GET_FILE_INFO_H

#include <chrono>
#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <fstream>


namespace get_file_info {

std::string getIncrementalContent(const std::string& filePath, std::streampos& offset) {
  // 在最后打开文件
  std::ifstream file(filePath, std::ios::ate);

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return {};  // Return an empty string to indicate an error
  }

  // 获取文件的当前大小
  std::streampos fileSize = file.tellg();
  if (offset == 0) {
    // 如果偏移量为 0，则将其重置为文件的开头
    file.seekg(0);
  } else if (fileSize < offset) {
    // 文件大小小于上一个偏移量，如果文件在外部被截断或修改，则可能会发生这种情况。在这种情况下，请将偏移量重置为文件的开头。
    offset = 0;
    file.seekg(offset);
  } else {
    // 将位置设置为最后一个偏移量
    file.seekg(offset);
  }

  // 计算增量内容的大小
  std::streamsize incrementalSize = fileSize - offset;

  if (incrementalSize > 0) {
    // 分配缓冲区以存储增量内容
    std::unique_ptr<char[]> buffer(new char[incrementalSize]);
    // 将增量内容读入缓冲区
    file.read(buffer.get(), incrementalSize);
    // 将偏移量更新为文件的当前末尾
    offset = file.tellg();
    // 从缓冲区构造字符串
    std::string incrementalContent(buffer.get(), incrementalSize);
    // Return the incremental content
    return incrementalContent;
  } else {
    // 无增量内容
    return {};
  }
}

void main() {
  auto time_debug_func = [](const std::string& flag, std::chrono::time_point<std::chrono::system_clock> time) {
    // 将时间转换为时间戳
    const long long timestamp = std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
    // 打印时间戳
    std::cout << flag << "Last modified timestamp: " << timestamp << std::endl;
    // 将时间转换为时分秒
    auto time_point = std::chrono::system_clock::to_time_t(time);
    std::tm* tm_info = std::localtime(&time_point);
    // 打印时分秒
    std::cout << flag << "Last modified time: " << std::put_time(tm_info, "%Y-%m-%d %H:%M:%S") << std::endl;
  };

  const char* filename = "../test.txt"; // 替换为你的文件名
  std::streampos offset = 0;  // Initialize the offset to 0

  struct stat file_stat;

  while (1) {
    if (stat(filename, &file_stat) == 0) {
      static auto last_update= std::chrono::system_clock::from_time_t(file_stat.st_mtime);

      // 获取最近更新时间
      auto recent_update= std::chrono::system_clock::from_time_t(file_stat.st_mtime);
        // 检查文件是否已经更新
        if ( recent_update > last_update || offset == 0) {
          std::cout << "文件已更新" << std::endl;
          time_debug_func("[上次更新时间]", last_update);
          time_debug_func("[最近更新时间]", recent_update);
          last_update = recent_update;
          std::string incrementalContent = getIncrementalContent(filename, offset);
          std::cout << incrementalContent << std::endl;
        } else {
          std::cout << "文件未更新" << std::endl;
        }
    } else {
      std::cerr << "无法获取文件信息" << std::endl;
    }

    sleep(5);
  }
}

}// namesapce get_file_info

#endif //GET_FILE_INFO_H

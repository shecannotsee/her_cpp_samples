//
// Created by shecannotsee on 23-11-29.
//

#ifndef GET_FILE_INCREMENTAL_CONTENT_H
#define GET_FILE_INCREMENTAL_CONTENT_H

#include <fstream>
#include <sstream>
#include <thread>

namespace get_file_incremental_content {

std::string getIncrementalContent(const std::string& filePath, std::streampos& startOffset) {
  std::ifstream inputFile(filePath, std::ios::binary);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return "";
  }

  // 设置文件流的起始位置
  inputFile.seekg(startOffset);

  if (!inputFile.good()) {
    std::cerr << "Error seeking to the specified position in file: " << filePath << std::endl;
    return "";
  }

  // 从当前位置到文件结尾读取内容
  std::ostringstream contentStream;
  contentStream << inputFile.rdbuf();

  // 检查是否发生了读取错误
  if (inputFile.bad()) {
    std::cerr << "Error reading file: " << filePath << std::endl;
    return {};
  }
  startOffset = inputFile.tellg();
  return contentStream.str();
}

void main() {
  // 示例用法
  std::string filePath = "../test.txt";
  std::streampos startOffset = 0; // 替换为你的起始位置

  while (1) {
    std::string incrementalContent = getIncrementalContent(filePath, startOffset);

    if (!incrementalContent.empty()) {
      std::cout << "Incremental content:\n" << incrementalContent << std::endl;
    } else {
      std::cerr << "Failed to get incremental content." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

}

#endif //GET_FILE_INCREMENTAL_CONTENT_H

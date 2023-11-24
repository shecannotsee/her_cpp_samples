//
// Created by shecannotsee on 23-11-24.
//
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

int main() {
  std::cout << "start.\n";
  std::string logContentStr;
  std::string errorLogBuffer_;
  /* get data from file */ {
    // 文件路径
    std::string filename = "../example.txt";
    // 创建 ifstream 对象
    std::ifstream inputFile(filename);
    // 检查文件是否成功打开
    if (!inputFile.is_open()) {
      std::cerr << "Unable to open file: " << filename << std::endl;
      return 1; // 退出程序，返回错误码
    }
    // 读取文件内容
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    logContentStr = fileContent;
    // 关闭文件
    inputFile.close();
  }

  auto logFraming = [](const std::string& logContentStr) ->std::vector<std::tuple<int, int, std::string>> {
    std::vector<std::tuple<int, int, std::string>> logEntries;
    std::tuple<int,int,std::string> tmp;
    // 用于存储未匹配部分的字符串
    std::string remainingLog = std::string(logContentStr);
    struct LogEntry {
      size_t start_index;
      size_t end_index;
      std::string date;
      std::string time;
      std::string log_level;
      std::string module;
      std::string file_name;
      std::string function_name;
      std::string line_number;
      std::string content;
    } entry;
    // regex
    // 定义正则表达式来匹配日志条目的不同部分
    const std::regex logRegex(
        "\\[([^\\]]+)\\s([^\\]]+)\\s([^\\]]+)\\]\\[([^\\]]+)\\]\\[([^\\]]+)\\]"
        "\\[([^\\]]+)\\]\\[([^\\]]+)\\](.*)");
    std::smatch match;
    // 在字符串中查找所有匹配的日志条目
    int currcurrentIndex = 0;
    while (std::regex_search(remainingLog, match, logRegex)) {
      // std::cout << "match[1]: " << match[1] << std::endl;
      // std::cout << "match[2]: " << match[2] << std::endl;
      // std::cout << "match[3]: " << match[3] << std::endl;
      // std::cout << "match[4]: " << match[4] << std::endl;
      // std::cout << "match[5]: " << match[5] << std::endl;
      // std::cout << "match[6]: " << match[6] << std::endl;
      // std::cout << "match[7]: " << match[7] << std::endl;
      // std::cout << "match[8]: " << match[8] << std::endl;
      // std::cout << "-----------------------------" << std::endl;
      // std::cout << "match[0]: " << match[0] << std::endl;
      // std::cout << "-----------------------------" << std::endl;
      entry.start_index    = currcurrentIndex;
      entry.end_index      = currcurrentIndex+match[0].length();
      entry.date         = match[1];
      entry.time         = match[2];
      entry.log_level    = match[3];
      entry.module       = match[4];
      entry.file_name    = match[5];
      entry.function_name= match[6];
      entry.line_number  = match[7];
      entry.content      = match[8];
      currcurrentIndex = entry.end_index + 1;

      std::get<0>(tmp) = entry.start_index;
      std::get<1>(tmp) = entry.end_index;
      std::get<2>(tmp) = entry.log_level;
      logEntries.push_back(tmp);
      // 更新待匹配的字符串，去掉已匹配的部分
      remainingLog = match.suffix();
    }

    return logEntries;
  };

  auto logsIndex = logFraming(logContentStr);
  std::cout << logsIndex.size() << std::endl;
  for (const auto& index : logsIndex) {
    if (std::get<2>(index) == "WARN") {
      errorLogBuffer_ += logContentStr.substr(
          std::get<0>(index), std::get<1>(index)-std::get<0>(index));
      errorLogBuffer_ += "\n";
    }
  }
  std::cout << "errorlog:--------------------\n";
  std::cout << errorLogBuffer_ << "\n";


  std::cout << "Done.\n";
  return 0;

}

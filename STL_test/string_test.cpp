//
// Created by shecannotsee on 23-11-21.
//
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

int main() {
  /* 分隔符 */{
    // 输入的字符串
    std::string inputString = "aaaaaaaaaa;bbbbbbbbbbb;cccccccccccc";

    // 使用 std::istringstream 进行字符串分隔
    std::istringstream iss(inputString);
    std::string token;

    // 使用 getline 和分号作为分隔符逐个提取数据
    std::getline(iss, token, ';');
    std::string part1 = token;

    std::getline(iss, token, ';');
    std::string part2 = token;

    std::getline(iss, token, ';');
    std::string part3 = token;

    // 打印提取的数据
    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;
    std::cout << "Part 3: " << part3 << std::endl;
  }

  /* \0分隔 */{
    // define
    std::string data;
    std::string streamBuffer_;
    auto func = [](const std::string& stream, std::string& buffer) {
      std::vector<std::string> result;
      size_t start = 0;

      for (size_t i = 0; i < stream.length(); ++i) {
        if (stream[i] == '\0') {
          std::string frame;
          if (!buffer.empty()) {
           frame = buffer + stream.substr(start, i - start);
            buffer.clear();
          } else {
            frame = stream.substr(start, i - start);
          }
          result.push_back(frame);
          start = i + 1;
        }
      }

      // 输出最后一个字符串
      if (start < stream.length()) {
        buffer =  stream.substr(start);
      }

      return result;
    };

    /* first round */ {
      std::cout << "first round\n";
      data = std::string("Data1\0Data22\0Data333\0Data44",27);
      auto frames = func(data, streamBuffer_);
      for (const auto& a: frames) {
        std::cout << a.size() << ":" << a << std::endl;
      }
      std::cout << "buffer:" << streamBuffer_ << std::endl;
    }
    /* second round */ {
      std::cout << "second round\n";
      data = std::string("44\0Data55555",12);
      auto frames = func(data, streamBuffer_);
      for (const auto& a: frames) {
        std::cout << a.size() << ":" << a << std::endl;
      }
      std::cout << "buffer:" << streamBuffer_ << std::endl;
    }


  }

  /* E check */ {
    std::cout << "E check =============================\n";
    std::vector<std::string> datas = {
      "xxxxxx-D.log",
      "xxxxxx-D.1.log",
      "xxxxxx-D.2.log",
      "xxxxxx-D.3.log",
      "xxxxxx-I.log",
      "xxxxxx-I.1.log",
      "xxxxxx-I.2.log",
      "xxxxxx-I.3.log",
      "xxxxxx-W.log",
      "xxxxxx-W.1.log",
      "xxxxxx-W.2.log",
      "xxxxxx-W.3.log",
      "xxxxxx-E.log",
      "xxxxxx-E.1.log",
    };
    for (auto data: datas) {
      // 使用迭代器倒序遍历std::string
      for (int i= data.size()-1; i>=0 ; --i) {
        if (data[i] == '-') {
          if (data[i+1] == 'E') {
            std::cout << data << std::endl;
          }
          break;
        }

      }
    }

  }

  /* log framing */ {
    struct LogEntry {
      size_t startIndex;
      size_t endIndex;
      std::string dateTime;
      std::string logLevel;
      std::string module;
      std::string fileName;
      std::string functionName;
      std::string lineNumber;
      std::string content;
    };

        std::cout << "log framing =================\n";
    // 示例日志条目
    const std::string logEntry =
        "[2023-11-13 17:35:16:291 INFO] [NetWork][handleData.c][recvNWData][156] Recv Net Data : xxxxxxxxxxxxxxx\n"
        "[2023-11-13 17:35:16:291 DEBUG] [NetWork][handleData.c][recvNWData][156] zzzzzzzzzzzzz\n";
    std::cout << logEntry << std::endl;
    std::cout << "logEntry done.\n";

    // 定义正则表达式来匹配日志条目的不同部分
    std::regex logRegex(R"(\[([\d\s:-]+)\s(\w+)\]\s\[(\w+)\]\[(\w+\.\w+)\]\[(\w+)\]\[(\d+)\]\s(.+))");

    // 用于存储匹配结果的std::smatch对象
    std::smatch match;

    // 用于存储多个日志条目
    std::vector<LogEntry> logEntries;

    // 开始位置
    size_t currentIndex = 0;

    // 用于存储未匹配部分的字符串
    std::string remainingLog = logEntry;

    // 在字符串中查找所有匹配的日志条目
    while (std::regex_search(remainingLog, match, logRegex)) {
        LogEntry entry;
        entry.startIndex = currentIndex;
        entry.endIndex = currentIndex + match[0].length() - 1;
        entry.dateTime = match[1];
        entry.logLevel = match[2];
        entry.module = match[3];
        entry.fileName = match[4];
        entry.functionName = match[5];
        entry.lineNumber = match[6];
        entry.content = match[7];

        // 将当前匹配的日志条目添加到集合中
        logEntries.push_back(entry);

        // 更新起始位置
        currentIndex += match[0].length();

        // 更新待匹配的字符串，去掉已匹配的部分
        remainingLog = match.suffix();
    }

    // 输出每条日志的起始和结束位置
    for (const auto& entry : logEntries) {
        std::cout << "Start Index: " << entry.startIndex << ", End Index: " << entry.endIndex << std::endl;
        std::cout << "Date/Time: " << entry.dateTime << std::endl;
        std::cout << "Log Level: " << entry.logLevel << std::endl;
        std::cout << "Module: " << entry.module << std::endl;
        std::cout << "File Name: " << entry.fileName << std::endl;
        std::cout << "Function Name: " << entry.functionName << std::endl;
        std::cout << "Line Number: " << entry.lineNumber << std::endl;
        std::cout << "Content: " << entry.content << std::endl;
        std::cout << "------------------------" << std::endl;
    }

  }
  return 0;
}

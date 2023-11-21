//
// Created by shecannotsee on 23-11-21.
//
#include <iostream>
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


  return 0;
}

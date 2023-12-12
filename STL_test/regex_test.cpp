//
// Created by shecannotsee on 23-11-24.
//
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <dirent.h>

long long  calculateDirectorySize(std::string dirPath) {
  DIR *dir;
  struct dirent *entry;
  struct stat info;
  long long totalSize = 0;

  dir = opendir(dirPath.c_str());

  if (!dir) {
    std::cerr << "Error opening directory" << std::endl;
    return -1;
  }

  while ((entry = readdir(dir)) != nullptr) {
    // Construct the full path of the entry
    std::string fullPath = std::string(dirPath) + "/" + entry->d_name;

    if (stat(fullPath.c_str(), &info) != -1) {
      if (S_ISDIR(info.st_mode)) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
          // Recursively calculate size for subdirectories
          totalSize += calculateDirectorySize(fullPath.c_str());
        }
      } else if (S_ISREG(info.st_mode)) {
        totalSize += info.st_size;
      }
    }
  }

  closedir(dir);

  return totalSize;
}

int main() {
  std::cout << "start.\n";
  /* log content */ {
    p1:
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
        std::string threadId;
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
          "\\[([^\\]]+)\\]\\[([^\\]]+)\\]\\[([^\\]]+)\\](.*)");
      std::smatch match;
      // 在字符串中查找所有匹配的日志条目
      int currcurrentIndex = 0;
      while (std::regex_search(remainingLog, match, logRegex)) {
        std::cout << "match[1]: " << match[1] << std::endl;
        std::cout << "match[2]: " << match[2] << std::endl;
        std::cout << "match[3]: " << match[3] << std::endl;
        std::cout << "match[4]: " << match[4] << std::endl;
        std::cout << "match[5]: " << match[5] << std::endl;
        std::cout << "match[6]: " << match[6] << std::endl;
        std::cout << "match[7]: " << match[7] << std::endl;
        std::cout << "match[8]: " << match[8] << std::endl;
        std::cout << "match[9]: " << match[9] << std::endl;

        std::cout << "-----------------------------" << std::endl;
        std::cout << "match[0]: " << match[0] << std::endl;
        std::cout << "-----------------------------" << std::endl;
        entry.start_index    = currcurrentIndex;
        entry.end_index      = currcurrentIndex+match[0].length();
        entry.date         = match[1];
        entry.time         = match[2];
        entry.log_level    = match[3];
        entry.threadId     = match[4];
        entry.module       = match[5];
        entry.file_name    = match[6];
        entry.function_name= match[7];
        entry.line_number  = match[8];
        entry.content      = match[9];
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
    exit(1);
  }
  /* log file name */
  {
    p2:
    std::vector<std::string> files = {
      "moduleA.log","moduleA.1.log","moduleA.2.log","moduleA.3.log","moduleA.4.log",
      "moduleB.log","moduleB.1.log","moduleB.2.log",
      "moduleC.log","moduleC.1.log","moduleC.2.log","moduleC.3.log","moduleC.4.log",
      "moduleD.log"
    };
    enum class log_module {DEFAULT,A,B,C,D};
    enum class log_file_type {USING,UPLOADABLE};
    std::vector<std::tuple<log_module,log_file_type>> files_info{files.size()};


    const std::string moduleA = "moduleA";
    const std::string moduleB = "moduleB";
    const std::string moduleC = "moduleC";
    const std::string moduleD = "moduleD";

    for ( int i = 0; i<files.size(); ++i) {
      std::vector<int> founds;

      for ( int j = 0; i < files[j].size(); ++j ) {
        if (files[i][j] == '.') {
          founds.emplace_back(j);
        }
      }
      if (!founds.empty()) {
        founds.emplace_back(files[i].size());
      }

      int start_index = 0;
      for (const auto& index : founds) {
        std::string tmp = files[i].substr(start_index,index-start_index);
        if (tmp == moduleA) {
          std::get<0>(files_info[i]) = log_module::A;
          continue;
        } else if (tmp == moduleB) {
          std::get<0>(files_info[i]) = log_module::B;
          continue;
        } else if (tmp == moduleC) {
          std::get<0>(files_info[i]) = log_module::C;
          continue;
        } else if (tmp == moduleD) {
          std::get<0>(files_info[i]) = log_module::D;
          continue;
        }
        for (const auto& n : tmp) {
          if (std::isdigit(n)) {
            std::get<1>(files_info[i]) = log_file_type::UPLOADABLE;
            continue;
          }
        }


        std::cout << tmp.size() << ":" << tmp << std::endl;
        start_index = index + 1;
      }
    }

    std::cout << "" << std::endl;

  }
  std::cout << "Done.\n";
  return 0;

}

//
// Created by shecannotsee on 23-12-12.
//

#ifndef FILE_DIR_TEMP_H
#define FILE_DIR_TEMP_H

#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

#include <string>

namespace file_dir_temp {
using std::string;

/**
 * @brief 临时目录
 */
class TempDir {
public:
  TempDir() = delete;
  explicit TempDir(const string& dirPath): dirPath_(dirPath) {
    // Check if the directory already exists
    struct stat info;
    if (stat(dirPath_.c_str(), &info) != 0) {
      // Directory does not exist, create the directory
      if (mkdir(dirPath_.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) {
        std::cerr << "Failed to create temporary directory: " << dirPath_ << std::endl;
      }
    }
  }
  ~TempDir() {
    // Remove the directory and its contents on destruction
    if (access(dirPath_.c_str(), F_OK) == 0) {
      if (rmdir(dirPath_.c_str()) != 0) {
        std::cerr << "Failed to delete temporary directory: " << dirPath_ << std::endl;
      }
    }
  }
private:
  string dirPath_;
};

/**
 * @brief 临时文件
 */
class TempFile {
public:
  TempFile() = delete;
  explicit TempFile(const string& filePath): filePath_(filePath) {
    // Check if the file already exists
    std::ifstream file(filePath_);
    if (!file.good()) {
      // File does not exist, create the file
      std::ofstream createFile(filePath_);
      if (!createFile.is_open()) {
        std::cerr << "Failed to create temporary file: " << filePath_ << std::endl;
      }
    }
  }
  ~TempFile() {
    // Delete the file on destruction
    if (std::remove(filePath_.c_str()) != 0) {
      std::cerr << "Failed to delete temporary file: " << filePath_ << std::endl;
    }
  }
private:
  string filePath_;
};

void main() {
  TempDir temp("../temp");
  TempDir temp2("../temp2");
  TempFile zzz("../temp/123.txt");
  TempFile zz1z("../123.txt");
  TempFile zz11z("../1234.txt");

  sleep(5);
  std::cout << "done\n";
}

}

#endif //FILE_DIR_TEMP_H

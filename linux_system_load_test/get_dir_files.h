//
// Created by shecannotsee on 23-11-21.
//

#ifndef GET_DIR_FILES_H
#define GET_DIR_FILES_H

#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

namespace get_dir_files {

std::vector<std::string> getFilesInDirectory(const std::string& directoryPath) {
  std::vector<std::string> fileNames;

  // 打开目录
  DIR *dir = opendir(directoryPath.c_str());
  if (dir == nullptr) {
    std::cerr << "Error opening directory: " << directoryPath << std::endl;
    return fileNames;
  }

  // 读取目录中的文件
  struct dirent *entry;
  while ((entry = readdir(dir)) != nullptr) {
    // 获取文件信息
    struct stat fileStat;
    std::string fullPath = directoryPath + "/" + entry->d_name;

    // 忽略当前目录(".")和上一级目录("..")
    if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
      // 检查是否为文件
      if (stat(fullPath.c_str(), &fileStat) == 0 && S_ISREG(fileStat.st_mode)) {
        fileNames.push_back(entry->d_name);
      }
    }
  }

  // 关闭目录
  closedir(dir);

  return fileNames;
}


void main() {
  std::string directoryPath = "/home/shecannotsee/desktop/all_code/sheTestcode/linux_system_load_test";
  std::vector<std::string> files = getFilesInDirectory(directoryPath);

  // 输出文件名
  for (const auto& fileName : files) {
    std::cout << fileName << std::endl;
  }

}

}// namespace get_dir_files

#endif //GET_DIR_FILES_H

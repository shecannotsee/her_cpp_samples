//
// Created by shecannotsee on 23-11-27.
//

#ifndef GET_FILE_STORE_H
#define GET_FILE_STORE_H

#include <string>
#include <sys/stat.h>

namespace get_file_store {

void main() {
  const std::string file_path = "/home/shecannotsee/desktop/temp/store/100M_file";
  struct stat file_info{};

  if (stat(file_path.c_str(), &file_info) != 0) {
    std::cout << "Error getting file information\n";
  }

  // 文件大小以字节为单位
  std::cout << "File size: " << file_info.st_size << " bytes = ";
  std::cout << file_info.st_size/1024 << " Kb = ";
  std::cout << file_info.st_size/1024/1024 << " Mb\n";
}

}

#endif //GET_FILE_STORE_H

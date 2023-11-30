//
// Created by shecannotsee on 23-11-29.
//

#ifndef GET_FILE_UPDATE_H
#define GET_FILE_UPDATE_H

#include <thread>
#include <sys/types.h>
#include <sys/stat.h>

namespace get_file_update {

ino_t getFileInode(const std::string& file_path) {
  struct stat file_stat{};

  if (stat(file_path.c_str(), &file_stat) == 0) {
    // 文件存在
    return file_stat.st_ino;
  } else {
    // 文件不存在或发生错误，返回0表示无效的inode号
    perror("Error");
    return 0;
  }
}

bool file_change(const std::string& file_path, const ino_t& previous_inode) {
  struct stat file_stat{};

  if (stat(file_path.c_str(), &file_stat) == 0) {
    // 文件存在
    const ino_t current_inode = file_stat.st_ino;

    if (current_inode != previous_inode) {
      // 文件已更新
      std::cout << "File has been updated." << std::endl;
      return true;
    } else {
      // 文件未更新
      std::cout << "File has not been updated." << std::endl;
      return false;
    }
  } else {
    // 文件不存在或发生错误
    perror("Error");
    return false;
  }
}

void main() {
  const std::string file_path = "../update.txt";  // 替换成你要检查的文件路径
  const ino_t previous_inode = getFileInode(file_path);  // 初始值，确保第一次比较时不会误报文件已更新

  while (1) {
    if (file_change(file_path, previous_inode)) {
      std::cout << "The file has changed\n";
      // 处理文件已更新的情况
      // 可以在这里添加需要执行的操作
    } else {
      // 处理文件未更新或发生错误的情况
      // 可以在这里添加需要执行的操作
      std::cout << "File unchanged\n";

    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

}

#endif //GET_FILE_UPDATE_H

//
// Created by shecannotsee on 23-11-17.
//

#ifndef LINUX_SYSTEM_LOAD_TEST_GET_DIR_STORE_H
#define LINUX_SYSTEM_LOAD_TEST_GET_DIR_STORE_H

#include <string>
#include <fstream>

namespace get_dir_store {

void main() {
  /* get file store */ {
    std::cout << "get file store #####\n";
    // create 100M file
    // dd if=/dev/zero of=100M_file bs=1M count=100
    std::string fileName = "/home/shecannotsee/desktop/temp/store/100M_file";
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (file.is_open()) {
      // 获取文件大小
      std::streamsize fileSize = file.tellg();
      auto fileSizeUint64 = static_cast<uint64_t>(fileSize);
      std::cout << fileSizeUint64 << std::endl;
      // 关闭文件
      file.close();
    }
  }

  /* get dir store */ {
    std::cout << "get dir store #####\n";
    std::string path = "/home/shecannotsee/desktop/temp/store";
    long long storageThreshold = 100 * 1024 * 1024;
    struct statvfs stat {};
    if (statvfs(path.c_str(), &stat) != 0) {
      std::cout << "Error getting filesystem statistics." << std::endl;
      return;
    }
    unsigned long usedSpace = (stat.f_blocks - stat.f_bfree) * stat.f_frsize;
    std::cout << "usedSpace :" << usedSpace << std::endl;
    std::cout << "storageThreshold :" << storageThreshold << std::endl;
    // 已使用空间尚未达到阈值不做上传处理
    if (usedSpace < storageThreshold) {
      std::cout << "No need to upload logs.\n";
    }
  }

}

}// namespace get_dir_store

#endif //LINUX_SYSTEM_LOAD_TEST_GET_DIR_STORE_H

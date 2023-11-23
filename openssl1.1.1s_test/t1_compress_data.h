//
// Created by shecannotsee on 23-11-23.
//

#ifndef T1_COMPRESS_DATA_H
#define T1_COMPRESS_DATA_H

#include <zip.h>
#include <zlib.h>

#include <cstring>
#include <fstream>
#include <iostream>

namespace t1_compress_data {

bool zip_file_with_pwd(const std::string& file_name, const std::string& password, const std::string& zip_file_path) {
  zipFile zip_file = zipOpen(zip_file_path.c_str(), APPEND_STATUS_CREATE);
  if (zip_file == nullptr) {
    std::cerr << "Failed to open zip file: " << zip_file_path << std::endl;
    return false;
  }

  zip_fileinfo zip_file_info;
  memset(&zip_file_info, 0, sizeof(zip_fileinfo));

  if (zipOpenNewFileInZip3_64(zip_file, file_name.c_str(), &zip_file_info, nullptr, 0, nullptr, 0, nullptr, Z_DEFLATED,
                              Z_DEFAULT_COMPRESSION, 0, -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, password.c_str(),
                              0, 0) != ZIP_OK) {
    std::cerr << "Failed to open file in zip with password" << std::endl;
    zipClose(zip_file, nullptr);
    return false;
  }

  std::ifstream input_file(file_name, std::ios::binary);
  if (!input_file.is_open()) {
    std::cerr << "Failed to open input file: " << file_name << std::endl;
    zipClose(zip_file, nullptr);
    return false;
  }

  const int buffer_size = 4096;
  char buffer[buffer_size];

  while (input_file.good()) {
    input_file.read(buffer, buffer_size);
    zipWriteInFileInZip(zip_file, buffer, static_cast<unsigned int>(input_file.gcount()));
  }

  input_file.close();
  zipCloseFileInZip(zip_file);

  zipClose(zip_file, nullptr);
  return true;
}

void main() {
  std::string file_name     = "test_file.txt";
  std::string password      = "789";
  std::string zip_file_path = "../x.zip";

  if (!zip_file_with_pwd(file_name, password, zip_file_path)) {
    std::cout << "failed.\n";
  } else {
    std::cout << "success.\n";
  }
}

}  // namespace t1_compress_data

#endif  // T1_COMPRESS_DATA_H

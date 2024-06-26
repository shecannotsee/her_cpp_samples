#ifndef T1_FILESYSTEM_H
#define T1_FILESYSTEM_H

#include <filesystem>
#include <fstream>
#include <iostream>

namespace t1_filesystem {

inline void run() {
  std::cout << "t1_filesystem start---------------------------------------------------------------------------------\n";

  const std::string path      = "example_directory";
  const std::string file_name = "example.txt";

  // 查看当前路径
  std::string current_path = std::filesystem::current_path();
  std::cout << "[0]当前路径为 " << std::filesystem::current_path() << '\n';
  // 设置当前路径
  std::filesystem::current_path(std::filesystem::temp_directory_path());
  std::cout << "[0]设置后当前路径为 " << std::filesystem::current_path() << '\n';
  std::filesystem::current_path(current_path);
  std::cout << "[0]设置后当前路径为 " << std::filesystem::current_path() << '\n';


  // 创建目录
  if (!std::filesystem::exists(path)) {
    std::filesystem::create_directory(path);
    std::cout << "[1]Directory created: " << path << std::endl;
  }

  // 创建文件
  {
    std::ofstream file(path + "/" + file_name);
    file << "Hello, World!" << std::endl;
    file.close();
  }

  // 检查文件是否存在
  if (std::filesystem::exists(path + "/"+file_name)) {
    std::cout << "[2]File exists!" << std::endl;
  } else {
    std::cout << "[2]File does not exist!" << std::endl;
  }

  // 获取文件大小
  const auto size = std::filesystem::file_size(path + "/"+file_name);
  std::cout << "[3]File size: " << size << " bytes" << std::endl;

  // 遍历目录
  {
    // 创建文件
    {
      std::ofstream file(path + "/" + file_name+"1");
      file << "Hello, World!" << std::endl;
      file.close();
    }
  }
  for (const auto& entry : std::filesystem::directory_iterator(path)) {
    std::cout << "[4]Directory entry: " << entry.path() << std::endl;
  }

  // 删除文件和目录
  std::filesystem::remove(path + "/"+file_name);
  std::filesystem::remove_all(path);
  std::cout << "[5]Directory and file deleted." << std::endl;

  std::cout << "t1_filesystem done\n";
}

}  // namespace t1_filesystem

#endif  // T1_FILESYSTEM_H

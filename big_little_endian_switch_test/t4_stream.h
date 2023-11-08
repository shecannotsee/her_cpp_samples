//
// Created by shecannotsee on 23-11-7.
//

#ifndef BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H
#define BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H

#include <string>

namespace t4_stream {

void main() {
  {
    std::string headerBuffer_ = {0x19,
                          0x00,0x07,
                          0x00,0x00,
                          0x00,
                          0x01};
    std::string headerBuffer_char = {
      'H',
      'P','P',
      'W','W',
      'C',
      'V'
    };
    constexpr int PacketLengthOffset = 1;
    constexpr int PacketLengthBytesLength = 2;
    uint16_t PacketLength;
    std::string temp(headerBuffer_char.begin() + PacketLengthOffset,
                     headerBuffer_char.begin() + PacketLengthOffset + PacketLengthBytesLength);
    PacketLength = (static_cast<std::uint16_t>(headerBuffer_[1]) << 8) |
                   (static_cast<std::uint16_t>(headerBuffer_[2]) << 0);
    std::cout << "[[[[[[[[[[[]]]]]]char:" << temp << std::endl;
    std::cout << "[[[[[[[[[[[]]]]]]uint:" << PacketLength << std::endl;

  }

  std::string _1;
  std::string _2;
  {
    std::string a = "1234567890";

    auto x1 = [&]() -> std::string {
      return std::string(a.begin() + 0, a.begin() + 1);
    }();// "34"
    _1 = std::move(x1);

    auto x2 = [&]() -> std::string {
      return std::string(a.begin() + 1, a.begin() + 2);
    }();// "34"
    _2 = std::move(x2);

    auto x3 = [&]() -> std::string {
      return "1" + std::string(a.begin() + 2, a.begin() + 3);
    }();// "34"
    _2 = std::move(x3);
  }
  _1;
  _2;

  {
    // 流测试代码
    std::string data = "0123456789";
    std::string buffer_;
    {
      auto processBuffer = [](const std::string& data, int offset) -> int {
        int tail = -1;
        if(data.size() >= 3) { // 根据文档,长度在23字节,当流数据长度大于3的时候方可正确获取长度
          // 包长度
          std::uint16_t length;
          length = (static_cast<std::uint16_t>(data[0]) << 8) |
                   (static_cast<std::uint16_t>(data[1]) << 0);
          length = 1;
          if ((length+offset) <= data.size()) { // 当且仅当流长度大于等于流中所描述的包长度时,返回正确的流尾部偏移
            tail = offset+length;
          }
        }
        return tail;
      };
      auto msgCallBack_ = [](const std::string& data){
        std::cout << data << std::endl;
      };
      int start = 0;
      int tail = 0;
      // 使用while来处理多条完整包的情况
      while (tail != -1) {
        // 缓存buffer没数据表示之前的数据已经处理完毕,只需要对接收的data做处理
        if (buffer_.size() == 0) {
          tail = processBuffer(data, start);
          if (tail != -1) {
            msgCallBack_(
              std::string(data.begin() + start, data.begin() + tail));
            start = tail;
          } else {
            buffer_ = std::string(data);
          }
        }
        // 需要对buffer_ + data 做处理
        else {
          buffer_ += std::string(data);
          tail = processBuffer(buffer_, start);
          if (tail != -1) {
            msgCallBack_(
              std::string(buffer_.begin() + start, buffer_.begin() + tail));
            start = tail;
          } else {
            buffer_ = std::string(data);
          }
        }
      }
    }
  }



}

}// namespace t4_stream

#endif //BIG_LITTLE_ENDIAN_SWITCH_TEST_T4_STREAM_H

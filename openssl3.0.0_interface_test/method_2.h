//
// Created by shecannotsee on 2022/12/27.
//

#ifndef OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_2_H_
#define OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_2_H_

#include <string.h>

#include <iostream>
#include <string>

#include <openssl/evp.h>

namespace method_2 {

void main() {
  const unsigned char data[] = "shecannotsee"; // len = 12字节
  const unsigned char iv[]   = "1234567890123456";// 4字节,128位
  const unsigned char key[]  = "shecannotseeZZZZ";// 密码,4字节,128位

  unsigned char mid_data[] = "shecannotsee";
  /* 加密 */ {
    int ret = -1;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, // 指向密码上下文的指针，在调用该函数时必须已经分配了内存空间
                      EVP_aes_128_cbc(), // 指向加解密算法的指针，用于指定要使用的算法
                      NULL, // 可以添加自己实现的加密解密算法
                      key, // 指向密钥的指针，用于指定加解密使用的密钥。
                      iv, // 指向初始化向量的指针，用于指定加解密使用的初始化向量
                      AES_ENCRYPT // 布尔类型的变量，用于指定当前的操作是加密还是解密。如果为真，则表示执行加密操作；如果为假，则表示执行解密操作
                      );
    int temp = -1;
    EVP_CipherUpdate(ctx, // 指向密码上下文的指针，在调用该函数时必须已经分配了内存空间
                     mid_data, // 指向加解密后的数据的缓冲区的指针，该函数会将加解密后的数据存储到这个缓冲区中
                     &temp, // 指向一个整型变量的指针，用于存储加解密后的数据的长度
                     data, // 指向要加解密的数据的缓冲区的指针，该函数会从这个缓冲区中读取要加解密的数据
                     12 // 要加解密的数据的长度，以字节为单位
                     );
    std::cout<<"\"shecannotsee\"输出的数据长度为["<<temp<<"]"<<std::endl;

    EVP_CipherFinal(ctx, // 指向密码上下文的指针，在调用该函数时必须已经初始化了密码上下文
                    mid_data, //指向加解密后的数据的缓冲区的指针，该函数会将加解密后的数据存储到这个缓冲区中
                    &temp // 指向一个整型变量的指针，用于存储加解密后的数据的长度
                    );
    std::cout<<"\"shecannotsee\"输出的数据长度为["<<temp<<"]"<<std::endl;
    EVP_CIPHER_CTX_free(ctx);
  };


  /* 解密 */ {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx,
                      EVP_aes_128_cbc(),
                      NULL,
                      key,
                      iv,
                      AES_DECRYPT);

  };

};

};// namespace method_2

#endif //OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_2_H_

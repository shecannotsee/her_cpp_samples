//
// Created by shecannotsee on 2022/12/28.
//

#ifndef OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_3_H_
#define OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_3_H_

#include <openssl/evp.h>

namespace method_3 {

void main() {
  // 要加密的数据
  unsigned char data[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // 密钥
  unsigned char key[] = "1234567890123456";
  // 初始向量 (IV)
  unsigned char iv[] = "1234567890123456";

  // 初始化加密上下文
  EVP_CIPHER_CTX *ctx;
  ctx = EVP_CIPHER_CTX_new();
  // 设置加密模式为 AES-CBC 128
  EVP_EncryptInit(ctx, EVP_aes_128_cbc(), key, iv);

  // 输出缓冲区
  unsigned char out[1024];
  int outl;

  // 加密第一块数据
  EVP_EncryptUpdate(ctx, out, &outl, data, 10);

  // 加密第二块数据
  EVP_EncryptUpdate(ctx, out, &outl, data + 10, 10);

  // 加密第三块数据
  EVP_EncryptUpdate(ctx, out, &outl, data + 20, 6);

  // 完成加密过程
  EVP_EncryptFinal(ctx, out, &outl);

  // 释放加密上下文


};

};// namespace method_3

#endif //OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_3_H_

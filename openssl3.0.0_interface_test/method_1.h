//
// Created by shecannotsee on 2022/12/27.
//

#ifndef OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_1_H_
#define OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_1_H_

#include <iostream>
#include <memory>

#include <openssl/aes.h>
#include <openssl/evp.h>

namespace method_1 {

std::unique_ptr<unsigned char[]> string_to_uchar(std::string str) {
  std::unique_ptr<unsigned char[]> ret = std::make_unique<unsigned char[]>(str.size());
  for (int i=0; i<str.size(); i++) {
    ret[i] = static_cast<unsigned char>(str[i]);
  }
  return ret;
}
std::string uchar_to_string(unsigned char* uchar, int len) {
  std::string ret;
  for (int i=0; i<len; i++) {
    ret += static_cast<char>(uchar[i]);
  }
  return ret;
}

void main() {
  std::string str_key  = "sihan12345612345";
  std::string str_iv   = "1234567890123456";
  std::unique_ptr<unsigned char[]> key  = string_to_uchar(str_key);
  std::unique_ptr<unsigned char[]> iv   = string_to_uchar(str_iv);


  std::string str_data = "123456";//加密用
  std::unique_ptr<unsigned char[]> data = string_to_uchar(str_data);
  std::cout<<"str_data.size() :"<<str_data.size()<<std::endl;
  int data_len = (str_data.size()/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;
  std::cout<<"cal data_len    :"<<data_len<<std::endl;

  std::string mid;//解密用
  /* 加密 */ {
    int len = str_data.size();
    int len_format = (len/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;
    std::cout<<"\nstart encode.\n";
    std::unique_ptr<unsigned char[]> middle_data = std::make_unique<unsigned char[]>(len_format);
    std::cout<<"en_data:["<<uchar_to_string(data.get(),str_data.size())<<"]"<<std::endl;
    int temp = 0;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, key.get(), iv.get(), AES_ENCRYPT);
    EVP_CipherUpdate(ctx, middle_data.get(), &temp, data.get(), str_data.size() );
    std::cout<<"after EVP_CipherUpdate, temp(0->?)  :"<<temp<<std::endl;
    EVP_CipherFinal(ctx, middle_data.get()+temp, &temp);
    std::cout<<"after EVP_CipherFinal,  temp(?->??) :"<<temp<<std::endl;
    EVP_CIPHER_CTX_free(ctx);

    std::string orig = uchar_to_string(middle_data.get(),len_format);
    mid = uchar_to_string(middle_data.get(),len_format);
  };
  /* 解密 */ {
    int len = mid.size();
    int len_format = (len/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;
    std::cout<<"\nstart decode.\n";
    std::unique_ptr<unsigned char[]> de_data = std::make_unique<unsigned char[]>(len_format);
    int temp = 0;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, key.get(), iv.get(), AES_DECRYPT);
    EVP_CipherUpdate(ctx,de_data.get(), &temp, (string_to_uchar(mid)).get(),len_format);
    std::cout<<"after EVP_CipherUpdate, temp(0->?)  :"<<temp<<std::endl;
    EVP_CipherFinal(ctx, de_data.get()+temp, &temp);
    std::cout<<"after EVP_CipherFinal,  temp(?->??) :"<<temp<<std::endl;
    EVP_CIPHER_CTX_free(ctx);
    std::cout<<"de_data :["<<uchar_to_string(de_data.get(),len_format)<<"]"<<std::endl;
  };
}

};// namespace method_1


#endif //OPENSSL_3_0_0_TEST_OPENSSL3_0_0_INTERFACE_TEST_METHOD_1_H_

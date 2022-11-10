//
// Created by shecannotsee on 2022/11/10.
//

#ifndef NLOHMANN_JSON_TEST_OPENSSL_TEST_HEADER_H_
#define NLOHMANN_JSON_TEST_OPENSSL_TEST_HEADER_H_

#include <assert.h>
#include <string.h>
#include <string>
#include <memory>
#include <openssl/aes.h>
#include <openssl/evp.h>

namespace aes_cbc_test1 {

/*
{name: "admin"
password: "admin123."
}
//5F3S4hN/ 4gMV3o1qSCOILDlgoBLEL25PZnZiI7Qak1f1eumHfNbJfKHboueiRW1:
*/
void main() {
  const char* str_KEY = "sihan12345612345\0";
  const char* str_IV  = "1234567890123456\0";
  const char* str_DATA = "{\"name\" : \"admin\",\"password\" : \"admin123\"}\0";
  int len = strlen(str_DATA);
  // 是AES_BLOCK_SIZE的整数倍，需要严格限制
  int data_len = (len/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;

  std::unique_ptr<unsigned char[]> key =  std::make_unique<unsigned char[]>(AES_BLOCK_SIZE); {
    memcpy(key.get(),str_KEY,AES_BLOCK_SIZE);
  }
  std::unique_ptr<unsigned char[]> iv =   std::make_unique<unsigned char[]>(AES_BLOCK_SIZE); {
    memcpy(iv.get(),str_IV,AES_BLOCK_SIZE);
  }
  std::unique_ptr<unsigned char[]> data = std::make_unique<unsigned char[]>(data_len); {
    memcpy(data.get(),str_DATA,len);
  }

  std::cout << "str_DATA :[" << std::hex<< data.get() << "]" << std::endl;
  std::unique_ptr<unsigned char[]> middle_data = std::make_unique<unsigned char[]>(data_len);
  /* 加密 */ {
    AES_KEY en_aes;/* 处理AES_KEY */ {
      assert(AES_set_encrypt_key(key.get(), 128, &en_aes) == 0);
    };
    AES_cbc_encrypt(/*in*/data.get(),/*out*/middle_data.get(),/*len of output*/data_len,&en_aes, iv.get(), AES_ENCRYPT);
    std::cout << "en___str :[" << middle_data.get() << "]" << std::endl;

  }
  /* 解密 */ {
    std::unique_ptr<unsigned char[]> buffer = std::make_unique<unsigned char[]>(data_len);
    AES_KEY de_aes;/* 处理AES_KEY */ {
      assert(AES_set_decrypt_key(key.get(), 128, &de_aes) == 0);
    }
    AES_cbc_encrypt(/*in*/middle_data.get(),/*out*/buffer.get(),/*len of output*/data_len,&de_aes, iv.get(), AES_DECRYPT);
    std::cout << "de___str :[" << std::hex<<buffer.get() << "]" << std::endl;
  }


};

};// namespace aes_cbc_test1

namespace aes_cbc_test2 {
const int MSG_LEN = 128;
//, int olen)可能会设置buf长度
int aes_encrypt(char* in, char* key, char* out,int len) {
  if(!in || !key || !out) return 0;
  unsigned char iv[AES_BLOCK_SIZE];//加密的初始化向量
  for(int i=0; i<AES_BLOCK_SIZE; ++i)//iv一般设置为全0,可以设置其他，但是加密解密要一样就行
    iv[i]=0;
  AES_KEY aes;
  if(AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)
  {
    return 0;
  }
  //int len=strlen(in);//这里的长度是char*in的长度，但是如果in中间包含'\0'字符的话

  //那么就只会加密前面'\0'前面的一段，所以，这个len可以作为参数传进来，记录in的长度

  //至于解密也是一个道理，光以'\0'来判断字符串长度，确有不妥，后面都是一个道理。
  AES_cbc_encrypt((unsigned char*)in, (unsigned char*)out, len, &aes, iv, AES_ENCRYPT);
  return 1;
}
int aes_decrypt(char* in, char* key, char* out,int len) {
  if(!in || !key || !out) return 0;
  unsigned char iv[AES_BLOCK_SIZE];//加密的初始化向量
  for(int i=0; i<AES_BLOCK_SIZE; ++i)//iv一般设置为全0,可以设置其他，但是加密解密要一样就行
    iv[i]=0;
  AES_KEY aes;
  if(AES_set_decrypt_key((unsigned char*)key, 128, &aes) < 0)
  {
    return 0;
  }
  //   int len=strlen(in);
  AES_cbc_encrypt((unsigned char*)in, (unsigned char*)out, len, &aes, iv, AES_DECRYPT);
  return 1;
}
void main() {
  char sourceStringTemp[MSG_LEN];
  char dstStringTemp[MSG_LEN];
  memset((char*)sourceStringTemp, 0 ,MSG_LEN);
  memset((char*)dstStringTemp, 0 ,MSG_LEN);
  strcpy((char*)sourceStringTemp, "123456789 123456789 123456789 12a");
  //strcpy((char*)sourceStringTemp, argv[1]);

  char key[AES_BLOCK_SIZE];
  int i;
  for(i = 0; i < 16; i++)//可自由设置密钥
  {
    key[i] = 32 + i;
  }
  int sour_len = strlen((char*)sourceStringTemp);
  if(!aes_encrypt(sourceStringTemp,key,dstStringTemp,MSG_LEN))
  {
    printf("encrypt error\n");
    return ;
  }
  printf("enc %d:",strlen((char*)dstStringTemp));
  for(i= 0;dstStringTemp[i];i+=1){
    printf("%x",(unsigned char)dstStringTemp[i]);
  }
  memset((char*)sourceStringTemp, 0 ,MSG_LEN);
  if(!aes_decrypt(dstStringTemp,key,sourceStringTemp,MSG_LEN))
  {
    printf("decrypt error\n");
    return ;
  }
  printf("\n");
  printf("dec %d:",strlen((char*)sourceStringTemp));
  printf("%s\n",sourceStringTemp);
  for(i= 0;i < sour_len;i+=1){
    printf("%x",(unsigned char)sourceStringTemp[i]);
  }
  printf("\n");
}

};// namespace aes_cbc_test2

namespace aes_cbc_test3 {
void main() {
  // key的长度对应算法的选用
  // 例如EVP_aes_128_cbc()对应的key[16],而EVP_aes_256_cbc()对应的key[32]
  unsigned char key[16] = {1};
  unsigned char iv[16] = {0};
  const char* temp = "this is test string";
  unsigned char *inStr = new unsigned char[strlen(temp)];
  memcpy(inStr,temp,strlen(temp));
  int inLen = strlen(temp);
  int encLen = 0;
  int outlen = 0;
  unsigned char encData[1024];

  printf("source: %s\n",inStr);

  //加密
  EVP_CIPHER_CTX* ctx;
  ctx = EVP_CIPHER_CTX_new();

  EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv, 1);
  EVP_CipherUpdate(ctx, encData, &outlen, inStr, inLen);
  encLen = outlen;
  EVP_CipherFinal(ctx, encData+outlen, &outlen);
  encLen += outlen;
  EVP_CIPHER_CTX_free(ctx);


  //解密
  int decLen = 0;
  outlen = 0;
  unsigned char decData[1024];
  EVP_CIPHER_CTX *ctx2;
  ctx2 = EVP_CIPHER_CTX_new();
  EVP_CipherInit_ex(ctx2, EVP_aes_128_cbc(), NULL, key, iv, 0);
  EVP_CipherUpdate(ctx2, decData, &outlen, encData, encLen);
  decLen = outlen;
  EVP_CipherFinal(ctx2, decData+outlen, &outlen);
  decLen += outlen;
  EVP_CIPHER_CTX_free(ctx2);

  decData[decLen] = '\0';
  printf("decrypt: %s\n",decData);
};

};// namespace aes_cbc_test3

namespace aes_cbc_test4 {
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
  std::string str_data = "{name: \"admin\"\n"
                         "password: \"admin123.\"\n"
                         "}";
  int data_len = (str_data.size()/AES_BLOCK_SIZE+1)*AES_BLOCK_SIZE;
  std::cout<<"str_data.size() :"<<str_data.size()<<std::endl;
  std::cout<<"cal data_len    :"<<data_len<<std::endl;

  std::unique_ptr<unsigned char[]> key  = string_to_uchar(str_key);//std::make_unique<unsigned char[]>(16);
  std::unique_ptr<unsigned char[]> iv   = string_to_uchar(str_iv);//std::make_unique<unsigned char[]>(16);
  std::unique_ptr<unsigned char[]> data = string_to_uchar(str_data);//std::make_unique<unsigned char[]>(str_data.size());

  std::unique_ptr<unsigned char[]> middle_data = std::make_unique<unsigned char[]>(data_len);
  /* 加密 */ {
    std::cout<<"\nstart encode.\n";
    std::cout<<"en_data:["<<uchar_to_string(data.get(),str_data.size())<<"]"<<std::endl;
    int temp = 0;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, key.get(), iv.get(), AES_ENCRYPT);
    EVP_CipherUpdate(ctx, middle_data.get(), &temp, data.get(), str_data.size() );
    std::cout<<"after EVP_CipherUpdate, temp(0->?)  :"<<temp<<std::endl;
    EVP_CipherFinal(ctx, middle_data.get()+temp, &temp);
    std::cout<<"after EVP_CipherFinal,  temp(?->??) :"<<temp<<std::endl;
    EVP_CIPHER_CTX_free(ctx);
  };
  /* 解密 */ {
    std::cout<<"\nstart decode.\n";
    std::unique_ptr<unsigned char[]> de_data = std::make_unique<unsigned char[]>(data_len);
    int temp = 0;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx, EVP_aes_128_cbc(), NULL, key.get(), iv.get(), AES_DECRYPT);
    EVP_CipherUpdate(ctx,de_data.get(), &temp, middle_data.get(),data_len);
    std::cout<<"after EVP_CipherUpdate, temp(0->?)  :"<<temp<<std::endl;
    EVP_CipherFinal(ctx, de_data.get()+temp, &temp);
    std::cout<<"after EVP_CipherFinal,  temp(?->??) :"<<temp<<std::endl;
    EVP_CIPHER_CTX_free(ctx);
    std::cout<<"de_data :["<<uchar_to_string(de_data.get(),data_len)<<"]"<<std::endl;
  };
}
};// namespace aes_cbc_test4

#endif //NLOHMANN_JSON_TEST_OPENSSL_TEST_HEADER_H_

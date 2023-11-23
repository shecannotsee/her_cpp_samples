**Dependent projects:**

(1)openssl-OpenSSL_1_1_1s

(2)zlib-1.2.8

(3)minizip-ng-3.0.9



**The directory structure of the project**

```bash
$ tree -L 1
.
├── libraries
└── sheTestcode

$ tree ./libraries/openssl-OpenSSL_1_1_1s/ ./libraries/zlib-1.2.8/ ./libraries/minizip-ng-3.0.9/ -L 1
./libraries/openssl-OpenSSL_1_1_1s/
├── bin
├── include
├── lib
├── share
└── ssl
./libraries/zlib-1.2.8/
├── include
├── lib
└── share
./libraries/minizip-ng-3.0.9/
├── include
└── lib

10 directories, 0 files

$ tree ./sheTestcode/openssl1.1.1s_test/ -L 1
./sheTestcode/openssl1.1.1s_test/
├── cmake-build-debug
├── CMakeLists.txt
├── main.cpp
├── README.md
├── single_test_file.txt
├── t1_compress_data.h
├── t2_decompress_data.h
├── temp
└── test_dir

3 directories, 6 files
```




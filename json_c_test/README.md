where is json-c?

```bash
-> pwd
${path}/sheTestcode
-> cd ..
-> cd libraries/
-> ls
json-c
-> cd openssl-3.0.0
-> ls
include  lib
```
And you can use this CMakeLists.txt now.



g++ main.cpp -o main 
-I/usr/local/include/glog \
-L/usr/local/lib \
-lglog
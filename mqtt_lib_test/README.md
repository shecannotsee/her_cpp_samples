1.where is mqtt library?

```bash
-> pwd
${path}/sheTestcode
-> cd ..
-> cd libraries/
-> ls
paho.mqtt.c-1.3.10 ...
-> cd paho.mqtt.c-1.3.10
-> ls
bin  include  lib  share
-> cd ..
-> ls
paho.mqtt.cpp-1.2.0 ...
-> cd paho.mqtt.cpp-1.2.0
-> ls
include lib
```
tips:If you want to use the c++interface of the library, be sure to generate its static library when compiling paho.mqtt.c

And you can use this CMakeLists.txt now.


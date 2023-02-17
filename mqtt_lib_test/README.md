1.where is jwt-cpp?

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
```
tips:If you want to use the c++interface of the library, be sure to generate its static library when compiling paho.mqtt.c

And you can use this CMakeLists.txt now.


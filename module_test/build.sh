#!/bin/bash
# Generate Folder ./gcm.cache
g++ -std=c++20 -fmodules-ts -c display.cpp
g++ -std=c++20 -fmodules-ts display.o main.cpp -o module_test
./module_test
rm -rf ./display.o ./gcm.cache ./module_test
#!/bin/bash

# install python c api
sudo apt-get install python3-dev

# get lib
git clone https://github.com/pybind/pybind11.git
git checkout v2.11

mv pybind11 pybind11-src
mkdir pybind11

# build lib
cd pybind11-src
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../../pybind11 ..
make -j8
make install

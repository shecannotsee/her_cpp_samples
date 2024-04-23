#### 1.build benchmark

build_dependency.sh

```bash
$ git clone https://github.com/google/benchmark.git
$ mv benchmark benchmark_src
$ mkdir benchmark
$ cd benchmark_src/
$ git checkout v1.8.3
$ mkdir build
$ cd build
$ cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../benchmark ..
$ make -j8
$ make install
$ cd ..
$ cd ..
$ rm -rf ./benchmark_src/
```



where is benchmark?

```bash
-> pwd
${path}/sheTestcode
-> cd ..
-> cd libraries/
-> ls
benchmark-1.7.0
-> cd benchmark-1.7.0
-> ls
include lib ...
```

And you can use this CMakeLists.txt now.


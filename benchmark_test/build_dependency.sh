git clone https://github.com/google/benchmark.git
mv benchmark benchmark_src
mkdir benchmark
cd benchmark_src/
git checkout v1.8.3
mkdir build
cd build
cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -CMAKE_INSTALL_PREFIX=../../benchmark ..
make -j8
make install

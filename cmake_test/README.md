#### 这是什么？

这是一个基于源码自动构建依赖库然后将库集成到项目中的案例

在该案例中， ./third_party 中有glog的源代码，可以在 ./third_party 下通过 git clone https://github.com/google/glog.git 获取

接下来就是在获取到源码后如何构建的问题

在目录./下

```bash
mkdir build
cd build
cmake ..
make
```

之后会看到glog在make的时候会优先于cmake_test构建出来，然后在构建cmake_test的时候加入到构建依赖中，完成项目的构建



#### What is this?

This is a case study of automatically building dependency libraries based on source code and integrating them into a project.

In this case, You can use [ git clone https://github.com/google/glog.git ] to get the source code.

The next question is how to build after obtaining the source code

In the directory ./

```bash
mkdir build
cd build
cmake ..
make
```

Later on, you will see that glog takes precedence over cmake when making_ Build the test and then build the cmake_ Add build dependencies during the test to complete the project's construction

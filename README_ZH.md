#### (1)a_demo

一般的项目结构示例，里面还有一些过时的 cmake 示例。



#### (2)asio_test

asio 库的测试用例，仅测试了一些简单定时器的代码， tcp 服务因为 ip 不会填写尚未完成



#### (3)benchmark_test

google 的 benchmark 库测试用例，主要用来处理一些性能测试，只搭建了测试结构以及最简单的函数性能测试



#### (4)big_little_endian_switch_test

主要是用来测试大小端转换的代码

t1 主要检查本机的大小端

t2 主要用来处理大小端的转换，其实更多的时候是在处理本机大小端和网络序列（大端）的转换



#### (5)buffer_design_test

主要用来测试设计的流数据的组包与拆包，但是代码有 bug ，尚未修复完成



#### (6)cmake_test

一些 cmake 用法的案例，主要是想通过 cmake 支持的语法，来通过 cmake 构建第三方库，主要就是 cmake 中`FetchContent_Declare` 和 `ExternalProject_Add` 的使用



#### (7)common_algorithm

一些常用算法的测试代码，主要写的是雪花算法的示例



#### (8)cpp20_coroutine_test

用来测试 c++20 协程语法的使用

m1 好像是 cppreference 的示例

m2 也是一个简单的协程示例



#### (9)cross_platform_test

主要用来写一些跨平台宏，还有编译器宏的测试代码



#### (10)dynamic_programming _test

动态规划的示例代码

t1 是使用指定面值钞票组成指定金额的代码示例，docs里也有对于该例子的手写笔记



#### (11)float32_bytes_view_test

主要用于查看浮点数每个 bit 的值，以便于更好的观察和处理浮点数



#### (12)fltk1.3.7_test

fltk1.3.7 库使用的测试代码

m1 就是显示窗口和按钮然后处理相关的事件

m2 在窗口里实现了一个输入和回显框，通过按钮将输入框的数据在回显框中进行展示

m3 是一个表格代码，是从 fltk 库里的示例代码里改过来的

m4 是通过 fltk 显示指定窗口的代码



#### (13)googletest_test

google 的 cpp 测试库的使用示例代码

head 里面代码展现了如何使用 gtest 来编写测试代码

m2 里面有一个使用 gmock 的例子



#### (14)hash_function

展示了一些常用的hash函数



#### (15)huffman_coding

huffman 编码（哈弗曼编码），因为没有二叉树的数据结构所以还没完成

test1 试图使用 hash table 来实现二叉树，但是也还没完全实现



#### (16)json_c_test

json-c 库的使用例子



#### (17)jsoncpp_test

jsoncpp1.9.5 库的使用例子



#### (18)jwt-cpp_test

jwt-cpp 库的使用示例，主要用来处理 token 相关内容



#### (19)linux_system_load_test

linux 系统下，获取 cpu 内存的使用情况示例代码



#### (20)linux_timer_test

linux 系统下定时器的使用



#### (21)map_replace_ifelse_test

使用 map 代替 大量 ifelse 的示例代码

m1 是常规的 ifelse 代码

m2 是试图用 map 去代替的代码。但是目前没什么好的头绪，所以尚未实现



#### (22)memory_share_test

linux 系统下多进程来通过共享内存传递信息的示例代码



#### (23)mini_docker

使用 c 实现的一个很小的 docker ，实际上是隔绝了 os 的轻量级容器



#### (24)mqtt_lib_test

mqtt 库的使用示例，主要是 paho.mqtt.c 和 paho.mqtt.cpp 这两个库

m1 是同步推送代码

m2 是异步订阅代码

m3 是异步推送代码

m4 是异步推送代码

m5 是异步订阅代码

m6 是一些接口定义，但是里面什么代码也没有

m7 是带有 ssl 的异步推送代码

m8 是带有 ssl 的异步订阅代码

m9 是 c++ 的订阅代码

m10 是 c++ 的带有 ssl 的推送代码

m11 是 c++ 的推送代码

m12 是 c++ 的订阅和推送代码



#### (25)my_bloom_filter_test

布隆过滤器以及相关位图的实现以及测试用例代码

t1 是位图调用测试代码

t2 是布隆过滤器的调用测试代码



#### (26)nlohmann_json_test

nlohmann json 库的使用示例

该使用用例较为详细，基本包含了所有使用细节



#### (27)only_c_project

纯 c 语言的项目构建示例



#### (28)openssl3.0.0_interface_test

openssl3.0.0 的使用示例代码，但是大多数可以在 1.1.0 版本使用

aes cbc 128 是 aes 128 的示例代码

m1 是使用 aes  的加密解密流程

m2 是使用 aes  的加密解密流程

m3 是 aes 加解密流程，但是有 bug ，尚未修复，无法运行

m4 是 rsa 使用用例，里面有代码参考链接



#### (29)prorobuf_test

protobuf 的使用用例代码。定 protobuf 协议，然后通过 protobuf 来序列化，反序列化的示例代码



#### (30)qt5.12_test

qt5.12 库的使用代码

m1 是产生窗口以及处理中文显示的示例代码



#### (31)random_test

随机数测试代码

m1 线性同余发生器的实现和测试代码



#### (32)real_time_thread_test

linux 系统下使用 pthread 来处理线程优先级的示例代码，想让线程获得高优先级运行，也就是实时运行的示例代码



#### (33)rsa_test

rsa 加密解密原理测试代码。通过 python3 来处理的大数运算，其他代码均为 c++ 实现。还贴心的附上了一个加解密的时间记录，被 openssl 爆 1000% 还要更多了（而且这还是在素数取的很小的情况下）



#### (34)simple_seb_server_test

simple-web-server 库的使用用例代码，构建一个简单的 web 服务器



#### (35)spdlog_test

spdlog 库的使用用例代码。一些写日志的代码



#### (36)sqlite3_test

sqlite3 库的使用用例代码，用来做查询等操作



#### (37)sqlite_orm_test

sqlite_orm 库的使用用例代码，主要封装了 sqlite3 的表操作，数据库操作等



#### (38)STL_test

一些 stl 库的性质示例代码

#### (39)t_m_test

模板元编程测试代码。该项目有一个编译器计算的示例



#### (40)Template_Metaprogramming_test

模板元编程测试代码。

m1 见代码和注释

m2 见代码和注释

m3 主要写了一个处理参数包的示例



#### (41)TestWindows.h

一些在 windows 操作系统上实现的模拟键盘和鼠标的操作



#### (42)url_map_test

用来处理 web 请求接口注册的map实现示例。主要封装了 set 和 get 方法



#### (43)use_compiler_to_decltype

使用编译器来推到类型的示例代码


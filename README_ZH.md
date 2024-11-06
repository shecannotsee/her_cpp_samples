#### (1)big_little_endian_switch_test

主要是用来测试大小端转换的代码

- t1 主要检查本机的大小端
- t2 主要用来处理大小端的转换，其实更多的时候是在处理本机大小端和网络序列（大端）的转换
- t3 主要用来处理流数据的大小端转换
- t4 类似t3



#### (2)buffer_design_test

主要用来测试设计的流数据的组包与拆包，但是代码有 bug ，尚未修复完成



#### (3)cmake_test

一些 cmake 用法的案例，主要是想通过 cmake 支持的语法，来通过 cmake 构建第三方库，主要就是 cmake 中`FetchContent_Declare` 和 `ExternalProject_Add` 的使用



#### (4)common_algorithm

一些常用算法的测试代码，主要写的是雪花算法的示例



#### (5)coroutines_in_c
c的协程代码



#### (6)coroutines_test

c++20 的协程代码测试

- t1 是一个最小的，简易的协程测试
- t2 是一个泄漏的协程序测试
- t3 是一个较为复杂的但是较为完整的协程代码测试
- t4 是一个可以参考并且修改后进行使用的协程 demo



#### (7)cpp17_test

c++17 一些新特性的使用示例

- t1 是 filesystem 的使用用例
- t2 是 optional 的使用用例
- t3 是 variant 的使用用例
- t4 是 std::byte 的使用用例
- t5 是结构化绑定的使用用例
- t6 是初始化 if 的使用用例
- t7 是属性的使用用例



#### (8)cpp20_coroutine_test

用来测试 c++20 协程语法的使用

- m1 是 cppreference 的示例


- m2 是一个简单的协程示例



#### (9)cpp20_test

c++20 一些新特性的使用示例

- ti 是 concept 的使用用例
- t2 是 requires 的使用用例
- t3 是宇宙飞船运算符的使用用例
- t4 是 jthread 的使用用例
- t5 是时区的使用用例
- t6 是大小端的使用用例
- t7 是 source_location 的使用用例 




#### (10)cross_platform_test

主要用来写一些跨平台宏，还有编译器宏的测试代码



#### (11)dynamic_programming _test

动态规划的示例代码

- t1 是使用指定面值钞票组成指定金额的代码示例，docs里也有对于该例子的手写笔记




#### (12)float32_bytes_view_test

主要用于查看浮点数每个 bit 的值，以便于更好的观察和处理浮点数



#### (13)hash_function

展示了一些常用的hash函数



#### (15)huffman_coding

huffman 编码（哈弗曼编码），因为没有二叉树的数据结构所以还没完成

- test1 试图使用 hash table 来实现二叉树，但是也还没完全实现




#### (16)linux_system_load_test

linux 系统下一些系统接口的使用用例



#### (17)linux_timer_test

linux 系统下定时器的使用



#### (18)map_replace_ifelse_test

使用 map 代替 大量 ifelse 的示例代码

- m1 是常规的 ifelse 代码
- m2 是试图用 map 去代替的代码。但是目前没什么好的头绪，所以尚未实现



#### (19)memory_share_test

linux 系统下多进程来通过共享内存传递信息的示例代码



#### (20)mini_docker

使用 c 实现的一个很小的 docker ，实际上是隔绝了 os 的轻量级容器



#### (21)module_test

c++20 module在各种编译器下的使用，可以参考目录里的 README.MD 文档



#### (22)my_bloom_filter_test

布隆过滤器以及相关位图的实现以及测试用例代码

- t1 是位图调用测试代码
- t2 是布隆过滤器的调用测试代码




#### (23)only_c_project

纯 c 语言的项目构建示例



#### (24)random_test

随机数测试代码

- m1 线性同余发生器的实现和测试代码




#### (25)real_time_thread_test

linux 系统下使用 pthread 来处理线程优先级的示例代码，想让线程获得高优先级运行，也就是实时运行的示例代码



#### (26)rsa_test

rsa 加密解密原理测试代码。通过 python3 来处理的大数运算，其他代码均为 c++ 实现。还贴心的附上了一个加解密的时间记录，被 openssl 爆 1000% 还要更多了（而且这还是在素数取的很小的情况下）



#### (27)semantic_test

c++ 的语义测试

- t1 主要用来处理类的移动与构造的示例



#### (28)she_test_lib_support

测试框架的一些功能尝试




#### (29)STL_test

一些 stl 库的性质示例代码



#### (30)t_m_test

模板元编程测试代码。

- t1 是一个编译期计算的示例



#### (31)Template_Metaprogramming_test

模板元编程测试代码。

- m1 见代码和注释
- m2 见代码和注释
- m3 主要写了一个处理参数包的示例
- t4 是不依赖头文件的一些类型处理的原始实现



#### (32)TestWindows.h

一些在 windows 操作系统上实现的模拟键盘和鼠标的操作



#### (33)url_map_test

用来处理 web 请求接口注册的map实现示例。主要封装了 set 和 get 方法



#### (34)use_compiler_to_decltype

使用编译器来推到类型的示例代码


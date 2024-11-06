#### (1) big_little_endian_switch_test

Mainly used to test byte order conversion code.

- t1 primarily checks the local machine's byte order.
- t2 is mainly used for byte order conversion, often handling conversion between the local machine's byte order and network byte order (big-endian).
- t3 is mainly for handling byte order conversion of streaming data.
- t4 is similar to t3.

#### (2) buffer_design_test

Used to test the design of stream data packaging and unpacking. The code contains bugs that have not been fixed yet.

#### (3) cmake_test

Examples of CMake usage, primarily aimed at building third-party libraries via CMake's supported syntax, especially using `FetchContent_Declare` and `ExternalProject_Add`.

#### (4) common_algorithm

Test code for commonly used algorithms, mainly focusing on an example of the Snowflake algorithm.

#### (5) coroutines_in_c

Coroutine code in C.

#### (6) coroutines_test

C++20 coroutine test code.

- t1 is a minimal, simple coroutine test.
- t2 is a coroutine test with leaks.
- t3 is a more complex but complete coroutine test.
- t4 is a coroutine demo that can be referenced and modified for use.

#### (7) cpp17_test

Examples of new features in C++17.

- t1 is a use case for the filesystem library.
- t2 is a use case for optional.
- t3 is a use case for variant.
- t4 is a use case for std::byte.
- t5 is a use case for structured bindings.
- t6 is a use case for if-initialization.
- t7 is a use case for attributes.

#### (8) cpp20_coroutine_test

Used to test C++20 coroutine syntax.

- m1 is an example from cppreference.
- m2 is a simple coroutine example.

#### (9) cpp20_test

Examples of new features in C++20.

- t1 is a use case for concepts.
- t2 is a use case for requires.
- t3 is a use case for the spaceship operator.
- t4 is a use case for jthread.
- t5 is a use case for time zones.
- t6 is a use case for byte order.
- t7 is a use case for source_location.

#### (10) cross_platform_test

Mainly used for writing cross-platform macros and testing compiler macros.

#### (11) dynamic_programming_test

Examples of dynamic programming.

- t1 is an example of using specified denominations of bills to form a target amount, with handwritten notes in the docs.

#### (12) float32_bytes_view_test

Used to view the bit values of a floating-point number for better observation and handling.

#### (13) hash_function

Demonstrates several commonly used hash functions.

#### (15) huffman_coding

Huffman coding. This is incomplete because there is no binary tree data structure yet.

- test1 attempts to use a hash table to implement a binary tree, but it is not fully implemented.

#### (16) linux_system_load_test

Examples of system interface usage on Linux.

#### (17) linux_timer_test

Examples of timer usage on Linux.

#### (18) map_replace_ifelse_test

Examples of using a map to replace extensive if-else statements.

- m1 is the standard if-else code.
- m2 attempts to replace it using a map, but there is no good solution yet, so it's not fully implemented.

#### (19) memory_share_test

Example code for inter-process communication using shared memory on Linux.

#### (20) mini_docker

A small Docker implementation in C, effectively creating a lightweight container that isolates the OS.

#### (21) module_test

Usage of C++20 modules across various compilers. Refer to the README.md in the directory for details.

#### (22) my_bloom_filter_test

Implementation and test cases for Bloom Filters and related bitmaps.

- t1 is a bitmap test case.
- t2 is a Bloom Filter test case.

#### (23) only_c_project

An example of a C language project build.

#### (24) random_test

Random number test code.

- m1 is the implementation and test code for a Linear Congruential Generator.

#### (25) real_time_thread_test

Example code for handling thread priority using pthreads on Linux, to make threads run with high priority in a real-time context.

#### (26) rsa_test

RSA encryption and decryption test code. Big number computations are handled by Python3, with the rest implemented in C++. It also includes timing records for encryption/decryption, which significantly outperformed OpenSSL (even with relatively small primes).

#### (27) semantic_test

C++ semantic testing.

- t1 mainly deals with class move and construction examples.

#### (28) she_test_lib_support

Testing some framework features.

#### (29) STL_test

Examples of STL library properties.

#### (30) t_m_test

Template metaprogramming test code.

- t1 is an example of compile-time computation.

#### (31) Template_Metaprogramming_test

Template metaprogramming test code.

- m1 to m3 are examples with explanations in code and comments.
- t4 is a raw implementation of type handling that does not rely on header files.

#### (32) TestWindows.h

Simulated keyboard and mouse operations on Windows OS.

#### (33) url_map_test

A map implementation for handling web request API registration, mainly encapsulating set and get methods.

#### (34) use_compiler_to_decltype

Examples of using the compiler to deduce types.

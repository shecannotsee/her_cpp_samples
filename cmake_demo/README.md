#### DESCRIBE

Describe an example of how this project demonstrates how to build third-party libraries during project construction using the functionality provided by CMake. The prerequisite is that the source code of a third-party library already exists in the specified directory.

#### HOW TO RUN IT!

```bash
# to get source code
$ pwd
.../cmake_demo
$ mkdir third_party
$ cd third_party
# get source code
$ ../script/get_third_party_src.sh
$ cd ..
# Now you can use this project like other cmake project
$ mkdir build
$ cd build 
$ cmake ..
$ make -j2
......
```

#### TIPS

To be honest, I don't think this approach is a good idea, and I may not pay much attention to this project in the future. I am not very proficient in cmake, so I encountered great difficulties when relying on build. In the future, I will use other methods to build third-party libraries, possibly through scripts but definitely not through cmake.

cmake_minimum_required(VERSION 3.10)

# 显式指定编译器
set(CMAKE_CXX_COMPILER "g++")
 
# 开启调试信息
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
 
# 开启所有警告
set(CMAKE_CXX_FLAGS "-Wall")
# 设置编译模式为DEbug
SET(CMAKE_BUILD_TYPE "Debug")

project(Test)

set(CMAKE_CXX_STANDARD 11)

link_directories(lib)  # 库文件目录

include_directories(include)  #头文件路径
# 添加可执行文件
add_executable(test1 test1.cpp)
target_link_libraries(test1 libleveldb.a -pthread)
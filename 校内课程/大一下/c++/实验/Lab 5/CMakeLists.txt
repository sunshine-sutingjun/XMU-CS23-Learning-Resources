cmake_minimum_required(VERSION 3.10)
project(MyStringProject)

# 添加可执行文件
add_executable(Test Test.cpp MyString.cpp)

# 添加头文件目录
target_include_directories(Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

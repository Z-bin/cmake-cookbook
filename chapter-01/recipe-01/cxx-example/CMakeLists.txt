# 指定CMake需要最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 声明项目的名称，CXX代表C++
project(recipe-01 LANGUAGES CXX)

# 指示CMake创建一个新目标:生成一个可执行文件hello-world,
# 这个文件是通过编译和链接源文件hello-world.cpp生成的
add_executable(hello-world hello-world.cpp)
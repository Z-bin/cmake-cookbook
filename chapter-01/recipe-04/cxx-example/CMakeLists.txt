# 指定CMake需要最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 声明项目的名称，CXX代表C++
project(recipe-04 LANGUAGES CXX)

# 设置一个变量USE_LIBRARY 值为OFF 
set(USE_LIBRARY OFF)

# 输出变量值
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

# BUILD_SHARED_LIBS为全局变量
set(BUILD_SHARED_LIBS OFF)

# 引入变量_sources，包括Message.cpp Message.h
list(APPEND _sources Message.cpp Message.h)

# 如果逻辑为真，则打包成库 
if(USE_LIBRARY)
    add_library(message ${_sources})
    # 指示CMake创建一个新目标:生成一个可执行文件hello-world,
    # 这个文件是通过编译和链接源文件hello-world.cpp生成的
    add_executable(hello-world hello-world.cpp)
    # 将目标库链接到执行目标
    target_link_libraries(hello-world message)
else()
    add_executable(hello-world hello-world.cpp ${_sources})
endif()

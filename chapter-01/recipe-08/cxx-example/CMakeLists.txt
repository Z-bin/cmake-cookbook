# 指定CMake需要最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 声明项目的名称，CXX代表C++
project(recipe-08 LANGUAGES CXX)

# 打印当前编译器标志
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# 为目标准备标志列表
list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")    
endif()

# 生成一个静态库
add_library(geometry
  STATIC
    geometry_circle.cpp
    geometry_circle.h
    geometry_polygon.cpp
    geometry_polygon.h
    geometry_rhombus.cpp
    geometry_rhombus.h
    geometry_square.cpp
    geometry_square.h
 )

# 为静态库设置编译选项
target_compile_options(geometry
  PRIVATE
    ${flags}
 )

# 生成可执行文件
add_executable(compute-areas compute-areas.cpp)

# 为可执行文件设置编译选项
target_compile_options(compute-areas
  PRIVATE
    "-fPIC"
 )

 # 最后将可执行文件链接到静态库
 target_link_libraries(compute-areas geometry)
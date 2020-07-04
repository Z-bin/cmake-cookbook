# 指定CMake需要最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 声明项目的名称，CXX代表C++
project(recipe-09 LANGUAGES CXX)

# 在win上导出所有库符号
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# 为库添加一个目标，将源代码编译成一个动态库
add_library(animals
  SHARED
    Animal.cpp
    Animal.h
    Cat.cpp
    Cat.h
    Dog.cpp
    Dog.h
    Factory.h
)

# 设置了CXX_STANDARD、CXX_EXTENSIONS和CXX_STANDARD_REQUIRED属性。
# 还设置了position_independent ent_code属性，以避免在使用一些编译器构建DSO时出现问题:
set_target_properties(animals
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE 1
)

# 为可执行文件添加新目标
add_executable(animal-farm  animal-farm.cpp)

# 设置animal-farm属性
set_target_properties(
    PROPERTIES
      CXX_STANDARD 14
      CXX_EXTENSIONS OFF
      CXX_STANDARD_REQUIRED ON
)

# 将可执行文件链接到动态库
target_link_libraries(animal-farm animals)
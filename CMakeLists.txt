cmake_minimum_required(VERSION 3.28)
project(parseSQL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#头文件路径
include_directories(E:/CAE/parseSQL/include)
#链接库路径
link_directories(E:/CAE/parseSQL/lib)
#添加可执行文件
add_executable(parseSQL src/main.cpp)
#链接sql-parse库
target_link_libraries(parseSQL sqlparser)

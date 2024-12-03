cmake_minimum_required(VERSION 3.10)
project(HttpServer)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/docker-build)


add_executable(HttpServer HttpServer.cpp FuncA.cpp)
target_link_libraries(HttpServer Boost::boost)


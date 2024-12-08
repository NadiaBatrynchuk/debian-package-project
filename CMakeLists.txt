cmake_minimum_required(VERSION 3.10)
project(HttpServer)

set(CMAKE_CXX_STANDARD 11)

# Додати шлях до Boost вручну
set(BOOST_ROOT "/usr/include/boost")
set(Boost_NO_SYSTEM_PATHS ON)

# Знайти Boost
find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

# Вказати додаткову директорію для вихідного коду
include_directories(${CMAKE_SOURCE_DIR}/docker-build)

# Додати ціль для компіляції
add_executable(HttpServer HttpServer.cpp FuncA.cpp)

# Лінкувати бібліотеку Boost
target_link_libraries(HttpServer Boost::boost)


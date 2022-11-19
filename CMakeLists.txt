cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB CACHE_SRC
        "include/*.hpp"
        "include/*.cpp"
        "include/impl/*.hpp"
        "include/impl/*.cpp"
        )

include_directories(include)
include_directories(include/impl)

add_executable(untitled1 main.cpp ${CACHE_SRC})

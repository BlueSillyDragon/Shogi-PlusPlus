cmake_minimum_required(VERSION 3.31)
project(Shogi++)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shogi++ main.cpp
        shogi.cpp)

target_include_directories(Shogi++ PRIVATE inc)

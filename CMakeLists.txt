cmake_minimum_required(VERSION 3.10)

project(height_map)

add_executable(height_map src/main.cpp src/height_map.cpp)

target_include_directories(height_map PUBLIC include)

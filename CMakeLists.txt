cmake_minimum_required(VERSION 3.12)
project(Dither)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dither main.cpp dither/dither.h dither/dither.cpp dither/helpers.h)

target_link_libraries(Dither -lpng)
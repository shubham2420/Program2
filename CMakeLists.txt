cmake_minimum_required(VERSION 3.9)
project(program2)

set(CMAKE_CXX_STANDARD 14)

# need to load data files from current directory as cpp files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(program2 main.cpp maze.cpp maze.h creature.cpp creature.h)
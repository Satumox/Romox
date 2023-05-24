cmake_minimum_required(VERSION 3.20)

# set project name
project(Romox VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(romox 
    src/main.cpp 
    src/rom-info.cpp)
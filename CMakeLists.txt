cmake_minimum_required(VERSION 3.15)
project(ne_pp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# tells compiler where to find headers
include_directories(include)

# find all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# build executable
add_executable(ne_pp ${SOURCES})
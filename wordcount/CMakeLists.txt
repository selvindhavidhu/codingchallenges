# CMakeList.txt : CMake project for wordcount, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

set(PROJECT_NAME "ccwc")
project ("${PROJECT_NAME}" VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB all_SRCS 
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/*.h")

include(compiler_flags.cmake)

add_executable(${PROJECT_NAME} ${all_SRCS})

enable_testing()
find_package(argparse CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE argparse::argparse)

# Copy the test.txt file from /resources to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)

cmake_minimum_required(VERSION 3.26)


set(CMAKE_CUDA_ARCHITECTURES 75)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)

project(Scions CXX CUDA C)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS False)


# Set target output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/utils.cmake)

add_subdirectory(Scions)
add_subdirectory(examples)
# Add stuff

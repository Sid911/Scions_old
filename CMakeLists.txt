cmake_minimum_required(VERSION 3.26)

#set(CMAKE_CUDA_ARCHITECTURES 75)
#set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Scions CXX C)

include(cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS False)

# Set target output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set common flags
set(COMMON_FLAGS -pedantic -Wshadow -march=native )
message("-- Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

CPMAddPackage("gh:fmtlib/fmt#10.1.1")
# Set different flags for different modes
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(COMMON_FLAGS ${COMMON_FLAGS} -O1 -g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(COMMON_FLAGS ${COMMON_FLAGS} -O3 -flto)
endif()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(${COMMON_FLAGS})
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_compile_options(${COMMON_FLAGS} -stdlib=libc++)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "IntelLLVM")
    # Something is wrong with how this setup is done
    # Just set the entire thing to this if it is intel for now
    set(CMAKE_CXX_FLAGS "-stdlib=libc++ -pedantic -Wshadow -O3 -march=native") # Using icpx as the compiler
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    add_compile_options(${COMMON_FLAGS} "/W4")
else()
    message(FATAL_ERROR "Unsupported compiler. Please use GNU, Clang, IntelLLVM or MSVC.")
endif()

include(cmake/utils.cmake)

add_subdirectory(Scions)
add_subdirectory(examples)
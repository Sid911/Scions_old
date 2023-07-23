cmake_minimum_required(VERSION 3.26)
set(FILES "" )
set(SUBDIRECTORIES "")
set(RELATIVE_PATH include/${PROJECT_NAME}/execution_provider/cuda)


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()

## CMakeLists.txt in execution_providers/cuda folder
#
#project(cuda_execution_provider LANGUAGES CXX CUDA)
#
## List your CUDA source files
#set(cuda_source_files
#        cuda_operations.cu
#        cuda_memory_ops.cu
#        # Add more source files here
#)
#
## Create a library for the CUDA execution provider
#add_library(cuda_execution_provider STATIC ${cuda_source_files})
#
## Add any additional include directories specific to the CUDA provider
#target_include_directories(cuda_execution_provider PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#
## Link any necessary CUDA libraries (e.g., CUDA runtime, cuBLAS, cuDNN, etc.)
#target_link_libraries(cuda_execution_provider PUBLIC
#        CUDA::cudart
#        # Add more CUDA libraries here as needed
#)
#
## Set CUDA-specific compile and link flags
#target_compile_options(cuda_execution_provider PRIVATE
#        $<$<COMPILE_LANGUAGE:CUDA>:--gpu-architecture=sm_61> # Example: set the target GPU architecture
#)
#
## Optionally, set the output directory for the CUDA provider library
#set_target_properties(cuda_execution_provider PROPERTIES
#        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib # Adjust the path to your desired output directory
#)
#
## Optionally, you can set any additional properties or compile options specific to the CUDA provider
## For example, if your CUDA code uses C++ features, enable C++11 for the CUDA code:
#set_property(TARGET cuda_execution_provider PROPERTY CUDA_STANDARD 11)
#
## Optionally, you can install the CUDA provider library if needed:
## install(TARGETS cuda_execution_provider ARCHIVE DESTINATION lib)
#
## Optionally, you can install the headers for the CUDA provider if needed:
## install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
#
## Optionally, you can create an alias target for the CUDA provider to simplify linking
#add_library(Scions::cuda_execution_provider ALIAS cuda_execution_provider)


cmake_minimum_required(VERSION 3.26)


set(FILES CUDAExecutionProvider.h CUDAExecutionProvider.cpp)
set(SUBDIRECTORIES "")
set(RELATIVE_PATH include/${PROJECT_NAME}/execution_provider/cuda)


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (FILES)
    target_sources(${PROJECT_NAME}_EPCUDA PRIVATE ${FILES})
    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()

target_link_libraries(${PROJECT_NAME}_EPCUDA PUBLIC
        cudart
        # Add more CUDA libraries here as needed
)

set_target_properties(${PROJECT_NAME}_EPCUDA PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib # Adjust the path to your desired output directory
)

set_property(TARGET ${PROJECT_NAME}_EPCUDA PROPERTY CUDA_STANDARD 23)


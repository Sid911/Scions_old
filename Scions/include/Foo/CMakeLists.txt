set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/library.h")
set(SUBDIRECTORIES "")
set(RELATIVE_PATH "include/Foo")


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()
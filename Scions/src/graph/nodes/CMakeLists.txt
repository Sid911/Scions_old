set(FILES Flatten.cpp Dense.cpp)
set(SUBDIRECTORIES "")
set(RELATIVE_PATH src/${PROJECT_NAME}/graph/nodes)


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()
set(H_FILES Dense.h Flatten.h Node.h NodeTypes.h Relu.h)
set(S_FILES Dense.cpp Flatten.cpp Node.cpp Relu.cpp)
set(SUBDIRECTORIES "")
set(H_RELATIVE_PATH include/${PROJECT_NAME}/core/graph/nodes)

#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (H_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${H_FILES})
    install(FILES ${H_FILES} DESTINATION ${H_RELATIVE_PATH})
#    install(FILES ${S_FILES} DESTINATION ${S_RELATIVE_PATH})
endif ()

if (S_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${S_FILES})
endif ()

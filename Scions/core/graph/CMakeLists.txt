set(H_FILES CompiledGraph.h OpComputeInfo.h SequentialModel.h)
set(S_FILES SequentialModel.cpp)
set(SUBDIRECTORIES memory nodes ops)
set(H_RELATIVE_PATH include/${PROJECT_NAME}/core/graph)

#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (H_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${H_FILES})
    install(FILES ${H_FILES} DESTINATION ${H_RELATIVE_PATH})
endif ()

if (S_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${S_FILES})
endif ()
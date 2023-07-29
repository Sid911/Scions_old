set(H_FILES MemoryRef.h MemoryObject.h)
set(S_FILES MemoryObject.cpp)
set(SUBDIRECTORIES "")
set(H_RELATIVE_PATH include/${PROJECT_NAME}/core/graph/memory)

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

set(H_FILES cpu_ep.h cpu_execution_stats.h mem/cpu_mem_object.h)
set(S_FILES cpu_ep.cpp mem/cpu_mem_object.cpp)
set(SUBDIRECTORIES "")
set(H_RELATIVE_PATH include/${PROJECT_NAME}/ep/cpu)
set(S_RELATIVE_PATH src/${PROJECT_NAME}/ep/cpu)


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (H_FILES)
    # Add source files
    target_sources(${PROJECT_NAME}_CPU PRIVATE ${H_FILES})
    install(FILES ${H_FILES} DESTINATION ${H_RELATIVE_PATH})
endif ()

if (S_FILES)

    target_sources(${PROJECT_NAME}_CPU PRIVATE ${S_FILES})
    install(FILES ${S_FILES} DESTINATION ${S_RELATIVE_PATH})
endif ()

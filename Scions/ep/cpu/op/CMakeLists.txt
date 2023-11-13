set(H_FILES execute_op.h tensor_ops.h)
set(S_FILES tensor_ops.cpp)
set(SUBDIRECTORIES "")
set(H_RELATIVE_PATH include/${PROJECT_NAME}/ep/cpu/op)
set(S_RELATIVE_PATH src/${PROJECT_NAME}/ep/cpu/op)


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

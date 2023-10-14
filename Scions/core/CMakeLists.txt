set(H_FILES "")
set(FILES "" )
set(SUBDIRECTORIES op mem)
set(H_RELATIVE_PATH include/${PROJECT_NAME}/core/)
set(S_RELATIVE_PATH src/${PROJECT_NAME}/core/)


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

    target_sources(${PROJECT_NAME} PRIVATE ${S_FILES})
    install(FILES ${S_FILES} DESTINATION ${S_RELATIVE_PATH})
endif ()
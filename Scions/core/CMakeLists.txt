set(H_FILES "")
set(FILES "" )
set(SUBDIRECTORIES graph tensor)


#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()


if (H_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PRIVATE ${H_FILES})
#    install(FILES ${H_FILES} DESTINATION ${H_RELATIVE_PATH})
#    install(FILES ${S_FILES} DESTINATION ${S_RELATIVE_PATH})
endif ()

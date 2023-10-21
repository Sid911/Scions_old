set(FILES common.h d_type.h progress_bar.h)
set(S_FILES "")
set(SUBDIRECTORIES "")
set(RELATIVE_PATH include/${PROJECT_NAME}/common)

#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()

if (FILES)
    # Add source files
#    target_sources(${PROJECT_NAME} INTERFACE ${FILES})
    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()


if (S_FILES)
    # Add source files
    target_sources(${PROJECT_NAME} PUBLIC ${S_FILES})
endif ()

set(H_FILES OpTypes.h Op.h)
set(S_FILES "")
set(SUBDIRECTORIES "")
set(H_RELATIVE_PATH include/${PROJECT_NAME}/core/graph/ops)

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

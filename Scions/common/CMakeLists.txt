set(FILES common.h result.h)
set(SUBDIRECTORIES "")
set(RELATIVE_PATH include/${PROJECT_NAME}/common)

target_include_directories(${PROJECT_NAME}_Common INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()

if (FILES)
    # Add source files
    target_sources(${PROJECT_NAME}_Common PUBLIC ${FILES})
#    install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif ()

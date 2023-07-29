add_library(${PROJECT_NAME} "")

add_library(${PROJECT_NAME}_Common INTERFACE "")

add_library(${PROJECT_NAME}_EPCUDA STATIC "")
add_library(${PROJECT_NAME}_EPCPU STATIC "")

add_library(Scions::Scions ALIAS ${PROJECT_NAME})
add_library(Scions::CUDA ALIAS ${PROJECT_NAME}_EPCUDA)
add_library(Scions::CPU ALIAS ${PROJECT_NAME}_EPCPU)
add_library(Scions::Common ALIAS ${PROJECT_NAME}_Common)

#set(SCIONS_EXPORT_FILE "Scions-Exports")
#set(SCIONS_COMMON_EXPORT_FILE "Scions-Common-Exports")
#
#install(TARGETS ${PROJECT_NAME}_Common EXPORT ${SCIONS_COMMON_EXPORT_FILE})
#install(TARGETS ${PROJECT_NAME} EXPORT ${SCIONS_EXPORT_FILE})

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>/include/"
        "$<INSTALL_INTERFACE:include>"
)

if (NOT BUILD_SHARED_LIBS)
    set(STATIC_POSTFIX "-s")
    set_target_properties(${PROJECT_NAME} PROPERTIES
    COMPILE_FLAGS -DSCIONS_STATIC_DEFINE)
endif ()

# Rename build targets
set_target_properties(${PROJECT_NAME} PROPERTIES
        DEBUG_POSTFIX "${STATIC_POSTFIX}-d"
        RELEASE_POSTFIX ""
        MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
        RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)
include("GenerateExportHeader")
generate_export_header(${PROJECT_NAME})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/scions_export.h DESTINATION "include")

target_link_libraries(${PROJECT_NAME} PRIVATE Scions::Common)
target_link_libraries(${PROJECT_NAME}_EPCUDA PRIVATE Scions::Common)
target_link_libraries(${PROJECT_NAME}_EPCPU PRIVATE Scions::Common)

#set(SCIONS_CONFIG_DIR "lib/cmake/${PROJECT_NAME}")
#configure_file(${Scions_SOURCE_DIR}/cmake/ScionsConfig.cmake.in ${Scions_BINARY_DIR}/${SCIONS_CONFIG_DIR}/ScionsConfig.cmake)
#install(FILES ${Scions_BINARY_DIR}/${SCIONS_CONFIG_DIR}/ScionsConfig.cmake DESTINATION ${SCIONS_CONFIG_DIR})
#install(EXPORT ${SCIONS_COMMON_EXPORT_FILE} DESTINATION ${SCIONS_CONFIG_DIR} NAMESPACE "Scions::Common")
#install(EXPORT ${SCIONS_EXPORT_FILE} DESTINATION ${SCIONS_CONFIG_DIR} NAMESPACE "Scions::")

add_subdirectory(core)
add_subdirectory(execution_provider)
add_subdirectory(common)


# uninstall target
#if(NOT TARGET uninstall)
#  configure_file(
#    "${Scions_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
#    "${Scions_BINARY_DIR}/cmake_uninstall.cmake"
#    IMMEDIATE @ONLY)
#
#  add_custom_target(uninstall
#    COMMAND ${CMAKE_COMMAND} -P ${Scions_BINARY_DIR}/cmake_uninstall.cmake)
#endif()

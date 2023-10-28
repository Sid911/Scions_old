set(SUBDIRECTORIES cpu common)


add_library(${PROJECT_NAME}_CPU STATIC "")
add_library(${PROJECT_NAME}_EP_COMMON INTERFACE "")
add_library(Scions::CPU ALIAS ${PROJECT_NAME}_CPU)
add_library(Scions::EP_COMMON ALIAS ${PROJECT_NAME}_EP_COMMON)

find_package(MKL CONFIG REQUIRED PATHS $ENV{MKLROOT})
message(STATUS "Imported oneMKL targets: ${MKL_IMPORTED_TARGETS}")

target_include_directories(${PROJECT_NAME}_CPU PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Scions>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>/include/"
        "$<INSTALL_INTERFACE:include>"
)

set_target_properties(${PROJECT_NAME}_CPU PROPERTIES
        DEBUG_POSTFIX "${STATIC_POSTFIX}-d"
        RELEASE_POSTFIX ""
        MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
        RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)

#Add subdirectories
foreach (VAR ${SUBDIRECTORIES})
    add_subdirectory(${VAR})
endforeach ()
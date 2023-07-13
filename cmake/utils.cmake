# Utils.cmake

# Function to recursively find source files in a directory
function(find_source_files DIR FILES)
    file(GLOB_RECURSE SOURCE_FILES "${DIR}/*.cpp" "${DIR}/*.h" "${DIR}/*.hpp")
    list(APPEND ${FILES} ${SOURCE_FILES} PARENT_SCOPE)
endfunction()

# Function to recursively find subdirectories in a directory
function(find_subdirectories DIR SUBDIRECTORIES FILES)
    file(GLOB CHILDREN RELATIVE "${DIR}" "${DIR}/*")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY "${DIR}/${CHILD}")
            list(APPEND ${SUBDIRECTORIES} "${CHILD}" PARENT_SCOPE)
            find_subdirectories("${DIR}/${CHILD}" ${SUBDIRECTORIES} ${FILES})
            find_source_files("${DIR}/${CHILD}" ${FILES})
        endif()
    endforeach()
endfunction()

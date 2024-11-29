# Add library cpp files

if (NOT DEFINED COREHTTP_PATH)
    set(COREHTTP_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/coreHTTP")
endif()

message("Using COREHTTP from ${COREHTTP_PATH}")

include(${COREHTTP_PATH}/httpFilePaths.cmake)

message("${HTTP_SOURCES}")

add_library(coreHTTP STATIC)

target_sources(coreHTTP PUBLIC
	${HTTP_SOURCES}
)


# Add include directory
target_include_directories(coreHTTP PUBLIC 
    ${HTTP_INCLUDE_PUBLIC_DIRS}
    ${COREHTTP_PORT}
)

target_link_libraries(coreHTTP PUBLIC pico_stdlib)


#target_precompile_headers(coreHTTP PRIVATE
#  ${FREERTOS_CONFIG_FILE_DIRECTORY}/logging_stack.h
#)

target_compile_definitions(coreHTTP PRIVATE
	LIBRARY_LOG_LEVEL=LOG_ERROR
	LIBRARY_LOG_NAME="coreHTTP"
)

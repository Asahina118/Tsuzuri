add_library(doctest INTERFACE)

target_include_directories(doctest INTERFACE
    ${PROJECT_SOURCE_DIR}
)

add_executable(logger    
    ${PROJECT_SOURCE_DIR}/tests/logger.cpp
)

target_link_libraries(logger PRIVATE
    doctest
    "${project_name}"
)

target_compile_definitions(logger PRIVATE
    DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
)

set_target_properties(logger PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)

add_test(NAME logger COMMAND logger)

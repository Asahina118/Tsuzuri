add_library(doctest INTERFACE)

target_include_directories(doctest INTERFACE
    ${PROJECT_SOURCE_DIR}
)

add_executable(example    
    ${PROJECT_SOURCE_DIR}/tests/example.cpp
)

target_link_libraries(example PRIVATE
    doctest
    "${project_name}"
)

target_compile_definitions(example PRIVATE
    DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
)

set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)

add_test(NAME example COMMAND example)

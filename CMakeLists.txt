cmake_minimum_required(VERSION 3.20)
get_filename_component(project_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
project("${project_name}" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_executable("${project_name}"
    src/main.cpp
)

target_include_directories("${project_name}" PUBLIC
        ${PROJECT_SOURCE_DIR}
)

if(BUILD_TESTING)
    add_subdirectory(tests test)
endif()

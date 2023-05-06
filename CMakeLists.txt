cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(spinning_cube VERSION 1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable("${PROJECT_NAME}" main.cpp src/vec3.cpp ${SRC_FILES})

target_include_directories("${PROJECT_NAME}" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries("${PROJECT_NAME}" SDL2main SDL2)

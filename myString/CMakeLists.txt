project(myString)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wno-missing-field-initializers")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/ SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})


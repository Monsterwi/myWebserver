cmake_minimum_required(VERSION 2.6)
project(libnet)

if(NOT CMAKE_STUB_FORMATTER)
    set(CMAKE_STUB_FORMATTER echo)
endif()

set(CXX_FLAGS
        -O0
        -g
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wwrite-strings
        -std=c++17
        -march=native
        -rdynamic)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib)

include_directories(
        libnet/base
        libnet/net
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_BINARY_DIR})

add_subdirectory(libnet/base)
add_subdirectory(libnet/net)
add_subdirectory(examples/echo)
add_subdirectory(examples/http)


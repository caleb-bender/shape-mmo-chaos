cmake_minimum_required(VERSION 3.28)

project(ShapeMMOChaos VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")

add_subdirectory(networking-common)
add_subdirectory(networking-common-tests/unit)
add_subdirectory(shape-mmo-client)
add_subdirectory(shape-mmo-server)
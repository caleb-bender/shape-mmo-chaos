cmake_minimum_required(VERSION 3.28)

project(ShapeMMOChaos VERSION 0.0.0 LANGUAGES CXX)

add_subdirectory(networking-common)
add_subdirectory(networking-common-tests/unit)
add_subdirectory(shape-mmo-client)
add_subdirectory(shape-mmo-server)


add_executable(ShapeMMOServer)

target_sources(ShapeMMOServer PRIVATE ./src/main.cpp)

target_link_libraries(
    ShapeMMOServer PRIVATE NetworkingCommon
)
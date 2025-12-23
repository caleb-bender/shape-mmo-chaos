

add_executable(ShapeMMOClient)

target_sources(ShapeMMOClient PRIVATE ./src/main.cpp)

target_link_libraries(
    ShapeMMOClient PRIVATE NetworkingCommon
)


add_subdirectory(vendor/SDL3)

add_executable(ShapeMMOClient)

target_link_libraries(
    ShapeMMOClient PRIVATE NetworkingCommon
)

target_sources(ShapeMMOClient
    PRIVATE
        ./src/main.cpp
    PRIVATE
        FILE_SET sdl3InternalHeaders
        TYPE HEADERS
        BASE_DIRS
            ./vendor/SDL3/include
        FILES
            ./vendor/SDL3/include/SDL3/SDL.h
            ./vendor/SDL3/include/SDL3/SDL_main.h
)

target_link_libraries(
    ShapeMMOClient PRIVATE SDL3-shared
)
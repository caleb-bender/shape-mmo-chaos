

add_library(NetworkingCommon)

target_sources(NetworkingCommon
    PRIVATE
        ./src/NetworkingCommon.cpp
    PUBLIC
        FILE_SET NetworkingCommonHeaders
        TYPE HEADERS
        BASE_DIRS
            ./include
        FILES
            ./include/NetworkingCommon.hpp
)

target_precompiled_headers(
    NetworkingCommon PRIVATE ./include/NetworkingCommonPch.hpp
)
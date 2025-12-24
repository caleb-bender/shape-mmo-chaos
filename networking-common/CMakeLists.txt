add_library(NetworkingCommon)

target_sources(NetworkingCommon
    PRIVATE ./src/NetworkingCommon.cpp
    PUBLIC
        FILE_SET networkingCommonHeaders
        TYPE HEADERS
        BASE_DIRS
            ./include
        FILES
            ./include/NetworkingCommon.hpp
)

target_precompile_headers(
    NetworkingCommon PRIVATE ./include/NetworkingCommonPch.hpp
)
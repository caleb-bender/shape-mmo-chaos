add_library(NetworkingCommon)

target_sources(NetworkingCommon
    PRIVATE
        ./src/NetworkingCommon.cpp
        ./src/Conversion/HostToNetwork.cpp
    PUBLIC
        FILE_SET networkingCommonHeaders
        TYPE HEADERS
        BASE_DIRS
            ./include
        FILES
            ./include/NetworkingCommon.hpp
            ./include/Conversion/HostToNetwork.hpp
)

target_precompile_headers(
    NetworkingCommon PRIVATE ./include/NetworkingCommonPch.hpp
)
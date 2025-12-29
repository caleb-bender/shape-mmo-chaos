add_executable(NetworkingCommonUnitTests)

target_sources(NetworkingCommonUnitTests
    PRIVATE
        ./src/main.cpp
    PRIVATE
        FILE_SET networkingCommonUnitTestsVendorHeaders
        TYPE HEADERS
        BASE_DIRS
            ../../vendor/utest
        FILES
            ../../vendor/utest/utest.h
    PRIVATE
        FILE_SET networkingCommonUnitTestsLibraryHeaders
        TYPE HEADERS
        BASE_DIRS
            ../../networking-common/include
            ./include
        FILES
            ../../networking-common/include/NetworkingCommon.hpp
            ./include/NetworkingCommonUnitTestsPch.hpp
            ./include/Conversion/HostToNetworkTests.hpp
            ./include/Addresses/IPAddressTests.hpp
)

target_precompile_headers(
    NetworkingCommonUnitTests PRIVATE ./include/NetworkingCommonUnitTestsPch.hpp
)

target_link_libraries(NetworkingCommonUnitTests PRIVATE NetworkingCommon)


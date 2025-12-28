#pragma once
#include "NetworkingCommonUnitTestsPch.hpp"
#include "Conversion/HostToNetwork.hpp"

UTEST(Conversion_HostToNetF32, WhenConvertingToBigEndianOrNetworkFloat_ThenItsBytesAreCorrect) {
    // Arrange
    static_assert(sizeof(float) == 4);
    static_assert(std::numeric_limits<float>::is_iec559); // IEEE-754
    float f = -123.456f;
    // Act
    uint32_t net = Bender::Conversion::HostToNet(f);
    // Assert
    std::array<uint8_t, 4> expectedBigEndianBytes = {0xC2, 0xF6, 0xE9, 0x79};
    std::array<uint8_t, 4> bytes{};
    std::memcpy(bytes.data(), &net, bytes.size());
    // Expected IEEE-754 bytes in network (big-endian) order
    for (int i = 0; i < 4; i++)
        ASSERT_EQ(expectedBigEndianBytes[i], bytes[i]);
}

UTEST(Conversion_HostToNetF64, WhenConvertingToBigEndianOrNetworkDouble_ThenItsBytesAreCorrect) {
    // Arrange
    static_assert(sizeof(double) == 8);
    static_assert(std::numeric_limits<double>::is_iec559); // IEEE-754
    double d = -12345.67890;
    // Act
    uint64_t net = Bender::Conversion::HostToNet(d);
    // Assert
    std::array<uint8_t, 8> expectedBigEndianBytes = {0xC0, 0xC8, 0x1C, 0xD6, 0xE6, 0x31, 0xF8, 0xA1};
    std::array<uint8_t, 8> bytes{};
    std::memcpy(bytes.data(), &net, bytes.size());
    // Expected IEEE-754 bytes in network (big-endian) order
    for (int i = 0; i < 8; i++)
        ASSERT_EQ(expectedBigEndianBytes[i], bytes[i]);
}
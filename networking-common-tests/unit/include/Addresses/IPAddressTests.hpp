#pragma once
#include "NetworkingCommonUnitTestsPch.hpp"
#include "Addresses/IPAddress.hpp"

UTEST(IPAddressTests, WhenCreatingValidIPv4AddressNoExceptionIsThrown) {
    // Act & Assert
    Bender::Addresses::IPAddress ipAddress("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4);
}

UTEST(IPAddressTests, WhenCreatingIPv4AddressWithInvalidData_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act & Assert
    EXPECT_EXCEPTION_WITH_MESSAGE(
        Bender::Addresses::IPAddress("192.168.1.245.1", Bender::Addresses::IPAddress::Type::IPv4),
        std::invalid_argument,
        "\"192.168.1.245.1\" is not a valid IPv4 address"
    );
}

UTEST(IPAddressTests, WhenCreatingIPv6AddressWithInvalidData_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act & Assert
    EXPECT_EXCEPTION_WITH_MESSAGE(
        Bender::Addresses::IPAddress("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv6),
        std::invalid_argument,
        "\"192.168.1.245\" is not a valid IPv6 address"
    );
}

UTEST(IPAddressTests, WhenCreatingIPAddressWithInvalidTypeAny_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act & Assert
    EXPECT_EXCEPTION_WITH_MESSAGE(
        Bender::Addresses::IPAddress("192.168.1.245", Bender::Addresses::IPAddress::Type::Any),
        std::invalid_argument,
        "type must be IPAddress::Type::IPv4 or IPAddress::Type::IPv6"
    );
}

UTEST(IPAddressTests, WhenCreatingIPAddressWithNullConstCharPointer_ThenInvalidRuntimeErrorIsThrownWithCorrectMessage) {
    // Act & Assert
    EXPECT_EXCEPTION_WITH_MESSAGE(
        Bender::Addresses::IPAddress(nullptr, Bender::Addresses::IPAddress::Type::IPv4),
        std::runtime_error,
        "Failed to create IPAddress"
    );
}

UTEST(IPAddressTests, WhenWritingIPv4AddressToOstream_ThenItContainsCorrectStringData) {
    // Arrange
    std::ostringstream stream;
    Bender::Addresses::IPAddress ipAddress("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4);
    // Act
    stream << ipAddress;
    // Assert
    std::string output = stream.str();
    ASSERT_STREQ(output.c_str(), "IPv4: 192.168.1.245");
}

UTEST(IPAddressTests, WhenWritingIPv6AddressToOstream_ThenItContainsCorrectStringData) {
    // Arrange
    std::ostringstream stream;
    Bender::Addresses::IPAddress ipAddress("2601:204:c903:c630::b03d", Bender::Addresses::IPAddress::Type::IPv6);
    // Act
    stream << ipAddress;
    // Assert
    std::string output = stream.str();
    ASSERT_STREQ(output.c_str(), "IPv6: 2601:204:c903:c630::b03d");
}

// test that type() method returns correct type
UTEST(IPAddressTests, WhenCreatingIPv4Address_ThenTypeMethodReturnsIPv4) {
    // Arrange
    Bender::Addresses::IPAddress ipAddress("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4);
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv4;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenCreatingIPv6Address_ThenTypeMethodReturnsIPv6) {
    // Arrange
    Bender::Addresses::IPAddress ipAddress("2601:204:c903:c630::b03d", Bender::Addresses::IPAddress::Type::IPv6);
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv6;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenUsingIPv4UserDefinedLiteral_ThenCreatesCorrectIPAddress) {
    // Arrange
    using namespace Bender::Addresses;
    Bender::Addresses::IPAddress ipAddress = "192.168.1.245"_ipv4;
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv4;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenUsingIPv6UserDefinedLiteral_ThenCreatesCorrectIPAddress) {
    // Arrange
    using namespace Bender::Addresses;
    Bender::Addresses::IPAddress ipAddress = "2601:204:c903:c630::b03d"_ipv6;
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv6;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}
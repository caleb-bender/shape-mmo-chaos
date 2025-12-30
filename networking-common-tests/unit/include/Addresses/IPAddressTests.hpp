#pragma once
#include "NetworkingCommonUnitTestsPch.hpp"
#include "Addresses/IPAddress.hpp"

UTEST(IPAddressTests, WhenCreatingValidIPv4AddressNoExceptionIsThrown) {
    // Act & Assert
    Bender::Addresses::IPAddress::create("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4);
}

UTEST(IPAddressTests, WhenCreatingIPv4AddressWithInvalidData_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act
    auto expected = Bender::Addresses::IPAddress::create("192.168.1.245.1", Bender::Addresses::IPAddress::Type::IPv4);
    // Assert
    ASSERT_FALSE(expected.has_value());
    ASSERT_STREQ("\"192.168.1.245.1\" is not a valid IPv4 address", expected.error().c_str());
}

UTEST(IPAddressTests, WhenCreatingIPv6AddressWithInvalidData_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act
    auto expected = Bender::Addresses::IPAddress::create("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv6);
    // Assert
    ASSERT_FALSE(expected.has_value());
    ASSERT_STREQ("\"192.168.1.245\" is not a valid IPv6 address", expected.error().c_str());
}

UTEST(IPAddressTests, WhenCreatingIPAddressWithInvalidTypeAny_ThenInvalidArgumentExceptionIsThrownWithCorrectMessage) {
    // Act
    auto expected = Bender::Addresses::IPAddress::create("192.168.1.245", Bender::Addresses::IPAddress::Type::Any);
    // Assert
    ASSERT_FALSE(expected.has_value());
    ASSERT_STREQ("type must be IPAddress::Type::IPv4 or IPAddress::Type::IPv6", expected.error().c_str());
}

UTEST(IPAddressTests, WhenCreatingIPAddressWithNullConstCharPointer_ThenInvalidRuntimeErrorIsThrownWithCorrectMessage) {
    // Act
    auto expected = Bender::Addresses::IPAddress::create(nullptr, Bender::Addresses::IPAddress::Type::IPv4);
    // Assert
    ASSERT_FALSE(expected.has_value());
    ASSERT_STREQ("Failed to create IPAddress", expected.error().c_str());
}

UTEST(IPAddressTests, WhenWritingIPv4AddressToOstream_ThenItContainsCorrectStringData) {
    // Arrange
    std::ostringstream stream;
    auto ipAddress = Bender::Addresses::IPAddress::create("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4).value();
    // Act
    stream << ipAddress;
    // Assert
    std::string output = stream.str();
    ASSERT_STREQ(output.c_str(), "IPv4: 192.168.1.245");
}

UTEST(IPAddressTests, WhenWritingIPv6AddressToOstream_ThenItContainsCorrectStringData) {
    // Arrange
    std::ostringstream stream;
    auto ipAddress = Bender::Addresses::IPAddress::create("2601:204:c903:c630::b03d", Bender::Addresses::IPAddress::Type::IPv6).value();
    // Act
    stream << ipAddress;
    // Assert
    std::string output = stream.str();
    ASSERT_STREQ(output.c_str(), "IPv6: 2601:204:c903:c630::b03d");
}

// test that type() method returns correct type
UTEST(IPAddressTests, WhenCreatingIPv4Address_ThenTypeMethodReturnsIPv4) {
    // Arrange
    auto ipAddress = Bender::Addresses::IPAddress::create("192.168.1.245", Bender::Addresses::IPAddress::Type::IPv4).value();
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv4;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenCreatingIPv6Address_ThenTypeMethodReturnsIPv6) {
    // Arrange
    auto ipAddress = Bender::Addresses::IPAddress::create("2601:204:c903:c630::b03d", Bender::Addresses::IPAddress::Type::IPv6).value();
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv6;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenUsingIPv4UserDefinedLiteral_ThenCreatesCorrectIPAddress) {
    // Arrange
    using namespace Bender::Addresses;
    auto ipAddress = "192.168.1.245"_ipv4;
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv4;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}

UTEST(IPAddressTests, WhenUsingIPv6UserDefinedLiteral_ThenCreatesCorrectIPAddress) {
    // Arrange
    using namespace Bender::Addresses;
    auto ipAddress = "2601:204:c903:c630::b03d"_ipv6;
    auto expectedType = Bender::Addresses::IPAddress::Type::IPv6;
    // Act
    auto actualType = ipAddress.type();
    // Assert
    ASSERT_EQ(expectedType, actualType);
}
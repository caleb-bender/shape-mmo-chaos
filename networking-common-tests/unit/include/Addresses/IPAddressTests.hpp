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
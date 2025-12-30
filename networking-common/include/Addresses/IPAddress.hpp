#pragma once
#include <ostream>
#include <cstdint>
#include <string>
#include <expected>
#include <array>

namespace Bender::Addresses {

    
    class IPAddress {
    public:
        enum class Type : std::uint8_t {
            IPv4,
            IPv6,
            Any
        };

        static std::expected<IPAddress, std::string> create(const char* ip, Type type);
        ~IPAddress();
        friend std::ostream& operator<<(std::ostream& os, const IPAddress& obj);
        constexpr Type type() const { return _type; }
    private:
        IPAddress(std::array<std::uint8_t, 16> ipDataBuffer, Type type);
        alignas(16) std::array<std::uint8_t, 16> _ipDataBuffer = {0};
        Type _type;
    };

    IPAddress operator"" _ipv4(const char* ip, std::size_t len);
    IPAddress operator"" _ipv6(const char* ip, std::size_t len);
}
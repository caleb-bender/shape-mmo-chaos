#pragma once
#include <ostream>
#include <cstdint>

namespace Bender::Addresses {

    
    class IPAddress {
    public:
        enum class Type : std::uint8_t {
            IPv4,
            IPv6,
            Any
        };

        IPAddress(const char* ip, Type type);
        ~IPAddress();
        friend std::ostream& operator<<(std::ostream& os, const IPAddress& obj);
        constexpr Type type() const { return _type; }
    private:
        alignas(16) std::uint8_t _ipDataBuffer[16] = {0};
        Type _type;
    };

    IPAddress operator"" _ipv4(const char* ip, std::size_t len);
    IPAddress operator"" _ipv6(const char* ip, std::size_t len);
}
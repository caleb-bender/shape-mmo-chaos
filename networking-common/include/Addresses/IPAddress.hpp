#pragma once
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
    private:
        alignas(16) std::uint8_t _ipDataBuffer[16] = {0};
    };

    // IPAddress operator"" _ipv4(const char* ip);
    // IPAddress operator"" _ipv6(const char* ip);


}
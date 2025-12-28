#include "NetworkingCommonPch.hpp"
#include "Conversion/HostToNetwork.hpp"

namespace Bender::Conversion {

    uint32_t HostToNet(float f) {
        static_assert(sizeof(float) == 4);
        uint32_t u;
        std::memcpy(&u, &f, sizeof(float));
        return htonl(u);
    }
    
    uint64_t HostToNet(double d) {
        static_assert(sizeof(double) == 8);
        uint64_t u;
        std::memcpy(&u, &d, sizeof(double));
        static_assert(std::endian::native == std::endian::little || std::endian::native == std::endian::big, "Unknown endianness");
        if constexpr (std::endian::native == std::endian::little) {
            uint8_t* bytes = reinterpret_cast<uint8_t*>(&u);
            std::reverse(bytes, bytes + sizeof(uint64_t));
        }
        return u;
    }
}
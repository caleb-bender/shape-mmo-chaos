#include "NetworkingCommonPch.hpp"
#include "Conversion/HostToNetwork.hpp"

namespace Bender::Conversion {

    uint32_t HostToNetF32(float f) {
        uint32_t u;
        std::memcpy(&u, &f, sizeof(float));
        return htonl(u);
    }

    uint64_t HostToNetF64(double d) {
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
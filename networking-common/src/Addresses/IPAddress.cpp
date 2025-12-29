#include "NetworkingCommonPch.hpp"
#include "Addresses/IPAddress.hpp"

namespace Bender::Addresses {

    struct IPData {
        std::uint8_t addr[sizeof(struct in6_addr)];
    };

    IPAddress::IPAddress(const char* ip, IPAddress::Type type) {
        new (_ipDataBuffer) IPData;
        IPData* data = reinterpret_cast<IPData*>(_ipDataBuffer);
        int rc;
        if (!ip) throw std::runtime_error("Failed to create IPAddress");
        if (type == IPAddress::Type::IPv4) {
            rc = inet_pton(AF_INET, ip, data->addr);
        }
        else if (type == IPAddress::Type::IPv6) {
            rc = inet_pton(AF_INET6, ip, data->addr);
        }
        else {
            throw std::invalid_argument("type must be IPAddress::Type::IPv4 or IPAddress::Type::IPv6");
        }

        if (rc == 0) {
            std::string ipTypeString = (type == IPAddress::Type::IPv4) ? "IPv4" : "IPv6";
            throw std::invalid_argument("\"" + std::string(ip) + "\" is not a valid " + ipTypeString + " address");
        }
        else if (rc < 0) {
            throw std::runtime_error("Failed to create IPAddress");
        }
    }

    IPAddress::~IPAddress() {
        IPData* data = reinterpret_cast<IPData*>(_ipDataBuffer);
        data->~IPData();
    }
}
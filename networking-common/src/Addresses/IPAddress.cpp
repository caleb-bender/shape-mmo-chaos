#include "NetworkingCommonPch.hpp"
#include "Addresses/IPAddress.hpp"

namespace Bender::Addresses {

    struct IPData {
        std::uint8_t addr[sizeof(struct in6_addr)];
    };

    IPAddress::IPAddress(const char* ip, IPAddress::Type type) : _type(type) {
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

    std::ostream& operator<<(std::ostream& os, const IPAddress& obj) {
        char ipAddressString[INET6_ADDRSTRLEN];
        const IPData* data = reinterpret_cast<const IPData*>(obj._ipDataBuffer);
        if (obj._type == IPAddress::Type::IPv4) {
            inet_ntop(AF_INET, data->addr, ipAddressString, INET_ADDRSTRLEN);
        }
        else {
            inet_ntop(AF_INET6, data->addr, ipAddressString, INET6_ADDRSTRLEN);
        }
        os << ((obj._type == IPAddress::Type::IPv4) ? "IPv4: " : "IPv6: ") << ipAddressString;
        return os;
    }

    IPAddress operator"" _ipv4(const char* ip, std::size_t len) {
        return IPAddress(ip, IPAddress::Type::IPv4);
    }

    IPAddress operator"" _ipv6(const char* ip, std::size_t len) {
        return IPAddress(ip, IPAddress::Type::IPv6);
    }
}
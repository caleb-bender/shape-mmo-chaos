#include "NetworkingCommonPch.hpp"
#include "Addresses/IPAddress.hpp"

namespace Bender::Addresses {

    struct IPData {
        std::uint8_t addr[sizeof(struct in6_addr)];
    };

    std::expected<IPAddress, std::string> IPAddress::create(const char* ip, Type type) {
        std::array<std::uint8_t, 16> ipDataBuffer = {0};
        if (!ip) return std::unexpected("Failed to create IPAddress");
        int rc;
        if (type == IPAddress::Type::IPv4) {
            rc = inet_pton(AF_INET, ip, ipDataBuffer.data());
        }
        else if (type == IPAddress::Type::IPv6) {
            rc = inet_pton(AF_INET6, ip, ipDataBuffer.data());
        }
        else {
            return std::unexpected("type must be IPAddress::Type::IPv4 or IPAddress::Type::IPv6");
        }

        if (rc == 0) {
            std::string ipTypeString = (type == IPAddress::Type::IPv4) ? "IPv4" : "IPv6";
            return std::unexpected("\"" + std::string(ip) + "\" is not a valid " + ipTypeString + " address");
        }
        else if (rc < 0) {
            return std::unexpected("Failed to create IPAddress");
        }
        return IPAddress(ipDataBuffer, type);
    }

    IPAddress::IPAddress(std::array<std::uint8_t, 16> ipDataBuffer, Type type) : _type(type) {
        new (_ipDataBuffer.data()) IPData;
        IPData* data = reinterpret_cast<IPData*>(_ipDataBuffer.data());
        std::copy(ipDataBuffer.begin(), ipDataBuffer.end(), data->addr);
    }

    IPAddress::~IPAddress() {
        IPData* data = reinterpret_cast<IPData*>(_ipDataBuffer.data());
        data->~IPData();
    }

    std::ostream& operator<<(std::ostream& os, const IPAddress& obj) {
        char ipAddressString[INET6_ADDRSTRLEN];
        const IPData* data = reinterpret_cast<const IPData*>(obj._ipDataBuffer.data());
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
        return IPAddress::create(ip, IPAddress::Type::IPv4).value();
    }

    IPAddress operator"" _ipv6(const char* ip, std::size_t len) {
        return IPAddress::create(ip, IPAddress::Type::IPv6).value();
    }
}
#include <NetworkingCommon.hpp>
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace Bender::Addresses;

int main(int argc, char* argv[]) {

    IPAddress ip = IPAddress::create("192.168.1.245", IPAddress::Type::IPv4).value();
    return 0;
}
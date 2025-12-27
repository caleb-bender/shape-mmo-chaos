#include <NetworkingCommon.hpp>
#include <iostream>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "You must include float argument\n";
        return 1;
    }
    float f = atof(argv[1]);
    uint32_t u;
    memcpy(&u, &f, 4);
    uint32_t sign = u & 0b10000000000000000000000000000000;
    int exp = (u << 1) >> 24;
    float significand = (u << 9) >> 9;
    std::cout << "f = " << f << ":\n";
    std::cout << "sign = " << ((sign == 0) ? "+" : "-") << "\n";
    std::cout << "exp = 2^" << (exp - 127) << "\n";
    std::cout << "significand = 1 + " << (significand / 0b00000000011111111111111111111111) << "\n";
    return 0;
}
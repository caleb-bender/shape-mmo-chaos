#pragma once

namespace Bender::Conversion {

    // Assumes f is an IEEE 754 float
    uint32_t HostToNet(float f);
    // Assumes d is an IEEE 754 double
    uint64_t HostToNet(double d);
}
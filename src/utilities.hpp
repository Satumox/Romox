#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <cstdio>

std::string formatHex(uint8_t num) {
    char buf[5];
    snprintf(buf, sizeof(buf), "0x%02x", num);
    return std::string(buf);
}


#endif
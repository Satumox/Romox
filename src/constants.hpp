#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <cstdint>

namespace Romox {

    // Properties of the cartridge header
    constexpr uint8_t HEADER_SIZE = 0x50;

    // Positions of the information in the cartridge header
    constexpr uint8_t HEADER_ENTRY_POINT_POS = 0x0;
    constexpr uint8_t HEADER_LOGO_POS = 0x4;
    constexpr uint8_t HEADER_TITLE_POS = 0x34;
    constexpr uint8_t HEADER_MANUFACTURER_CODE_POS = 0x3F;
    constexpr uint8_t HEADER_CGB_FLAG_POS = 0x43;
    constexpr uint8_t HEADER_NEW_LICENSEE_CODE_POS = 0x44;
    constexpr uint8_t HEADER_SGB_FLAG_POS = 0x46;
    constexpr uint8_t HEADER_CARTRIDGE_TYPE_POS = 0x47;
    constexpr uint8_t HEADER_ROM_SIZE_POS = 0x48;
    constexpr uint8_t HEADER_RAM_SIZE_POS = 0x49;
    constexpr uint8_t HEADER_DESTINATION_CODE = 0x4A;
    constexpr uint8_t HEADER_OLD_LICENSEE_CODE = 0x4B;
    constexpr uint8_t HEADER_MASK_ROM_VERSION_NUMBER_POS = 0x4C;
    constexpr uint8_t HEADER_CHECKSUM_POS = 0x4D;
    constexpr uint8_t HEADER_GLOBAL_CHECKSUM_POS = 0x4F;
    
    // Sizes of the information stored in the cartrdige header
    constexpr uint8_t LOGO_SIZE = 48;
    constexpr uint8_t TITLE_SIZE = 16;
}

#endif
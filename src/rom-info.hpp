#ifndef ROM_INFO_HPP
#define ROM_INFO_HPP

#include <string>
#include <vector>
#include <cstdint>
#include <ostream>

class RomInfo
{
public:
    RomInfo(const std::string &romPath);
    virtual ~RomInfo();

    void printInfo(std::ostream& os);
    std::uintmax_t m_file_size;

    std::vector<uint8_t> m_rom_header;
    std::vector<uint8_t> m_rom_logo;
    std::string m_title;
    std::string m_manufacturer_code;
    uint8_t m_CGB_flag;
    std::string m_new_licensee_code;
    uint8_t m_SGB_flag;
    uint8_t m_cartridge_type;
    uint8_t m_rom_size;
    uint8_t m_ram_size;
    uint8_t m_destination_code;
    uint8_t m_old_licensee_code;
    uint8_t m_mask_rom_version_number;
    uint8_t m_header_checksum;
    uint16_t m_global_checkum;
};

#endif
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <filesystem>

#include "rom-info.hpp"
#include "constants.hpp"
#include "mappings.hpp"

namespace fs = std::filesystem;
using std::ifstream;

RomInfo::RomInfo(const std::string &romPath) : m_rom_header(Romox::HEADER_SIZE), m_rom_logo(Romox::LOGO_SIZE)
{
    std::ifstream romFile{};
    romFile.exceptions(ifstream::failbit | ifstream::badbit);
    romFile.open(romPath, std::ios::binary);

    // new check file size :P
    fs::path path(romPath);
    m_file_size = fs::file_size(path);

    if(m_file_size > 8388608) {
        std::cerr << "Warning: File is larger then 8MiB";
    }

    // read the entire header
    romFile.seekg(0x100, std::ios::beg);
    romFile.read(reinterpret_cast<char *>(m_rom_header.data()), Romox::HEADER_SIZE);
    romFile.close();

    // copy the logo
    std::copy(m_rom_header.begin() + Romox::HEADER_LOGO_POS, m_rom_header.begin() + Romox::LOGO_SIZE + 1, m_rom_logo.begin());

    // read and store title
    for (size_t offset = Romox::HEADER_TITLE_POS; offset < Romox::HEADER_TITLE_POS + Romox::TITLE_SIZE; offset++)
    {
        char c = static_cast<char>(m_rom_header[offset]);
        if ((c >= 0) && (c <= 127) && (c != '\0'))
        {
            m_title += c;
        }
        else
        {
            break;
        }
    }

    m_CGB_flag = m_rom_header[Romox::HEADER_CGB_FLAG_POS];
    m_SGB_flag = m_rom_header[Romox::HEADER_SGB_FLAG_POS];
    m_cartridge_type = m_rom_header[Romox::HEADER_CARTRIDGE_TYPE_POS];
    m_rom_size = m_rom_header[Romox::HEADER_ROM_SIZE_POS];
    m_ram_size = m_rom_header[Romox::HEADER_RAM_SIZE_POS];
    m_destination_code = m_rom_header[Romox::HEADER_DESTINATION_CODE];
    m_old_licensee_code = m_rom_header[Romox::HEADER_OLD_LICENSEE_CODE];
    m_new_licensee_code = {(char)m_rom_header[0x44], (char)m_rom_header[0x45]};
    m_mask_rom_version_number = m_rom_header[Romox::HEADER_MASK_ROM_VERSION_NUMBER_POS];
}

RomInfo::~RomInfo()
{
}

void RomInfo::printInfo(std::ostream &os = std::cout)
{
    // print out title
    os << "Title: " << m_title << std::endl;

    // print out CGB Flag info
    os << "CGB Flag: ";
    if (m_CGB_flag == 0x80)
    {
        os << "GB+GBC";
    }
    else if (m_CGB_flag == 0xC0)
    {
        os << "GBC Only";
    }
    else
    {
        os << "Not set";
    }
    os << std::endl;

    // print out SGB Flag info
    os << "SGB support: " << std::boolalpha << (m_SGB_flag == 0x03) << std::endl;

    // print cartrdige type
    os << "Cartridge type: " << Romox::Maps::cartridge_types.at(m_cartridge_type) << std::endl;

    // print ROM size
    os << "ROM size: " << Romox::Maps::rom_sizes.at(m_rom_size) << std::endl;

    // print RAM size
    os << "RAM size: " << Romox::Maps::ram_sizes.at(m_ram_size) << std::endl;

    // print Destination
    os << "Destination: ";

    if (m_destination_code == 0x00)
    {
        os << "Japan (and possibly overseas)";
    }
    else if (m_destination_code == 0x01)
    {
        os << "Overseas only";
    }
    else
    {
        os << "Unknown";
    }
    os << std::endl;

    if (m_old_licensee_code == 0x33)
    {
        os << "New Licensee Code: " << Romox::Maps::new_licensee_codes.at(m_new_licensee_code) << "\n";
    }
    else
    {
        os << "Licensee Code: " << (uint32_t)m_old_licensee_code << std::endl;
    }

    os << "Mask ROM Version number: " << (uint16_t)m_mask_rom_version_number << "\n";
}
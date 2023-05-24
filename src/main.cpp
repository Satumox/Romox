#include <iostream>
#include <string>
#include <filesystem>

#include "rom-info.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if(argc != 2) {
        std::cout << "Usage: romox <game>" << std::endl;
        return EXIT_FAILURE;
    }
    std::string filename{argv[1]};
    RomInfo romInfo{filename};

    romInfo.printInfo(std::cout);
    return 0;
}
#pragma once

#include <string>

#include "SHA512.h"

class Block {
public:
    explicit Block(int index, std::string data);
    void mine(int difficulty);
    
    std::string hash;
    std::string prevHash;
private:
    std::string getHash();
    
    int index = 0;
    std::string data;
    int iteration = 0;
    time_t currentTime;
    SHA512 hasher;
};

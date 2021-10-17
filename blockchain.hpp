#pragma once

#include <string>
#include <vector>

#include "block.hpp"

class Blockchain {
public:
    Blockchain();
    void addBlock(std::string data);
    void addBlock();
private:
    int index = 0;
    int difficulty = 6;
    std::vector<Block *> chain;
};

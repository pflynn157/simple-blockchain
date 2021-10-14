#pragma once

#include <string>
#include <vector>

#include "block.hpp"

class Blockchain {
public:
    Blockchain();
    void addBlock(std::string data);
private:
    int index = 0;
    int difficulty = 7;
    std::vector<Block *> chain;
};

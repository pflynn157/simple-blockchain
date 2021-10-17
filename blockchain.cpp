#include <random>

#include "blockchain.hpp"

Blockchain::Blockchain() {
    Block *first = new Block(0, "InTheBeginning");
    chain.push_back(first);
    
    ++index;
}

void Blockchain::addBlock(std::string data) {
    Block *block = new Block(index, data);
    ++index;
    block->prevHash = chain.back()->hash;
    block->mine(difficulty);
    chain.push_back(block);
}

void Blockchain::addBlock() {
    std::string data = "";
    
    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<> distr(33, 126);
    
    for (int i = 0; i<100; i++) {
        data += (char)distr(gen);
    }
    
    addBlock(data);
}
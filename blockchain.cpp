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

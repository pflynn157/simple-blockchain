#include <string>

#include "block.hpp"
#include "SHA512.h"

Block::Block(int index, std::string data) {
    this->index = index;
    this->data = data;
    this->iteration = 0;
    this->currentTime = time(NULL);
    
    hash = getHash();
}

void Block::mine(int difficulty) {
    std::string diffStr;
    for (int i = 0; i<difficulty; i++)
        diffStr += '1';
        
    do {
        ++iteration;
        hash = getHash();
    } while (hash.substr(0, difficulty) != diffStr);
}

inline std::string Block::getHash() {
    std::string input = data;
    input += std::to_string(index);
    input += std::to_string(iteration);
    input += std::to_string(currentTime);
    
    return hasher.hash(input);
}

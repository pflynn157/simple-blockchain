#include <iostream>
#include <string>

#include "block.hpp"
#include "sha256.h"

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
        
    //int show = 0;
    //std::cout << "HASH: " << diffStr << std::endl;
        
    do {
        ++iteration;
        hash = getHash();
        //if (show < 10) {
        //    std::cout << "CURRENT: " << hash.substr(0, difficulty) << " | " << hash << std::endl;
        //    ++show;
        //}
    } while (hash.substr(0, difficulty) != diffStr);
    
    std::cout << "Block mined: " << hash << std::endl;
}

inline std::string Block::getHash() {
    std::string input = data;
    input += std::to_string(index);
    input += std::to_string(iteration);
    input += std::to_string(currentTime);
    
    return sha256(input);
}

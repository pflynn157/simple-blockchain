#include <iostream>

#include "blockchain.hpp"

int main(int argc, char **argv) {
    Blockchain chain;
    
    chain.addBlock("Block1");
    chain.addBlock("Block2");
    chain.addBlock("Block3");
    
    return 0;
}
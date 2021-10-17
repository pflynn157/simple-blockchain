#include <iostream>

#include "blockchain.hpp"

int main(int argc, char **argv) {
    Blockchain chain;
    for (int i = 0; i<4; i++) chain.addBlock();
    
    return 0;
}

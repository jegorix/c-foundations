//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_H
#define BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_H
#include "block.h"

typedef struct{
    Block* head;
    int size;
}BlockChain;

#endif //BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_H

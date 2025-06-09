//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_BLOCK_H
#define BLOCKCHAIN_SIMULATOR_BLOCK_H
#include "transaction.h"

typedef struct{
    int index;
    char prev_hash[65];
    char hash[65];
    int nonce;
    int timestamp;
    Transaction* transaction;
    struct Block* next;
}Block;


#endif //BLOCKCHAIN_SIMULATOR_BLOCK_H

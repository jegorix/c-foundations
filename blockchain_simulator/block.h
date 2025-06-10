//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_BLOCK_H
#define BLOCKCHAIN_SIMULATOR_BLOCK_H
#include "transaction.h"
#define HASH_SIZE 65

typedef struct{
    int index;
    char prev_hash[65];
    char hash[65];
    int nonce;
    time_t timestamp;
    char data[1024];
    Transaction* transaction;
    int transaction_count;


    struct Block* next;
}Block;


#endif //BLOCKCHAIN_SIMULATOR_BLOCK_H

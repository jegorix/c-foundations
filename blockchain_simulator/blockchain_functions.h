//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_FUNCTIONS_H
#define BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>
#include "transaction.h"
#include "block.h"
#include "blockchain.h"
#include "miner.h"
#include "validators.h"
#include "auxiliary.h"



Transaction* create_transaction(const char* sender, const char* receiver, float amount);
void add_to_mempool(Transaction** mempool, Transaction* tx);
Block* create_block(int index, const char* prev_hash, Transaction* transactions);
char* make_serialization(Block* block);
void transaction_to_string(const Transaction* head, char* output, int limit_size);
int isValidHash(const char* hash, int difficulty);
void simple_hash(const char* input, int nonce, char* output);
int mine_block(Block* block, int difficulty);
char* make_serialization(Block* block);
Block* create_block(int index, const char* prev_hash, Transaction* transactions);
Miner* create_miner(const char* name);
void saveBlockchain(BlockChain* blockchain, const char* filename, const char* mode);
char* convert_time(time_t timestamp);

#endif //BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_FUNCTIONS_H

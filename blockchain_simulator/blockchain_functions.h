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
#include "transaction.h"
#include "block.h"
#include "blockchain.h"
#include "validators.h"
#include <stdint.h>


Transaction* create_transaction(const char* sender, const char* receiver, float amount);
void add_to_mempool(Transaction** mempool, Transaction* tx);
Block* create_block(int index, const char* prev_hash, Transaction* transactions);
char* make_serialization(Block* block);
void transaction_to_string(const Transaction* head, char* output, int limit_size);
int isValidHash(const char* hash, int difficulty);
void simple_hash(const char* input, int nonce, char* output);
int mine_block(Block* block);
char* make_serialization(Block* block);
Block* create_block(int index, const char* prev_hash, Transaction* transactions);

#endif //BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_FUNCTIONS_H

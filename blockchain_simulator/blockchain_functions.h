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


Transaction* create_transaction(const char* sender, const char* receiver, float amount);
void add_to_mempool(Transaction** mempool, Transaction* tx);


#endif //BLOCKCHAIN_SIMULATOR_BLOCKCHAIN_FUNCTIONS_H

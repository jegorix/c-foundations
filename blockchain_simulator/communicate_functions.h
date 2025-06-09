//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_COMMUNICATE_FUNCTIONS_H
#define BLOCKCHAIN_SIMULATOR_COMMUNICATE_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <validators.h>
#include "transaction.h"
#include "blockchain_functions.h"

void createTransactionInterface(Transaction** mempool);
void show_mempool(Transaction* mempool);
#endif //BLOCKCHAIN_SIMULATOR_COMMUNICATE_FUNCTIONS_H

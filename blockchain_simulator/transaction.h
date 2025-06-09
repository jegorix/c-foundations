//
// Created by jegorix on 8.06.25.
//

#ifndef BLOCKCHAIN_SIMULATOR_TRANSACTION_H
#define BLOCKCHAIN_SIMULATOR_TRANSACTION_H

    typedef struct{
    int id;
    char sender[50];
    char receiver[50];
    float amount;
    float fee;
    struct Transactions* next;
    }Transaction;

#endif //BLOCKCHAIN_SIMULATOR_TRANSACTION_H

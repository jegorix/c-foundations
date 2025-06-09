//
// Created by jegorix on 8.06.25.
//

#include "blockchain_functions.h"

Transaction* create_transaction(const char* sender, const char* receiver, float amount)
{
    time_t uniq_id = time(NULL);
    Transaction* tx = (Transaction*)malloc(sizeof(Transaction));
    assert(tx != NULL);
    strncpy(tx->sender, sender, sizeof(tx->sender) - 1);
    strncpy(tx->receiver, receiver, sizeof(tx->receiver) - 1);
    tx->amount = amount;
    tx->next = NULL;
    tx->id = uniq_id;
    tx->fee = 1 + (tx->amount * 0.005);
    return tx;
}

void add_to_mempool(Transaction** mempool, Transaction* tx)
{
    if(*mempool == NULL) *mempool = tx;
    else
    {
        Transaction* current = *mempool;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = tx;
    }

}

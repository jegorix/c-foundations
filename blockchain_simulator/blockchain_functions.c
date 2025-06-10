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


int isValidHash(const char* hash, int difficulty)
{
    for(int i = 0; i < difficulty; i++)
    {
        if(hash[i] != '0')
        {
            return 0;
        }
    }
    return 1;
}


void transaction_to_string(const Transaction* head, char* output, int limit_size)
{
    output[0] = '\0';
    char buffer[100];
    const Transaction* current = head;

    while(current != NULL)
    {
        snprintf(buffer, sizeof(buffer), "%s->%s:%.2f;", current->sender, current->receiver, current->amount);
        if(strlen(output) + strlen(buffer) < limit_size)
        {
            strcat(output, buffer);
        }
        else
        {
            printf("Warning: too many transactions for serialization!\n");
            break;
        }
        current = current->next;

    }
}



void simple_hash(const char* input, int nonce, char* output)
{
    uint32_t hash = 5381;
    int c;

    while(nonce > 0)
    {
        hash = ((hash << 5) + hash) ^ (nonce & 0xFF);
        nonce >>= 8;
    }

    while((c = *input++))
    {
        hash = ((hash << 5) + hash) ^ c;
    }


    sprintf(output, "%08x", hash);

    char final_hash[65] = "";
    for(int i = 0; i < 8; i++)
    {
        strcat(final_hash, output);
    }
    strcpy(output, final_hash);
}


int mine_block(Block* block, int difficulty)
{
    char hash_output[65];
    unsigned int nonce = 0;


  printf("\n╭───────────────────────────────────╮\n");
    printf("│        Nonce Calculating...       │\n");
    printf("╰───────────────────────────────────╯\n");


    do
    {
        simple_pause(300);
        block->nonce = nonce;
        char* serialized = make_serialization(block);
        simple_hash(serialized, block->nonce, hash_output);
        free(serialized);
        int try = nonce + 1;

      printf("\n╭────────────────────────────────────────────────────────────────────────╮\n");
        printf("│                                 Try-%03d                                │\n", try);
        printf("│ Nonce = %03d                                                            │\n", nonce);
        printf("│ HASH: %s │\n", hash_output);
        printf("╰────────────────────────────────────────────────────────────────────────╯\n");


        if(isValidHash(hash_output, difficulty))
        {
            strcpy(block->hash, hash_output);
            block->nonce = nonce;

          printf("\n╭────────────────────────────────────────────────────────────────────────╮\n");
            printf("│                              BLOCK MINED                               │\n");
            printf("│ Nonce = %03d                                                            │\n", nonce);
            printf("│ HASH: %s │\n", hash_output);
            printf("╰────────────────────────────────────────────────────────────────────────╯\n");

            return 1;
        }
        nonce++;
    }
    while (nonce < max_limit);

    return 0;
}



char* make_serialization(Block* block)
{
    char* block_data = malloc(1024);
    assert(block_data != NULL);
    char output[1024];
    transaction_to_string(block->transaction, output, sizeof(output));
    snprintf(block_data, 1024, "%d%ld%s%s", block->index, block->timestamp, block->prev_hash, output);

    return block_data;
}



Block* create_block(int index, const char* prev_hash, Transaction* transactions)
{
    Block* block = (Block*)malloc(sizeof(Block));
    assert(block != NULL);

    block->index = index;
    strncpy(block->prev_hash, prev_hash, HASH_SIZE - 1);
    block->prev_hash[HASH_SIZE - 1] = '\0';
    strcpy(block->hash, ""); // create HASH FUNC
    block->nonce = 0; // nonce calculate
    block->transaction = transactions;
    block->timestamp = time(NULL);


    Transaction* current = transactions;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    block->transaction_count = count;
    block->next = NULL;

    return block;
}
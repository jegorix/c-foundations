//
// Created by jegorix on 8.06.25.
//

#include "communicate_functions.h"

void createTransactionInterface(Transaction** mempool)
{
    char sender_name[50];
    char receiver_name[50];
    char buffer[50];
    char* stripped_buffer;

  printf("\n╭───────────────────────────────────╮\n");
    printf("│     Transaction Creation Menu     │\n");
    printf("╰───────────────────────────────────╯\n");

    printf("\n");

    do {
      printf("\n╭───────────────────────────────────╮\n");
      printf("│        Enter sender name          │\n");
      printf("╰───────────────────────────────────╯\n");
      printf("╰─> ");


      fgets(buffer, 50, stdin);
      buffer[strcspn(buffer, "\n")] = 0;
      stripped_buffer = strip(buffer);

      if(strlen(stripped_buffer) == 0)
      {
        printf(
              "\n╭────────────────────────────────────────╮\n"
                "│      Sender name cannot be empty       │\n"
                "╰────────────────────────────────────────╯\n\n"
        );
      }


    }while(strlen(stripped_buffer) == 0);

    strncpy(sender_name, stripped_buffer, sizeof(sender_name) - 1);
    stripped_buffer = NULL;



    do {
      printf("\n╭───────────────────────────────────╮\n");
      printf("│       Enter receiver name         │\n");
      printf("╰───────────────────────────────────╯\n");
      printf("╰─> ");

      fgets(buffer, 50, stdin);
      buffer[strcspn(buffer, "\n")] = 0;
      stripped_buffer = strip(buffer);

      if(strlen(stripped_buffer) == 0)
      {
        printf(
              "\n╭────────────────────────────────────────╮\n"
                "│      Receiver name cannot be empty     │\n"
                "╰────────────────────────────────────────╯\n\n"
        );
      }

    }while(strlen(stripped_buffer) == 0);

    strncpy(receiver_name, stripped_buffer, sizeof(sender_name) - 1);



    printf("\n╭───────────────────────────────────╮\n");
    printf("│      Enter amount of COINS        │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");


    float amount_coins = execute_verification_float(0, max_limit);

    Transaction* tx = NULL;

    tx = create_transaction(sender_name, receiver_name, amount_coins);
    add_to_mempool(mempool, tx);

    printf("\n╭───────────────────────────────────╮\n");
    printf("│          Transaction ID           │\n");
    printf("│            %d             │\n",tx->id );
    printf("╰───────────────────────────────────╯\n");

  printf("\n╭───────────────────────────────────╮\n");
    printf("│   Successfully added to mempool   │\n");
    printf("╰───────────────────────────────────╯\n");

}



void show_mempool(Transaction* mempool)
{
    if(mempool == NULL)
    {
      printf("\n╭───────────────────────────────────╮\n");
        printf("│          Mempool is empty         │\n");
        printf("╰───────────────────────────────────╯\n");
        return;
    }

    Transaction* current = mempool;

    while(current != NULL)
    {
      printf("\n╔══════════════════════════════╗\n");
        printf("║ Transaction (ID: %d) ║\n", current->id);
        printf("╠══════════════════════════════╣\n");
        printf("  SENDER: %s  \n", current->sender);
        printf("\n");
        printf("  RECEIVER: %s \n", current->receiver);
        printf("\n");
        printf("  COINS: %.02f      \n", current->amount);
        printf("\n");
        printf("  FEE: %.02f      \n", current->fee);
        printf("╚══════════════════════════════╝\n");
        printf("\n");

        current = current->next;
    }
}


void miningProcess(BlockChain* blockchain, Transaction** mempool, Miner* miner)
{
  assert(miner!=NULL);

  if(*mempool == NULL)
  {
    printf("\n╭───────────────────────────────────╮\n");
    printf("│          Mempool is empty         │\n");
    printf("╰───────────────────────────────────╯\n");
    return;
  }


printf("\n╭───────────────────────────────────╮\n");
  printf("│           PRESS 'ENTER'           │\n");
  printf("│      TO START MINING PROCESS      │\n");
  printf("╰───────────────────────────────────╯\n");

  fgetch();

  Block* last_block = blockchain->head;
  int difficulty = 1;

  if(last_block == NULL)
  {
    blockchain->size = 0;
    const char* GENESIS_PREV_HASH = "0000000000000000000000000000000000000000000000000000000000000000";
    Block* genesis = create_block(blockchain->size, GENESIS_PREV_HASH, *mempool);

    if(mine_block(genesis, difficulty))
    {
      blockchain->head = genesis;
      blockchain->size++;
      miner->blocks_mined++;
      printf("\n╭───────────────────────────────────╮\n");
      printf("│           GENESIS BLOCK           │\n");
      printf("│         SUCCESSFULLY ADDED        │\n");
      printf("│           TO BLOCKCHAIN           │\n");
      printf("╰───────────────────────────────────╯\n");
    }
  }
  else
  {
  while(last_block->next != NULL) last_block = last_block->next;

  Block* new_block = create_block(blockchain->size, last_block->hash, *mempool);
    if(mine_block(new_block, difficulty))
      {
        last_block->next = new_block;
        blockchain->size++;
        miner->blocks_mined++;
        printf("\n╭───────────────────────────────────╮\n");
          printf("│              BLOCK-%d              │\n", blockchain->size);
          printf("│         SUCCESSFULLY MINED        │\n");
          printf("╰───────────────────────────────────╯\n");
      }
    }

  Transaction* head = *mempool;
  while(head != NULL)
  {
    miner->balance += head->fee;
    Transaction* temp = head;
    head = head->next;
    free(temp);
  }
  *mempool = NULL;

printf("\n╭───────────────────────────────────╮\n");
  printf("│               MEMPOOL             │\n");
  printf("│           HAS BEEN CLEARED        │\n");
  printf("╰───────────────────────────────────╯\n");

}

void blockchainVisualisation(BlockChain* blockchain)
{
  Block* block = blockchain->head;
  if(block == NULL)
  {
    printf("\n╭───────────────────────────────────╮\n");
    printf("│        BlockChain is empty        │\n");
    printf("╰───────────────────────────────────╯\n");
    return;
  }

  printf("\n╭───────────────────────────────────╮\n");
  printf("│            BLOCKCHAIN             │\n");
  printf("╰───────────────────────────────────╯\n");
  printf("\n");


  while(block != NULL)
  {

  if(block->index == 0)
  {
  printf("\n╭───────────────────────────────────────────────────────────────────────────────────╮\n");
    printf("│                                     GENESIS BLOCK                                 │\n");
  }
  else
  {
    printf("                                            ⬆                                          \n");
    printf("                                            ▐                                          \n");
    printf("                                            ▐                                           \n");
    printf("╭───────────────────────────────────────────────────────────────────────────────────╮\n");
    printf("│                                       BLOCK-%02d                                    │\n", block->index);
  }

    printf("│ block hash: %s      │\n", block->hash);
    printf("│ previous hash: %s   │\n", block->prev_hash);
    printf("│ transaction count: %02d                                                             │\n", block->transaction_count);
    printf("  Transactions: %s                                                             \n", block->data);
    printf("╰───────────────────────────────────────────────────────────────────────────────────╯\n");


    block = block->next;

  }


}


void minersBalance(Miner* miner)
{
printf("\n╔══════════════════════════════╗\n");
  printf("║          MINER INFO          ║\n");
  printf("╠══════════════════════════════╣\n");
  printf("  Name: %s  \n", miner->name);
  printf("\n");
  printf("  Balance: %.02f \n", miner->balance);
  printf("\n");
  printf("  Blocks mined: %d      \n", miner->blocks_mined);
  printf("╚══════════════════════════════╝\n");
  printf("\n");
}
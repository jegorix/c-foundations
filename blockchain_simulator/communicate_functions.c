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

    strncpy(sender_name, stripped_buffer, sizeof(stripped_buffer) - 1);
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

    strncpy(receiver_name, stripped_buffer, sizeof(stripped_buffer) - 1);



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


void miningProcess(BlockChain* blockchain_main, BlockChain* blockchain_temp, Transaction** mempool)
{

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

  Block* last_block = blockchain_main->head;
  int difficulty = 1;
  const char* prev_hash;
  int index;



  if(last_block == NULL)
  {
    index = 0;
    prev_hash = "0000000000000000000000000000000000000000000000000000000000000000";
  }
  else
  {
    while(last_block->next != NULL)last_block = last_block->next;
    prev_hash = last_block->hash;
    index = last_block->index + 1;
  }

  Block* new_block = create_block(index, prev_hash, *mempool);

    if(mine_block(new_block, difficulty))
    {
      blockchain_temp->head = new_block;
      blockchain_temp->size++;

      printf("\n╭───────────────────────────────────╮\n");
      if (index == 0)
      {
        printf("│        GENESIS BLOCK MINED        │\n");
      }
      else
      {
      printf("│        BLOCK-%d MINED SUCCESS      │\n", index);
      }
      printf("╰───────────────────────────────────╯\n");

    }


//  Transaction* head = *mempool;
//  while(head != NULL)
//  {
//    Transaction* temp = head;
//    head = head->next;
//    free(temp);
//  }
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

    printf("│ Block hash: %s      │\n", block->hash);
    printf("│ Previous hash: %s   │\n", block->prev_hash);
    printf("│ Transaction count: %02d                                                             │\n", block->transaction_count);
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


void saveMenu(BlockChain* blockchain, const char* folder, const char* mode) {
  char filename[50];
  char buffer[50];
  char *stripped_buffer;
  char full_path[512];


  if(blockchain->head == NULL)
  {
    printf("\n╭───────────────────────────────────╮\n");
    printf("│        BlockChain is empty        │\n");
    printf("╰───────────────────────────────────╯\n");
    return;
  }



  printf("\n╭───────────────────────────────────╮\n");
  printf("│       Save BlockChain Menu        │\n");
  printf("╰───────────────────────────────────╯\n");

  printf("\n");

  do {
    printf("\n╭───────────────────────────────────╮\n");
    printf("│          Enter file name          │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");


    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stripped_buffer = strip(buffer);

    if (strlen(stripped_buffer) == 0) {
      printf(
              "\n╭────────────────────────────────────────╮\n"
              "│       File name cannot be empty        │\n"
              "╰────────────────────────────────────────╯\n\n"
      );
    }
  } while(strlen(stripped_buffer) == 0);

  strncpy(filename, stripped_buffer, sizeof(stripped_buffer)-1);

  snprintf(full_path, sizeof(full_path), "%s%s", folder, filename);
  saveBlockchain(blockchain, full_path, mode);

printf("\n╭───────────────────────────────────╮\n");
  printf("│   BLOCKCHAIN SUCCESSFULLY SAVED   │  \n");
  printf("╰───────────────────────────────────╯\n");
  printf("\n");

}




void nodeMode(BlockChain* blockchain_main, BlockChain* blockchain_temp, Miner* miner) {


  assert(miner != NULL);

  printf("\n╭───────────────────────────────────╮\n");
  printf("│             NODE MODE             │\n");
  printf("╰───────────────────────────────────╯\n");
  printf("\n");



  if (blockchain_temp->head == NULL) {
    printf(
            "\n╭────────────────────────────────────────╮\n"
            "│    List of potential blocks is empty   │\n"
            "╰────────────────────────────────────────╯\n\n"
    );
    return;
  }



  blockchainVisualisation(blockchain_temp);
  printf("\n╭───────────────────────────────────╮\n");
  printf("│           PRESS 'ENTER'           │\n");
  printf("│       TO START NODE PROCESS       │\n");
  printf("╰───────────────────────────────────╯\n");
  fgetch();



  Block* current_block = blockchain_temp->head;
  Block* next_block;


if(blockchain_main->head == NULL)
{
  while(current_block != NULL)
  {
    next_block = current_block->next;

    if(isBlockValid(current_block, NULL))
    {
      blockchain_main->head = current_block;
      blockchain_main->head->next = NULL;
      blockchain_main->size = 1;
      blockchain_temp->size = 0;


      miner->blocks_mined++;
      miner->balance += get_total_fee_from_block(current_block);

      printf("\n╭───────────────────────────────────╮\n");
      printf("│         GENESIS BLOCK ADDED       │\n");
      printf("╰───────────────────────────────────╯\n");
      break;
    }

    else
    {
      free(current_block);
      blockchain_temp->size = 0;
    printf("\n╭───────────────────────────────────╮\n");
      printf("│        BLOCK IS INVALID           │\n");
      printf("╰───────────────────────────────────╯\n");
    }

    current_block = next_block;
  }

  blockchain_temp->head = NULL;
  return;
}



  Block* prev_block = blockchain_main->head;
  while(prev_block->next != NULL) prev_block = prev_block->next;
  while(current_block != NULL)
  {
      next_block = current_block->next;

    if (isBlockValid(current_block, prev_block))
    {
      prev_block->next = current_block;
      prev_block = current_block;
      current_block->next = NULL;
      blockchain_main->size++;
      blockchain_temp->size--;

      miner->blocks_mined++;
      miner->balance += get_total_fee_from_block(current_block);

      printf("\n╭───────────────────────────────────╮\n");
      printf("│           BLOCK IS VALID          │\n");
      printf("╰───────────────────────────────────╯\n");

      }

    else
    {
      free(current_block);
      blockchain_temp->size--;
      printf("\n╭───────────────────────────────────╮\n");
      printf("│          BLOCK IS INVALID         │\n");
      printf("╰───────────────────────────────────╯\n");
    }

      current_block = next_block;
  }

  blockchain_temp->head = NULL;
  return;
}


void blockchain_history(const char* file_path)
{
 FILE* file = fopen(file_path, "r");

  if (!file)
  {
    printf(
          "\n╭────────────────────────────────────────╮\n"
            "│           Error opening file.          │\n"
            "╰────────────────────────────────────────╯\n"
            "\n"
    );
    return;
  }

  char buffer[256];
  while(fgets(buffer, sizeof(256), file) != NULL)
  {
    printf("%s", buffer);
  }
  fclose(file);


printf("\n\n╭───────────────────────────────────╮\n");
  printf("│        BLOCKCHAIN HISTORY         │\n");
  printf("│  IN REVERSE CHRONOLOGICAL ORDER   │\n");
  printf("╰───────────────────────────────────╯\n\n");


}



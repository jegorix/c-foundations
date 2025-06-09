//
// Created by jegorix on 8.06.25.
//

#include "communicate_functions.h"

void createTransactionInterface(Transaction** mempool)
{
    char sender_name[50];
    char receiver_name[50];
    char buffer[50];

  printf("\n╭───────────────────────────────────╮\n");
    printf("│     Transaction Creation Menu     │\n");
    printf("╰───────────────────────────────────╯\n");

    printf("\n");

  printf("\n╭───────────────────────────────────╮\n");
    printf("│        Enter sender name          │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");


    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(sender_name, buffer, sizeof(sender_name) - 1);


  printf("\n╭───────────────────────────────────╮\n");
    printf("│       Enter receiver name         │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");

    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(receiver_name, buffer, sizeof(sender_name) - 1);


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
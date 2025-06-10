//
// Created by jegorix on 7.06.25.
//

#include "user_interface.h"


void show_interface()
{
    Transaction* mempool = NULL;
    BlockChain* blockchain = malloc(sizeof(blockchain));
    assert(blockchain != NULL);
    Miner* miner_1 = create_miner("Cooper");

    const char* folder = "blockchain/";
    const char* filename = "autosave.txt";
    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s%s", folder, filename);


    int running = 1;
    while(running)
    {
        clearScreen();
        printf(
                "\n╔═════════════════════════════════════════════════╗\n"
                "║                Choose activity                  ║\n"
                "╠═════════════════════════════════════════════════╣\n"
                "║ 0 - Create Transaction                          ║\n"
                "║ 1 - Mempool Viewing                             ║\n"
                "║ 2 - Mining mode                                 ║\n"
                "║ 3 - Node mode                                   ║\n"
                "║ 4 - Miners Balance                              ║\n"
                "║ 5 - Blockchain Visualisation                    ║\n"
                "║ 6 - Save Blockchain                             ║\n"
                "║ 7 - Blockchain History                          ║\n"
                "║ 8 - Editing mode                                ║\n"
                "║ 9 -                                             ║\n"
                "║ q - Exit                                        ║\n"
                "╚═════════════════════════════════════════════════╝\n"
        );

        printf("\n╭───────────────────────────────────╮\n");
        printf("│          Enter command            │\n");
        printf("╰───────────────────────────────────╯\n");
        printf("╰─> ");
        fflush(stdout);

        char user_choice = fgetch();
        clearScreen();

        switch(user_choice)
        {
            case '0':
                createTransactionInterface(&mempool);
                break;

            case '1':
                show_mempool(mempool);
                break;

            case '2':
                miningProcess(blockchain, &mempool, miner_1);
                saveBlockchain(blockchain, full_path, "a");
                break;

            case '3':

                break;

            case '4':
                minersBalance(miner_1);
                break;

            case '5':
                blockchainVisualisation(blockchain);
                break;

            case '6':
                saveMenu(blockchain, folder, "w");
                break;

            case '7':

                break;

            case '8':

                break;

            case '9':

                break;

            case 'q':
                printf("\n╭────────────────────────╮\n");
                printf("│          Exit          │\n");
                printf("╰────────────────────────╯\n");
                free(blockchain);
                free(miner_1);
//                printf("Выход в меню выбора");
//                loadingAnimation(3, 250);
                running = 0;
                return;

            default:
                printf("\n╔══════════════════════════════════════╗\n");
                printf("║           Unknown command!           ║\n");
                printf("║          Please try again.           ║\n");
                printf("╚══════════════════════════════════════╝\n\n");


        }
      printf("\n╭───────────────────────────╮\n");
        printf("│ Press 'Enter' to continue │\n");
        printf("╰───────────────────────────╯\n");
        getchar();

    }



}
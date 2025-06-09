//
// Created by jegorix on 7.06.25.
//
#include "stdio.h"
#include "user_interface.h"
#include "animations.h"
#include "getch_unix_without_conio.h"
int main()
{
    int running = 1;

    while(running) {
        clearScreen();
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║                                      ║\n");
        printf("║              Welcome to              ║\n");
        printf("║                                      ║\n");
        printf("║        BLOCKCHAIN SIMULATOR          ║\n");
        printf("║                                      ║\n");
        printf("║     Press 'Enter' to get started     ║\n");
        printf("║          Enter 'q' to exit           ║\n");
        printf("║                                      ║\n");
        printf("╚══════════════════════════════════════╝\n");

        printf("\n╭───────────────────────────────────╮\n");
        printf("│          Enter command            │\n");
        printf("╰───────────────────────────────────╯\n");
        printf("╰─> ");

        fflush(stdout);

        char choice = fgetch();

        if (choice == 'q' || choice == 'Q')
        {
            running = 0;
            return 0;
        }

        show_interface();
    }

}

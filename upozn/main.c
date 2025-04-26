#include <stdio.h>
#include <unistd.h>
#include "operating_mode.h"

int main(void) {
    int running = 1;

    while(running)
    {
        clearScreen();
      printf("\n╔══════════════════════════════════════╗\n");
        printf("║                                      ║\n");
        printf("║         Добро пожаловать в           ║\n");
        printf("║                                      ║\n");
        printf("║            TASK MANAGER              ║\n");
        printf("║                                      ║\n");
        printf("║   Нажмите Enter, чтобы начать работу ║\n");
        printf("║         Введите 'q' для выхода       ║\n");
        printf("║                                      ║\n");
        printf("╚══════════════════════════════════════╝\n");

        printf("\n╭──────────────────────────────╮\n");
        printf("│Введите команду:              │\n");
        printf("╰─> ");
        fflush(stdout);



        char choice[10];
        fgets(choice, 10, stdin);
        if(choice[0] == 'q' || choice[0] == 'Q')
        {
            printf("\n     Выход из программы");
            loadingAnimation(3, 250);
            clearScreen();
            running = 0;
            return 0;
        }

        clearScreen();
        printf("\n     Загрузка");
        loadingAnimation(3, 250);
        operating_mode_menu();


    }

}

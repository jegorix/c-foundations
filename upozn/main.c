#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int running = 1;

    while(running)
    {
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




        char choice[10];
        fgets(choice, 10, stdin);
        if(choice[0] == 'q' || choice[0] == 'Q')
        {
            printf("\nВыход из программы...\n");
            running = 0;
            return 0;
        }

        printf("\nЗапуск Task Manager...\n");


    }

}

//
// Created by jegorix on 26.04.25.
//

#include "operating_mode.h"
#include "validators.h"

void operating_mode_menu()
{
    int running = 1;


    while(running) {
        clearScreen();
        printf("\n╔══════════════════════════════╗\n");
        printf("║            МЕНЮ              ║\n");
        printf("╠══════════════════════════════╣\n");
        printf("║ 1. Создать новый ежедневник  ║\n");
        printf("║ 2. Загрузить задачи из файла ║\n");
        printf("║ 3. Выход в главное меню      ║\n");
        printf("╚══════════════════════════════╝\n");
        printf("\n╭──────────────────────────────╮\n");
        printf("│Введите команду:              │\n");
        printf("╰─> ");
        int choice = execute_verification(1, 3);
        switch (choice)
        {
            case 1:
                printf("\n     Запуск");
                loadingAnimation(3,250);
                clearScreen();
//                task_manager_create();
                break;

            case 2:
                break;

            case 3:
                printf("\n    Выход в главное меню");
                loadingAnimation(3,250);
                clearScreen();
                running = 0;
                return;

            default:
                printf("Неверный выбор! Попробуйте еще раз.");

        }

    }


}
//
// Created by jegorix on 26.04.25.
//

#include "operating_mode.h"
#include "validators.h"
#include "task_operations.h"



void task_manager_menu() {
    TaskList* list = malloc(sizeof(TaskList));
    int running = 1;
    while (running) {
        clearScreen();
      printf("\n╔═════════════════════════════════════════════════╗\n");
        printf("║                Выберите действие                ║\n");
        printf("╠═════════════════════════════════════════════════╣\n");
        printf("║ 0 - Загрузить задачи из файла                   ║\n");
        printf("║ 1 - Добавить задачу                             ║\n");
        printf("║ 2 - Посмотреть список задач                     ║\n");
        printf("║ 3 - Изменить задачу                             ║\n");
        printf("║ 4 - Сохранить задачи в файл                     ║\n");
        printf("║ 5 - Отметить задачу как выполненную             ║\n");
        printf("║ 6 - Удалить задачу                              ║\n");
        printf("║ 7 - Поиск задачи                                ║\n");
        printf("║ 8 - Очистить список задач                       ║\n");
        printf("║ 9 - Сортировать задачи                          ║\n");
        printf("║ q - Выход в меню выбора                         ║\n");
        printf("╚═════════════════════════════════════════════════╝\n");

      printf("\n╭───────────────────────────────────╮\n");
        printf("│        Введите действие:          │\n");
        printf("╰───────────────────────────────────╯\n");
        printf("╰─> ");

        char user_choice[10];
        fgets(user_choice, 10, stdin);
        clearScreen();                      // optionally

        switch (user_choice[0]) {

            case '0':

                break;

            case '1':
                addTask(list);
                break;

            case '2':

                break;

            case '3':

                break;

            case '4':

                break;

            case '5':

                break;

            case '6':
                break;

            case '7':

                break;

            case '8':

                break;

            case '9':

                break;

            case 'q':

              printf("\n╭────────────────────────╮\n");
                printf("│        Выход           │\n");
                printf("╰────────────────────────╯\n");

                printf("Выход в меню выбора");
                loadingAnimation(3, 250);
                running = 0;
                return;

            default:
              printf("\n╔══════════════════════════════════════╗\n");
                printf("║        Неизвестная команда!          ║\n");
                printf("║     Пожалуйста, попробуйте ещё раз.  ║\n");
                printf("╚══════════════════════════════════════╝\n\n");


        }
        printf("\nНажмите Enter для продолжения...");
        getchar();

    }

}





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

      printf("\n╭───────────────────────────────────╮\n");
        printf("│        Введите команду:           │\n");
        printf("╰───────────────────────────────────╯\n");
        printf("╰─> ");

        int choice = execute_verification(1, 3);
        switch (choice)
        {
            case 1:
                printf("\n     Запуск");
                loadingAnimation(3,250);
                task_manager_menu();
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
                printf("Неверный выбор! Попробуйте еще раз.\n");

        }

    }


}
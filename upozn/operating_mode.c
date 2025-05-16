//
// Created by jegorix on 26.04.25.
//

#include "operating_mode.h"
#include "validators.h"
#include "task_operations.h"
#include "getch_unix_without_conio.h"
#include "tasks_sorting_q_sort.h"




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

//        char user_choice[10];
//        fgets(user_choice, 10, stdin);
          char user_choice = fgetch();

//            printf("Загрузка");
//            loadingAnimation(3, 150);
            clearScreen();

        clearScreen();                      // optionally

        switch (user_choice) {

            case '0':

                break;

            case '1':
                addTask(list);
                break;

            case '2':
printf("────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
                showTasks(list);
                break;

            case '3':
                editTask(list);
                break;

            case '4':

                break;

            case '5':
                markCompleteTask(list);
                break;

            case '6':
                deleteTask(list);
                break;

            case '7':
                searchTask(list);
                break;

            case '8':
                clearTasks(list);
                break;

            case '9':
                taskSortMenu(list);
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

//        int choice = execute_verification(1, 3);
        char choice = fgetch();
        switch (choice)
        {
            case '1':
                printf("\n     Запуск");
                loadingAnimation(3,250);
                task_manager_menu();
                break;

            case '2':
                break;

            case '3':
                printf("\n    Выход в главное меню");
                loadingAnimation(3,250);
                clearScreen();
                running = 0;
                return;

            default:
              printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│                    Неверный выбор!                     │\n");
                printf("│                  Попробуйте еще раз.                   │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");

        }

    }


}
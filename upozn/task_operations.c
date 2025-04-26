//
// Created by jegorix on 26.04.25.
//

#include "task_operations.h"


void addTask(TaskList* list)
{
    if(list->size >= list->capacity)
    {
        list->capacity += 3;
        list->tasks = realloc(list->tasks, list->capacity * sizeof(Task));
    }

    Task* new_task = &list->tasks[list->size];
    new_task->id = list->size + 1;

    char buffer[256];

  printf("\n╭───────────────────────────────────╮\n");
    printf("│     Введите название задачи:      │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    new_task->title = buffer;
    printf("\n");

  printf("\n╭───────────────────────────────────╮\n");
    printf("│     Введите описание задачи:      │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("╰─> ");

    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    new_task->description = buffer;
    printf("\n");

    printf("\n╭────────────────────────────────────────╮\n");
    printf("│ Введите день выполнения задачи (1-31): │\n");
    printf("╰────────────────────────────────────────╯\n");
    printf("╰─> ");

    int day = execute_verification(1,31);
    new_task->day = day;
    printf("\n");

  printf("\n╭─────────────────────────────────────────╮\n");
    printf("│ Введите месяц выполнения задачи (1-31): │\n");
    printf("╰─────────────────────────────────────────╯\n");
    printf("╰─> ");

    int month = execute_verification(1,12);
    new_task->month = month;
    printf("\n");

  printf("\n╭────────────────────────────────────────╮\n");
    printf("│     Введите год выполнения задачи:     │\n");
    printf("╰────────────────────────────────────────╯\n");
    printf("╰─> ");

    int year = execute_verification(2025, max_limit);
    new_task->year = year;
    printf("\n");

  printf("\n╭────────────────────────────────────────╮\n");
    printf("│ Введите приоритет задачи:              │\n");
    printf("│ (1 - высокий, 2 - средний, 3 - низкий) │\n");
    printf("╰────────────────────────────────────────╯\n");
    printf("╰─> ");

    int priority = execute_verification(1, 3);
    new_task->priority = priority;
    printf("\n");

    new_task->status = 0;
    list->size++;

  printf("\n╔════════════════════════════════════════════╗\n");
    printf("║        Задача успешно добавлена!           ║\n");
    printf("╚════════════════════════════════════════════╝\n");


}







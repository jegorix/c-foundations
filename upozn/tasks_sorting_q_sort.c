//
// Created by jegorix on 14.05.25.
//

#include "tasks_sorting_q_sort.h"

int compare_by_priority(void* ascending, const void* a, const void* b)
{
    int condition = *(int*)ascending;
    Task* task_a = (Task*) a;
    Task* task_b = (Task*) b;
    int result = task_a->priority - task_b->priority;
    return condition ? result: -result;
}


int compare_by_status(void* ascending, const void* a, const void* b)
{
    int condition = *(int*) ascending;
    Task* task_a = (Task*) a;
    Task* task_b = (Task*) b;
    int result = task_a->status - task_b->status;
    return condition ? result: -result;

}

int compare_by_deadline(void* ascending, const void* a, const void* b)
{
    int condition = *(int*) ascending;
    Task* task_a = (Task*) a;
    Task* task_b = (Task*) b;
    int result = task_a->deadline - task_b->deadline;
    return condition ? result: -result;
}


int compare_by_id(void* ascending, const void* a, const void* b)
{
    int condition = *(int*) ascending;
    Task* task_a = (Task*) a;
    Task* task_b = (Task*) b;
    int result = task_a->id - task_b->id;
    return condition ? result: -result;
}

void exit_sorting()
{
    printf("\n╭────────────────────────────────────────────────────────╮\n");
    printf("│               Выход из режима сортировки               │\n");
    printf("╰────────────────────────────────────────────────────────╯\n");
    printf("     Сохранение изменений");
    loadingAnimation(3, 250);
}



int ascending_answer()
{
    printf("\n╭────────────────────────────────────────────────╮\n");
    printf("│          Выберите порядок сортировки:          │\n");
    printf("│               1 - по возрастанию               │\n");
    printf("│               2 - по убыванию                  │\n");
    printf("╰────────────────────────────────────────────────╯\n");
    printf("╰─> ");

    int ascending = execute_verification(1,2);
    ascending = (ascending == 1) ? 1 : 0;
    return ascending;
}




void taskSortMenu(TaskList* list) {
    if (list->size == 0) {
        printf("\n╭────────────────────────────────────────────────────────╮\n");
        printf("│                  Список задач пуст.                    │\n");
        printf("╰────────────────────────────────────────────────────────╯\n");
        return;
    }

    TasksShortList(list);
    int running = 1;
    int ascending;

    while (running) {
        printf("\n╭─────────────────────────────────────────────────────────╮\n");
        printf("│               Как вы хотите отсортировать?              │\n");
        printf("╠═════════════════════════════════════════════════════════╣\n");
        printf("│ 1 - По приоритету                                       │\n");
        printf("│ 2 - По статусу                                          │\n");
        printf("│ 3 - По сроку выполнения                                 │\n");
        printf("│ 4 - По номеру задач                                     │\n");
        printf("│ 5 - Просмотреть список задач                            │\n");
        printf("│ 6 - Выход                                               │\n");
        printf("╰─────────────────────────────────────────────────────────╯\n");
        printf("╰─> ");

        char choice = fgetch();


        switch(choice){
            case '1':
                ascending = ascending_answer();
                qsort_r(list->tasks, list->size, sizeof(Task), &ascending,compare_by_priority);
              printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│         Задачи отсортированы по приоритету.            │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");
                break;

            case '2':
                ascending  = ascending_answer();
                qsort_r(list->tasks, list->size, sizeof(Task), &ascending, compare_by_status);
              printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│            Задачи отсортированы по статусу.            │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");
                break;

            case '3':
                ascending = ascending_answer();
                qsort_r(list->tasks, list->size, sizeof(Task), &ascending, compare_by_deadline);
              printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│        Задачи отсортированы по сроку выполнения.       │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");
                break;

            case '4':
                ascending = ascending_answer();
                qsort_r(list->tasks, list->size, sizeof(Task), &ascending, compare_by_id);
              printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│      Задачи отсортированы по порядковому номеру.       │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");
                break;

            case '5':
                TasksShortList(list);
                break;

            case '6':
                exit_sorting();
                running = 0;
                break;

            default:
                printf("\n╭────────────────────────────────────────────────────────╮\n");
                printf("│         Неверный выбор! Попробуйте ещё раз.            │\n");
                printf("╰────────────────────────────────────────────────────────╯\n");
                break;


        }


    }


}
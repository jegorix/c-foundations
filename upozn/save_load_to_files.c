//
// Created by jegorix on 17.05.25.
//

#include "save_load_to_files.h"


int isValidTaskFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
        return 0;

    int id = 0, title = 0, date = 0;
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "Задача №", 8) == 0) id = 1;
        else if (strncmp(line, "Название:", 9) == 0) title = 1;
        else if (strncmp(line, "Срок выполнения до", 18) == 0) date = 1;

        if (id && title && date)
            break;
    }

    fclose(file);
    return id && title && date;
}



void loadTasks(TaskList* list, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if(!file)
    {
        printf("\n╭────────────────────────────────────────╮\n");
        printf("│       Ошибка при открытии файла.       │\n");
        printf("╰────────────────────────────────────────╯\n");
        printf("\n");
        return;
    }

    Task temp;
    char line[256];
    temp.title = malloc(128);
    temp.description = malloc(256);

    while(fgets(line, sizeof(line), file))
    {

        if(strncmp(line, "Задача №", 8) == 0) sscanf(line, "Задача №%d", &temp.id);

        else if(strncmp(line, "Название:", 9) == 0) sscanf(line, "Название: %[^\n]", temp.title);

        else if(strncmp(line, "Описание:", 9) == 0) sscanf(line, "Описание: %[^\n]", temp.description);

        else if(strncmp(line, "Срок выполнения до", 18) == 0) sscanf(line, "Срок выполнения до %d.%d.%d", &temp.day, &temp.month, &temp.year);

        else if(strncmp(line, "Задача высокой важности.", 24) == 0) temp.priority = 1;

        else if(strncmp(line, "Задача средней важности.", 24) == 0) temp.priority = 2;

        else if(strncmp(line, "Задача низкой важности.", 23) == 0) temp.priority = 3;

        else if(strncmp(line, "Задача выполнена!", 17) == 0) temp.status = 1;

        else if(strncmp(line, "Задача не выполнена!", 20) == 0) temp.status = 0;

        else if(strncmp(line, "──────────────────────────────────", 34) == 0)
        {
            if(list->size >= list->capacity)
            {
                list->capacity += 3;
               Task* new_tasks = realloc(list->tasks, list->capacity * sizeof(Task));
               if(new_tasks == NULL)
               {
                   printf("ошибка выделения памяти при загрузке задач\n");
                   fclose(file);
                   return;
               }
               list->tasks = new_tasks;
            }
            list->tasks[list->size].id = temp.id;
            list->tasks[list->size].title = strdup(temp.title);
            list->tasks[list->size].description = strdup(temp.description);
            list->tasks[list->size].day = temp.day;
            list->tasks[list->size].month = temp.month;
            list->tasks[list->size].year = temp.year;
            list->tasks[list->size].priority = temp.priority;
            list->tasks[list->size].status = temp.status;
            list->size++;


        }

    }

    fclose(file);

    printf("\n     Загрузка");
    loadingAnimation(3, 250);

    printf("\n╭────────────────────────────────────────────╮\n");
    printf("│     Задачи успешно загружены из файла!     │\n");
    printf("╰────────────────────────────────────────────╯\n");

    free(temp.title);
    free(temp.description);

}





void saveTasks(TaskList* list, const char* filename)
{

    FILE* file = fopen(filename, "w");
    if(!file)
    {
      printf("\n╭────────────────────────────────────────╮\n");
        printf("│       Ошибка при открытии файла.       │\n");
        printf("╰────────────────────────────────────────╯\n");
        printf("\n");
        return;
    }
    for(int i = 0; i < list->size; i++)
    {
        Task* task = &list->tasks[i];
        fprintf(file, "Задача №%d\n", task->id);
        fprintf(file, "Название: %s\n",task->title);
        fprintf(file, "Описание: %s\n", task->description);
        fprintf(file, "Срок выполнения до %02d.%02d.%04d\n", task->day, task->month, task->year);
        switch(task->priority)
        {
            case 1:
                fprintf(file, "Задача высокой важности.\n");
                break;
            case 2:
                fprintf(file, "Задача средней важности.\n");
                break;
            case 3:
                fprintf(file, "Задача низкой важности.\n");
                break;
        }

        if(task->status)
        {
            fprintf(file, "Задача выполнена!\n");
        }
        else
        {
            fprintf(file, "Задача не выполнена!\n");
        }
        fprintf(file, "──────────────────────────────────\n");
    }

    fclose(file);

    printf("\n     Сохранение");
    loadingAnimation(3, 250);

    printf("\n╭──────────────────────────────────────────────╮\n");
    printf("│   Все задачи успешно сохранены в файл!       │\n");
    printf("╰──────────────────────────────────────────────╯\n");

}





void fileTasksMenu(TaskList* list, int flag)
{
    char buffer[256];
    char* stripped_buffer;
    const char* folder = "tasks/";
    char full_path[512];

        do {
            printf("\n╭────────────────────────────────────────────────────────╮\n");
            printf("│            Введите имя файла с расширением.            │\n");
            printf("╰────────────────────────────────────────────────────────╯\n");
            printf("╰─> ");
//            int c;
//            while ((c = getchar()) != '\n' && c != EOF);
            fgets(buffer, 256, stdin);
            buffer[strcspn(buffer, "\n")] = 0;

            stripped_buffer = strip(buffer);

            if (strlen(stripped_buffer) == 0) {
                printf("\n╭────────────────────────────────────────╮\n");
                printf("│     Имя файла не может быть пустым.    │\n");
                printf("╰────────────────────────────────────────╯\n");
                printf("\n");
            }


        } while (strlen(stripped_buffer) == 0);

        snprintf(full_path, sizeof(full_path), "%s%s", folder, stripped_buffer);
//        printf("%s\n", full_path);

      if(flag)
      {
          saveTasks(list, full_path);
      }

      else
      {
          int value = isValidTaskFile(full_path);
          if (value)
          {
              loadTasks(list, full_path);
          }
          else
          {
            printf("\n╔═══════════════════════════════════════════════════╗\n");
              printf("║                    ОШИБКА                         ║\n");
              printf("║  Файл не прошёл проверку на валидность!           ║\n");
              printf("║  Убедитесь, что файл существует, и                ║\n");
              printf("║  каждая задача содержит:                          ║\n");
              printf("║                                                   ║\n");
              printf("║  • Номер задачи (Задача №...)                     ║\n");
              printf("║  • Название                                       ║\n");
              printf("║  • Срок выполнения                                ║\n");
              printf("║  • Уровень важности                               ║\n");
              printf("║  • Статус выполнения                              ║\n");
              printf("╚═══════════════════════════════════════════════════╝\n\n");
          }

      }


}
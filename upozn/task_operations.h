//
// Created by jegorix on 26.04.25.
//

#ifndef UPOZN_TASK_OPERATIONS_H
#define UPOZN_TASK_OPERATIONS_H
#include "validators.h"
#include <string.h>

typedef struct
{
    int id;
    char* title;
    char* description;
    int day;
    int month;
    int year;
    int priority;
    int status;

}Task;

typedef struct
{
    Task* tasks;
    int size;
    int capacity;
}TaskList;

void addTask(TaskList* list);
void showTasks(TaskList* list);


#endif //UPOZN_TASK_OPERATIONS_H

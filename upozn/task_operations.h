//
// Created by jegorix on 26.04.25.
//

#ifndef UPOZN_TASK_OPERATIONS_H
#define UPOZN_TASK_OPERATIONS_H
#include "validators.h"
#include <string.h>
#include "getch_unix_without_conio.h"


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
    int deadline;

}Task;

typedef struct
{
    Task* tasks;
    int size;
    int capacity;
}TaskList;

void addTask(TaskList* list);
void showTasks(TaskList* list);
void editTask(TaskList* list);
void TasksShortList(TaskList* list);
void markCompleteTask(TaskList* list);
void deleteTask(TaskList* list);
void searchTask(TaskList* list);
void show_micro_task(Task* task);
void clearTasks(TaskList* task);
void freeTasks(TaskList* list, int criteria);
int calculate_deadline(Task* task);


#endif //UPOZN_TASK_OPERATIONS_H

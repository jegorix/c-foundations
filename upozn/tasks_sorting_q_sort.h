//
// Created by jegorix on 14.05.25.
//

#ifndef UPOZN_TASKS_SORTING_Q_SORT_H
#define UPOZN_TASKS_SORTING_Q_SORT_H
#include "task_operations.h"
#include "operating_mode.h"

void taskSortMenu(TaskList* list);
int compare_by_priority(void* condition, const void* a, const void* b);
int ascending_answer();
void exit_sorting();

#endif //UPOZN_TASKS_SORTING_Q_SORT_H

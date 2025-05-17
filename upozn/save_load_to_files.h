//
// Created by jegorix on 17.05.25.
//

#ifndef UPOZN_SAVE_LOAD_TO_FILES_H
#define UPOZN_SAVE_LOAD_TO_FILES_H
#include "task_operations.h"
#include "operating_mode.h"
void saveTasks(TaskList* list, const char* filename);
void fileTasksMenu(TaskList* list, int flag);
void loadTasks(TaskList* list, const char* filename);
#endif //UPOZN_SAVE_LOAD_TO_FILES_H

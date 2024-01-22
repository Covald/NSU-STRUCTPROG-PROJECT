//
// Created by covald on 22.01.24.
//

#ifndef CPROJECT_TASK_H
#define CPROJECT_TASK_H

#endif //CPROJECT_TASK_H
#include "my_string.h"

typedef struct Task {
    char *title;
    char *text;
    int priority;
    char due_date[20];
} Task;


//Task create_task(char *title, char *text, int priority, const char due_date[20]);

Task *task_create_by_cli();

void task_print(Task *task);

void task_free(Task *task);

void task_edit_text(Task *task);


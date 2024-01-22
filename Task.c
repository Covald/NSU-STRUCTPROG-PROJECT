//
// Created by covald on 22.01.24.
//

#include "Task.h"

// Функция для создания задачи с вводом данных из консоли
Task *task_create_by_cli() {
    system("clear");
    flushBuffer();

    Task *newTask = malloc(sizeof(Task));

    printf("Введите заголовок задачи: ");
    newTask->title = read_string();

    printf("Введите текст задачи: ");
    newTask->text = read_string();

    printf("Введите приоритет задачи (целое число): ");
    scanf("%d", &newTask->priority);

    printf("Введите дату задачи (формат YYYY-MM-DD): ");
    scanf("%s", newTask->due_date);
    return newTask;
}

void task_print(Task *task) {
    printf("Дата: %s\n", task->due_date);
    printf("Приоритет: %d\n", task->priority);
    printf("Заголовок: %s\n", task->title);
    printf("Текст задачи: %s\n", task->text);
}

// Функция для освобождения памяти, выделенной под заголовок и текст задачи
void task_free(Task *task) {
    free(task->title);
    free(task->text);
    free(task);
}

void task_edit_text(Task *task) {
    system("clear");
    flushBuffer();
    printf("Введите новый текст: \n");
    char *new_text = read_string();
    free(task->text);
    task->text = new_text;
}
//
// Created by covald on 22.01.24.
//

#ifndef CPROJECT_BST_H
#define CPROJECT_BST_H

#endif //CPROJECT_BST_TODO_LIST_H

#include <string.h>
#include "Task.h"

typedef struct Node {
    Task *task;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BST {
    char *name;
    int tasks_count;
    Node *root;
    struct BST *next;
} BST;

BST *bst_create(char *name, Node *root);

BST *bst_create_by_cli();

// Функция для вставки задачи в BST
Node *bst_insert_task(BST *root, Task *task);

void bst_print_tasks(BST *bst);

// Функция для поиска задачи по номеру
Node *bst_find_task_by_number(BST *bst, int number);

// Функция для редактирования текста задачи
//void editTaskText(Node *root, const char *due_date, const char *new_task_text);
Node *bst_delete_node(BST *bst, Node *node);

// Функция для удаления задачи по дате
//Node *deleteTask(Node *root, const char *due_date);
//
//
//// Функция для удаления задачи по номеру
//Node *deleteTaskByNumber(Node *root, int number);

//void editTaskTextByNumber(Node *root, int number, const char *new_task_text);
// Функция для вывода всех задач в порядке сортировки по дате с нумерацией


// Освобождение памяти, выделенной для BST
void *bst_free(BST *bst);

//
// Created by covald on 23.01.24.
//

#include "todo.h"

TODO *todo_init() {
    TODO *todo = malloc(sizeof(TODO));
    todo->len = 0;
    todo->lists = NULL;
    return todo;
}

void todo_append_bst(TODO *todo, BST *bst) {
    if (todo->lists == NULL) {
        todo->lists = bst;
        todo->len++;
        return;
    }
    BST *temp = todo->lists;
    while (temp->next != NULL) { temp = temp->next; }
    temp->next = bst;
    todo->len++;
}

void todo_delete_bst_by_number(TODO *todo, int num) {
    int counter = 2;
    if (todo->lists == NULL) {
        fprintf(stderr, "Попытка удаления из пустого списка.");
        return;
    }
    if (num == 1) {
        BST *temp = todo->lists->next;
        if (temp != NULL) { bst_free(temp); }
        free(todo->lists);
        todo->lists = temp;
        todo->len--;
        return;
    }
    BST *temp_prev = todo->lists;
    BST *temp = temp_prev->next;
    while (counter < num) {
        if (temp->next == NULL) {
            fprintf(stderr, "В списке списков задач не найден удаляемый список.");
            return;
        }
        counter++;
        temp_prev = temp;
        temp = temp->next;
    }
    temp_prev->next = temp->next;
    bst_free(temp);
    todo->len--;
}

void todo_print(TODO *todo) {
    printf("TODO СПИСКИ.\n");
    printf("--------------------------------------------------------------------------------------------\n");
    if (todo->lists == NULL || todo->len == 0) {
        printf("Списков нет.\n");
    } else {
        int counter = 1;
        BST *temp = todo->lists;
        while (temp != NULL) {
            printf("%d. %s\n", counter, temp->name);
            counter++;
            temp = temp->next;
        }
    }
}

BST *todo_find_bst_by_idx(TODO *todo, int idx) {
    if (idx > todo->len || todo->lists == NULL) {
        fprintf(stderr, "Попытка поиска провалилась.");
        return NULL;
    }
    BST *temp = todo->lists;
    int counter = 1;
    while (counter != idx) {
        temp = temp->next;
        counter++;
    }
    return temp;
}
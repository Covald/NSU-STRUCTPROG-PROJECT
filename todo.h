//
// Created by covald on 23.01.24.
//

#ifndef CPROJECT_TODO_H
#define CPROJECT_TODO_H

#endif //CPROJECT_TODO_H

#include "BST.h"

typedef struct TODO {
    BST *lists;
    int len;
} TODO;

TODO *todo_init();

void todo_append_bst(TODO *todo, BST *bst);

void todo_delete_bst_by_number(TODO *todo, int num);

void todo_print(TODO *todo);

BST *todo_find_bst_by_idx(TODO *todo, int idx);
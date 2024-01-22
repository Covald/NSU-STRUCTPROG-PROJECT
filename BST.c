//
// Created by covald on 23.01.24.
//

#include "BST.h"

int taskCounter = 0;

BST *bst_create(char *name, Node *root) {
    BST *temp = malloc(sizeof(BST));
    temp->name = name;
    temp->tasks_count = 0;
    temp->root = root;
    temp->next = NULL;
    return temp;
}

BST *bst_create_by_cli() {
    flushBuffer();
    printf("Введите название списка дел: ");
    char *temp_name = read_string();
    BST *temp = bst_create(temp_name, NULL);
    return temp;
}

Node *_createNode(Task *task) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->task = task;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

Node *_find_min_node(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node *_insert_task(Node *root, Task *task) {
    if (root == NULL) {
        return _createNode(task);
    }

    // Сравниваем даты для определения порядка вставки
    int dateComparison = strcmp(task->due_date, root->task->due_date);

    if (dateComparison < 0) {
        root->left = _insert_task(root->left, task);
    } else if (dateComparison > 0) {
        root->right = _insert_task(root->right, task);
    }

    return root;
}

// Функция для вставки задачи в BST
Node *bst_insert_task(BST *bst, Task *task) {
    Node *root = bst->root;
    bst->tasks_count++;
    bst->root=_insert_task(root, task);
    return bst->root;
}

int _print_tasks(Node *root) {
    if (root != NULL) {
        _print_tasks(root->left);
        printf("%d. Дата выполнения: %s, Приоритет: %d, Заголовок: %s\n", ++taskCounter,
               root->task->due_date, root->task->priority, root->task->title);
        _print_tasks(root->right);
    }
    return taskCounter;
}

void bst_print_tasks(BST *bst) {
    taskCounter = 0;
    bst->tasks_count = _print_tasks(bst->root);
}

// Функция для поиска задачи по номеру
Node *_find_task_by_number(Node *root, int number) {
//TODO Optimize
    if (root != NULL) {
        if (taskCounter == number) {
            return root;
        }

        taskCounter++;
        Node *leftResult = _find_task_by_number(root->left, number);
        if (leftResult != NULL) {
            return leftResult;
        }

        Node *rightResult = _find_task_by_number(root->right, number);
        if (rightResult != NULL) {
            return rightResult;
        }
    }

    return NULL;
}

Node *bst_find_task_by_number(BST *bst, int number) {
    return _find_task_by_number(bst->root, number);
}

// Функция для удаления задачи по ноде
Node *_delete_node(Node *root, Node *nodeToDelete) {
    if (root == NULL) {
        return root;
    }

    // Рекурсивный вызов для поиска узла
    if (nodeToDelete->task->due_date < root->task->due_date) {
        root->left = _delete_node(root->left, nodeToDelete);
    } else if (nodeToDelete->task->due_date > root->task->due_date) {
        root->right = _delete_node(root->right, nodeToDelete);
    } else {
        // Нашли узел для удаления

        // У удаляемой ноды нет потомков или только один потомок
        if (root->left == NULL) {
            Node *temp = root->right;
            task_free(root->task);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            task_free(root->task);
            free(root);
            return temp;
        }

        // У удаляемой ноды два потомка
        Node *temp = _find_min_node(
                root->right); // Или findMaxNode(root->left) для нахождения максимального узла в левом поддереве
        root->task = temp->task;
        root->right = _delete_node(root->right, temp);
    }

    return root;
}

Node *bst_delete_node(BST *bst, Node *node) {
    bst->root = _delete_node(bst->root, node);
    bst->tasks_count--;
    return bst->root;
}


void _free(Node *root) {
    if (root != NULL) {
        _free(root->left);
        _free(root->right);
        task_free(root->task);
        free(root);
        root = NULL;
    }
}

// Освобождение памяти, выделенной для BST
void *bst_free(BST *bst) {
    _free(bst->root);
    free(bst);
    return NULL;
}

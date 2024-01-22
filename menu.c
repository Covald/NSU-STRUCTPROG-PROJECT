//
// Created by covald on 23.01.24.
//

#include "menu.h"

void print_break() {
    printf("--------------------------------------------------------------------------------------------\n");
}

int bst_menu_confirm_deleting(BST *bst, Node *node) {
    system("clear");
    int choice;
    while (1) {
        flushBuffer();
        printf("Вы действительно хотите удалить эту задачу?\n");
        printf("1. Да.\n");
        printf("2. Нет.\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bst_delete_node(bst, node);
                system("clear");
                return 1;
            case 2:
                system("clear");
                return 0;
            default:
                system("clear");
                printf("Unavailable selection.\n");
        }
    }
}

void bst_menu_edit_task(BST *bst, Node *node) {
    system("clear");
    int choice;
    int is_deleted = 0;
    while (1) {
        flushBuffer();
        task_print(node->task);
        print_break();
        printf("МЕНЮ:\n");
        printf("0. Вернуться назад.\n");
        printf("1. Редактировать текст задачи.\n");
        printf("2. Удалить задачу.\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                system("clear");
                return;
            case 1:
                task_edit_text(node->task);
                system("clear");
                continue;
            case 2:
                is_deleted = bst_menu_confirm_deleting(bst, node);
                if (is_deleted == 1) { return; }
                system("clear");
            default:
                system("clear");
                printf("Unavailable selection.\n");
        }
    }
}

void bst_menu_main(BST *bst) {
    system("clear");
    int choice;
    while (1) {
        flushBuffer();
        printf("Имя списка: %s\n", bst->name);
        printf("Кол-во задач: %d\n", bst->tasks_count);
        print_break();
        bst_print_tasks(bst);
        int len = bst->tasks_count;
        print_break();
        printf("МЕНЮ:\n");
        printf("-1. Добавить задачу.\n");
        printf("0. Вернуться назад.\n");
        if (bst->root != NULL && len != 0) {
            printf("1-%d. Редактирование задачи под номером 1-%d.\n", len, len);
        }
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        if (choice == -1) {
            Task *temp = task_create_by_cli();
            bst_insert_task(bst, temp);
            system("clear");
        } else if (choice == 0) {
            system("clear");
            break;
        } else if (0 < choice && choice <= len) {
            bst_menu_edit_task(bst, bst_find_task_by_number(bst, choice));
            system("clear");
        } else {
            system("clear");
            printf("Unavailable selection.\n");
        }
    }
}

void todo_menu_show(TODO *todo) {
    system("clear");
    int choice;
    while (1) {
        flushBuffer();
        todo_print(todo);
        print_break();
        printf("МЕНЮ:\n");
        printf("0. Вернуться назад.\n");
        if (!(todo->lists == NULL || todo->len == 0)) {
            printf("1-%d. Редактирование списка под номером 1-%d\n", todo->len, todo->len);
        }
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 0) { system("clear");break; }
        else {
            if (todo->lists == NULL || todo->len == 0 || choice < 1) {
                system("clear");
                printf("Unavailable selection.\n");
            } else {
                bst_menu_main(todo_find_bst_by_idx(todo, choice));
                system("clear");
            }
        }
    }
}

void todo_menu_create(TODO *todo) {
    system("clear");
    BST *temp = bst_create_by_cli();
    todo_append_bst(todo, temp);
    system("clear");
}

void todo_menu_delete(TODO *todo) {
    system("clear");
    int choice;
    while (1) {
        flushBuffer();
        todo_print(todo);
        print_break();
        printf("МЕНЮ:\n");
        printf("0. Вернуться назад.\n");
        if (!(todo->lists == NULL || todo->len == 0)) {
            printf("1-%d. Удаление списка под номером 1-%d\n", todo->len, todo->len);
        }
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        if (choice == 0) {system("clear"); break; }
        else {
            if (todo->lists == NULL || todo->len == 0) {
                system("clear");
                printf("Unavailable selection.\n");
            } else {
                todo_delete_bst_by_number(todo, choice);
                system("clear");
                printf("Список удалён.\n");
            }
        }
    }
}

void todo_menu_main(TODO *todo) {
    int choice;
    system("clear");
    while (1) {
        printf("0. Exit.\n");
        printf("1. Show TODO lists.\n");
        printf("2. Create new TODO list.\n");
        printf("3. Delete TODO list.");
        printf("\n\n\nEnter your choice\t:\t");

// Choice from the user
        scanf("%d", &choice);

        switch (choice) {

// Calling functions defined
// below as per the user input
            case 0:
                exit(1);
            case 1:
                todo_menu_show(todo);
                system("clear");
                continue;
            case 2:
                todo_menu_create(todo);
                system("clear");
                continue;
            case 3:
                todo_menu_delete(todo);
                system("clear");
                continue;
            default:
                system("clear");
                printf("\nInvalid Choice :-(\n");
        }
    }
}
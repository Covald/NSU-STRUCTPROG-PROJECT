cmake_minimum_required(VERSION 3.27)
project(Cproject C)

set(CMAKE_C_STANDARD 23)

add_executable(Cproject main.c
        Task.c
        Task.h
        my_string.c
        my_string.h
        menu.c
        menu.h
        todo.c
        todo.h
        BST.c
        BST.h
)

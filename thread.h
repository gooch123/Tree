//
// Created by gooch on 2023-12-08.
//

#ifndef TREE_CODING_THREAD_H
#define TREE_CODING_THREAD_H
#include <stdlib.h>
#include <stdio.h>

typedef struct thread{
    short int left_thread;
    struct thread *left_child;

    char data;
    short int right_thread;
    struct thread *right_child;

}THREAD;

THREAD* new_thread(char data,short int,short int);
void make_thread_tree(THREAD*);
void inorder_thread_1(THREAD * ptr);
THREAD *insucc(THREAD *ptr);
void tinorder(THREAD* node);
void insert_right(THREAD*,THREAD*);

void thread_exec();

#endif //TREE_CODING_THREAD_H

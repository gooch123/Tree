//
// Created by gooch on 2023-12-07.
//
#include "copy.h"
#include "tree_traversal.h"
#include <stdio.h>

NODE* tree_pointer_copy(NODE* original){
    NODE* temp;
    if(original){
        temp = (NODE*) malloc(sizeof (NODE));
        temp->data = original->data;
        temp->left_child = original->left_child;
        temp->right_child = original->right_child;
        return temp;
    }
    return NULL;
}

void copy_exec(){
    NODE* ptr = (NODE*)malloc(sizeof (NODE)), *copy;
    makeTree(ptr);
    copy = tree_pointer_copy(ptr);
    printf("original : ");
    inorder(ptr);
    printf("\ncopy : ");
    inorder(copy);
}

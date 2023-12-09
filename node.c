//
// Created by gooch on 2023-12-07.
//
#include "node.h"
#include "tree_traversal.h"
#include <stdlib.h>

NODE* new_node(){
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    temp->right_child = NULL;
    temp->left_child = NULL;
    return temp;
}
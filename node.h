//
// Created by gooch on 2023-12-07.
//

#ifndef TREE_CODING_NODE_H
#define TREE_CODING_NODE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node* left_child;
    struct node* right_child;
}NODE;

NODE* new_node();

#endif //TREE_CODING_NODE_H

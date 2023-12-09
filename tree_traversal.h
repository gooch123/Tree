//
// Created by gooch on 2023-12-07.
//

#ifndef TREE_CODING_TREE_TRAVERSAL_H
#define TREE_CODING_TREE_TRAVERSAL_H
#include "node.h"


NODE* new_node();
void makeTree(NODE*);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
void tree_traversal_exec();

#endif //TREE_CODING_TREE_TRAVERSAL_H

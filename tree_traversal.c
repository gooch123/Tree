//
// Created by gooch on 2023-12-07.
//
#include <stdlib.h>
#include <stdio.h>
#include "tree_traversal.h"
#include "node.h"

void makeTree(NODE* root) {
    NODE* temp;
    root->data = '+';

    temp = new_node();
    temp->data = 'E';
    root->right_child = temp;
    temp = new_node();
    temp->data = '*';
    root->left_child = temp;
    root = root->left_child;

    temp = new_node();
    temp->data = 'D';
    root->right_child = temp;
    temp = new_node();
    temp->data = '*';
    root->left_child = temp;
    root = root->left_child;

    temp = new_node();
    temp->data = 'C';
    root->right_child = temp;
    temp = new_node();
    temp->data = '/';
    root->left_child = temp;
    root = root->left_child;

    temp = new_node();
    temp->data = 'B';
    root->right_child = temp;
    temp = new_node();
    temp->data = 'A';
    root->left_child = temp;
    root = root->left_child;
}

void inorder(NODE* ptr) {
    if (ptr != NULL) {
        inorder(ptr->left_child);
        printf("%c ", ptr->data);
        inorder(ptr->right_child);
    }
}

void preorder(NODE* ptr) {
    if (ptr != NULL) {
        printf("%c ", ptr->data);
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

void postorder(NODE* ptr) {
    if (ptr != NULL) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%c ", ptr->data);
    }
}

void tree_traversal_exec(){
    NODE* tree = new_node();
    makeTree(tree);
    printf("inorder_traversal : ");
    inorder(tree);
    putchar('\n');
    printf("preorder_traversal : ");
    preorder(tree);
    putchar('\n');
    printf("postorder_traversal : ");
    postorder(tree);
}

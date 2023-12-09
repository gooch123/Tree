//
// Created by gooch on 2023-12-08.
//
#include "get_node_count.h"
#include "tree_traversal.h"

int get_node_count(NODE* root){
    int count = 0;
    if(root != NULL){
        count = 1+ get_node_count(root->left_child) + get_node_count(root->right_child);
    }
    return count;
}

int leaf_node_count(NODE* root){
    int count = 0;
    if(root != NULL){
        if(root->right_child == NULL && root->left_child == NULL)
            return 1;
        else
            count = leaf_node_count(root->left_child) + leaf_node_count(root->right_child);
    }
    return count;
}

void count_exec(){
    int count;
    NODE* root = (NODE*) malloc(sizeof (NODE));
    makeTree(root);
    count = get_node_count(root);
    printf("노드의 수 : %d",count);
}

void leaf_count_exec(){
    int count;
    NODE* root = (NODE*) malloc(sizeof (NODE));
    makeTree(root);
    count = leaf_node_count(root);
    printf("\n단말 노드의 수 : %d",count);
}


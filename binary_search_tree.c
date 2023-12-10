//
// Created by gooch on 2023-12-09.
//
#include "binary_search_tree.h"

B_NODE *recur_search(B_NODE* tree,int key){

    if(tree == NULL) return NULL;
    if(key == tree->data) return tree;
    if(key > tree->data) return recur_search(tree->right_child,key);
    else return recur_search(tree->left_child,key);

}

B_NODE* iter_search(B_NODE* tree,int key){

    while (tree->data != key){
        if(tree == NULL) return NULL;
        if(key > tree->data) tree = tree->right_child;
        else tree = tree->left_child;
    }
    return tree;
}

B_NODE *modified_search(B_NODE* root,int data){

    for(B_NODE* ptr = root;root != NULL; ){
        if(root->data == data)
            return NULL;
        if(data > root->data)
            if(ptr->right_child == NULL) return ptr;
            else root = root->right_child;
        else
            if(ptr->left_child == NULL) return ptr;
            else root = root->left_child;
    }
    return NULL;
}


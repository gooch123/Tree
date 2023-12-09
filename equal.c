//
// Created by gooch on 2023-12-08.
//

#include "equal.h"
#include "tree_traversal.h"
#include <stdio.h>

int equal(NODE* first, NODE* second){

    return ((!first&&!second)||(first && second && (first->data == second->data) &&
    equal(first->left_child , second->left_child) &&
            equal(first->right_child , second->right_child)));
}

void differ_tree(NODE* node){
    node= new_node();
    node->data = '+';
}

void equal_exec(){
    int result;
    NODE* tree1 = (NODE*) malloc(sizeof (NODE));
    NODE* tree2 = (NODE*) malloc(sizeof (NODE));
    NODE* tree3 = NULL;
    makeTree(tree1);
    makeTree(tree2);
    differ_tree(tree3);
    result = equal(tree1,tree2);
    if(result) printf("같은 트리입니다.");
    else printf("다른 트리입니다.");
}




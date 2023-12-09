//
// Created by gooch on 2023-12-08.
//
#include "thread.h"

THREAD* new_thread(char data,short int left_thread,short int right_thread){
    THREAD* node = (THREAD*) malloc(sizeof (THREAD));
    node->data = data;
    node->left_thread = left_thread;
    node->right_thread = right_thread;
    node->right_child = NULL;
    node->left_child = NULL;
    return node;
}

void make_thread_tree(THREAD* root){
    THREAD *node1,*node2,*node3,*node4,*node5,*node6,*node7,*node8,*node9;
    root->data = 'root';
    root->right_thread = 0;
    root->left_thread = 0;
    root->right_child = root;

    node1 = new_thread('A',0,0);
    root->left_child = node1;

    node2 = new_thread('B',0,0);
    node3 = new_thread('C',0,0);
    node1->left_child = node2;
    node1->right_child = node3;

    node4 = new_thread('D',0,0);
    node5 = new_thread('E',1,1);
    node2->left_child = node4;
    node2->right_child = node5;
    node5->left_child = node2;
    node5->right_child = node1;
    node6 = new_thread('F',1,1);
    node7 = new_thread('G',1,1);
    node3->left_child = node6;
    node3->right_child = node7;
    node6->left_child = node1;
    node6->right_child = node3;
    node7->left_child = node3;
    node7->right_child = root;
    node8 = new_thread('H',1,1);
    node9 = new_thread('I',1,1);
    node4->left_child = node8;
    node4->right_child = node9;
    node8->left_child = root;
    node8->right_child = node4;
    node9->left_child = node4;
    node9->right_child = node2;
}

void inorder_thread_1(THREAD * ptr) {
    if (ptr->left_thread != 1 && ptr->right_thread != 1) {
        inorder_thread_1(ptr->left_child);
        printf("%c ", ptr->data);
        inorder_thread_1(ptr->right_child);
    }
}

THREAD *insucc(THREAD *ptr)
{
    THREAD *temp = ptr->right_child;
    if (ptr->right_thread == 0)// right_child가 child pointer
        while (temp->left_thread == 0) // 왼쪽 끝까지 가자
            temp = temp->left_child;
    return temp;
}

void tinorder(THREAD* node){
    THREAD * temp = node;
    for(;;){
        temp = insucc(temp);
        if(temp == node)
            break;
        printf("%3c",temp->data);
    }
}

void insert_right(THREAD* parent,THREAD* child){

    THREAD *temp;
    child->right_child = parent->right_child;
    child->right_thread = parent->right_thread;
    child->left_child = parent;
    child->left_thread = 1;
    parent->right_child = child;
    parent->right_thread = 0;
    if(child->right_thread == 0){
        temp = insucc(child);
        temp->left_child = child;
    }

}

THREAD *inpred(THREAD* node){
    THREAD *temp = node->left_child;
    if(temp->left_thread != 1){
        while (temp->right_thread == 0)
            temp = temp->right_child;
    }
    return temp;
}

void insert_left(THREAD* parent,THREAD* child){
    THREAD *temp;
    child->left_child = parent->left_child;
    child->left_thread = parent->left_thread;
    child->right_child = parent;
    child->right_thread = 1;
    parent->left_child = child;
    parent->left_thread = 0;
    if(child->left_thread == 0){
        temp = inpred(child);
        temp->right_child = child;
    }
}

void thread_exec(){
    THREAD *root = (THREAD*) malloc(sizeof (THREAD));
    make_thread_tree(root);
    tinorder(root);
}
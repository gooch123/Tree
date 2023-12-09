//
// Created by gooch on 2023-12-09.
//
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define MAX_ELEMENTS 200
#define HEAP_FULL(heap_size) (heap_size == MAX_ELEMENTS -1)
#define HEAP_EMPTY(heap_size) (!heap_size)
typedef struct {
    int key;
} element;
element heap[MAX_ELEMENTS];
int heap_size = 0;

void insert_max_heap(int data){
    element* item = (element*) malloc(sizeof (element));
    item->key = data;
    int i;
    if(HEAP_FULL(heap_size)){
        fprintf(stderr,"The heap full\n");
        exit(1);
    }
    i = ++(heap_size);
    while ((i != 1) && (item->key > heap[i/2].key)){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = *item;
}

void delete_heap(){
    int parent = 1, child, temp ;
    if(HEAP_EMPTY(heap_size)){
        fprintf(stderr,"The heap empty\n");
        exit(1);
    }
    heap[parent].key = heap[heap_size].key;
    heap[heap_size--].key = 0;
    while (parent * 2 <= heap_size){
        child = (heap[parent * 2].key >= heap[parent * 2 + 1].key) ? parent * 2 : parent * 2 + 1;
        temp = heap[child].key;
        heap[child].key = heap[parent].key;
        heap[parent].key = temp;
        parent = child;
    }
}

void printf_heap(){
    for (int i = 1; i <= heap_size; ++i) {
        printf("%3d",heap[i]);
    }
}



void heap_exec(){
    insert_max_heap(20);
    insert_max_heap(15);
    insert_max_heap(2);
    insert_max_heap(14);
    insert_max_heap(10);
    delete_heap();
    printf_heap();
}
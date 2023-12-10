//
// Created by gooch on 2023-12-10.
//
#include "union.h"

int parent[10] = {-1,4,-1,2,-1,2,0,0,0,4};

int find(int i){
    for(;parent[i] != -1;){
        i = parent[i];
    }
    return i;
}

void _union_(int i,int j){
    int pi,pj;
    pi = find(i);
    pj = find(j);
    parent[pj] = pi;
}
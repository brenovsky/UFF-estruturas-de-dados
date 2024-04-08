#ifndef BINARY_TREES_OPERATIONS_H
#define BINARY_TREES_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "listas-encadeadas-funcoes.h"

typedef struct bitree {
    int info;
    struct bitree* esq;
    struct bitree* dir;
} TTree;

TTree* createTree() {
    return NULL;
}

TTree* insertRoot(int value) {
    TTree* new = (TTree*) malloc(sizeof(TTree));
    new -> info = value;
    new -> esq = NULL;
    new -> dir = NULL;

    return new;
}

TTree* insertLeft(TTree* root, int value) {
    if (root == NULL) {
        return insertRoot(value);
    }

    root -> esq = insertLeft(root -> esq, value);
    return root;
}

TTree* insertRight(TTree* root, int value) {
    if (root == NULL) {
        TTree* new = (TTree*) malloc(sizeof(TTree));
        new -> info = value;
        new -> esq = NULL;
        new -> dir = NULL;

        return new;
    }

    root -> dir = insertRight(root -> dir, value);
    return root;
}


#endif //BINARY_TREES_OPERATIONS_H

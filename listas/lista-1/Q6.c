#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoA {
    char info;
    struct NoA* esq;
    struct NoA* dir;
} TNo;

TNo* insertTree(TNo* root, char value) {
    TNo* new = (TNo*) malloc(sizeof(TNo));

    new -> info = value;
    new -> esq = NULL;
    new -> dir = NULL;

    return new;
}

int compare(char a, char b) {
    if (a == b) return 1;

    return 0;
}

void operation1(TNo* root) {
    if (root != NULL) {
        operation1(root->esq);
        printf("%c ", root->info);
        operation1(root->dir);
    }

}

void operation2(TNo* root) {
    if (root != NULL) {
        if ((compare(root -> info, '*') || compare(root -> info, '/')) && (compare(root -> esq ->  info, '+') || compare(root -> esq ->  info, '-'))) {
            printf("( ");
            operation2(root->esq);
            printf(")");
            printf(" %c ", root->info);
            operation2(root->dir);

        } else {
            operation1(root);
        }
    }

}
int main() {
    TNo* root = NULL;
    TNo* root2 = NULL;

    root = insertTree(root, '+');
    root -> esq = insertTree(root, '3');
    root -> dir = insertTree(root, '*');
    root -> dir -> esq = insertTree(root, '5');
    root -> dir -> dir = insertTree(root, '8');

    operation1(root);
    printf("\n");

    root2 = insertTree(root2, '*');
    root2 -> esq = insertTree(root2, '+');
    root2 -> esq -> esq = insertTree(root2, '3');
    root2 -> esq -> dir = insertTree(root2, '5');
    root2 -> dir = insertTree(root2, '8');

    operation2(root2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} TNo;

TNo* insertSearch(TNo* root, int chave) {
    if (root == NULL) {
        TNo* new = (TNo*) malloc(sizeof(TNo));

        new -> chave = chave;
        new -> esq = NULL;
        new -> dir = NULL;

        return new;
    }

    if (chave < root -> chave) root -> esq = insertSearch(root -> esq, chave);

    else if (chave > root -> chave) root -> dir = insertSearch(root -> dir, chave);

    return root;
}

// remove nó

int main() {
    TNo* root = NULL;

    root = insertSearch(root, 50);
    root = insertSearch(root, 30);
    root = insertSearch(root, 70);
    root = insertSearch(root, 20);
    root = insertSearch(root, 40);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int chave;
    int conteudo;
    struct reg *esq, *dir;
} noh;

int search(noh* root) {
    if (root -> esq != NULL || root -> dir != NULL) {
        if (!((root->chave > root->esq->chave) && (root->chave < root->dir->chave)))
            exit(1);

        return search(root->esq) && search(root->dir);
    }
    return 1;
}

int main() {
    return 0;
}
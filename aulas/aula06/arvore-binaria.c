#include "arvore-binaria.h"

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TNoA* profundidade(TNoA* raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz -> info);
        profundidade(raiz -> esq);
        profundidade(raiz -> dir);
    }
}


TNoA* simetrico(TNoA* raiz) {
    if (raiz != NULL) {
        simetrico(raiz -> esq);
        printf("%c ", raiz -> info);
        simetrico(raiz -> dir);
    }
}

TNoA* posOrdem(TNoA* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%c ", raiz->info);
    }
}

int contarNo(TNoA* raiz, int i) {
    if (raiz != NULL) {
        i++;
        i = contarNo(raiz -> esq, i);
        i = contarNo(raiz -> dir, i);
    }
    return i;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);

    int nos = contarNo(raiz, 0);

    printf("\n%d\n", nos);


};
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* prox;
} TPilha;

TPilha* criaPilha() {
    return NULL;
}

TPilha* pushElemento(TPilha* topo, int valor) {
    TPilha* novo = (TPilha*) malloc(sizeof(TPilha));

    novo -> info = valor;
    novo -> prox = topo;

    return novo;
}

TPilha* popElemento(TPilha* topo) {
    TPilha* temp = topo -> prox;
    free(topo);

    return temp;
}

TPilha* imprimirPilha(TPilha* topo) {
    if (topo != NULL) {
        printf("%d\n", topo -> info);
        imprimirPilha(topo -> prox);
    }
}

int main() {

    TPilha* pilha1;

    pilha1 = criaPilha();

    pilha1 = pushElemento(pilha1, 10);
    pilha1 = pushElemento(pilha1, 12);
    pilha1 = pushElemento(pilha1, 1);
    pilha1 = pushElemento(pilha1, 100);
    pilha1 = pushElemento(pilha1, 1222);

    imprimirPilha(pilha1);

    return 0;
}
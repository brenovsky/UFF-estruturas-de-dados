#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

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
    if (topo == NULL) {
        return topo;
    }

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
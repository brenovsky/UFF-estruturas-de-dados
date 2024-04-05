#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* criaLista() {
    return NULL;
}

TLista* insereComeco(TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = i;
    novo -> prox = li;

    return novo;
}

TLista* insereFim(TLista* li, int i) {

    if (li != NULL) {
        li -> prox = insereFim(li -> prox, i);
        return li;
    }

    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = i;
    novo -> prox = li;

    return novo;
}

TLista* insereOrdenado(TLista* li, int i) {

    if(li == NULL || i < li -> info) {
        TLista* novo = (TLista*) malloc(sizeof(TLista));

        novo -> info = i;
        novo -> prox = li;

        return novo;
    }

    li -> prox = insereOrdenado(li -> prox, i);
    return li;
}

TLista* excluiElemento(TLista* li, int i) {

    if (li == NULL) {
        return li;
    }

    if (li -> info == i) {
        TLista* temp = li -> prox;
        free(li);

        return temp;
    }

    li -> prox = excluiElemento(li -> prox, i);
    return li;
}

TLista* imprimirLista(TLista* li) {
    if (li != NULL) {
        printf("%d\n", li -> info);
        imprimirLista(li -> prox);
    }
}

int main() {

    TLista* lista1;

    lista1 = criaLista();

    lista1 = insereOrdenado(lista1, 100);
    lista1 = insereOrdenado(lista1, 10);
    lista1 = insereOrdenado(lista1, 122221);
    lista1 = insereOrdenado(lista1, 1222);

    imprimirLista(lista1);


    return 0;
}
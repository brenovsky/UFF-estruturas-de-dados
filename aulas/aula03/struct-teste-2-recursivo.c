#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* criarLista() {
    return NULL;
}

TLista* insereInicio(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;
    novo -> prox = inicio;

    return novo;
}

TLista* insereFim(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;

    if (inicio != NULL) {
        inicio -> prox = insereFim(inicio -> prox, valor);

    } else {
        novo->prox = NULL;
        inicio = novo;
    }

    return inicio;
}

TLista* imprimirLista(TLista* inicio) {
    if (inicio != NULL) {
        printf("%d\n", inicio -> info);

        imprimirLista(inicio -> prox);
    }
}

int main() {
    TLista* lista1;

    lista1 = criarLista();

    lista1 = insereFim(lista1, 10);
    lista1 = insereFim(lista1, 11);
    lista1 = insereFim(lista1, 12);

    imprimirLista(lista1);

    return 0;
}
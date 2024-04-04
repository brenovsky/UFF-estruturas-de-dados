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

TLista* insereOrdenado(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;
    novo -> prox = NULL;

    if (inicio != NULL) { //verificar se o ponteiro aponta para null
        if (valor < inicio -> info) { //se o valor for menor do que a info, o novo aponta pro inicio (> valor) e retorna novo (o novo inicio)
            novo -> prox = inicio;
            return novo;
        }
        else {
            return inicio -> prox = insereOrdenado(inicio -> prox, valor);//passa para verificar o próximo
        }
    }
    return novo;
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

    lista1 = insereOrdenado(lista1, 10);
    lista1 = insereOrdenado(lista1, 15);
    lista1 = insereOrdenado(lista1, 9);
    lista1 = insereOrdenado(lista1, 8);
    lista1 = insereOrdenado(lista1, 20);
    lista1 = insereOrdenado(lista1, 21);

    imprimirLista(lista1);

    return 0;
}
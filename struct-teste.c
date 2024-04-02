#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

void criar(TLista* inicio) {
    inicio -> prox = NULL;
}

void insereInicio(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;
    novo -> prox = inicio -> prox;

    inicio -> prox = novo;
}

void imprimir(TLista* inicio) {
    TLista* p = inicio -> prox;

    while (p != NULL) {
        printf("%d\n", p -> info);

        p = p -> prox;
    }
}

int main() {

    TLista inicio;//pq nao dá malloc?

    criar(&inicio);

    insereInicio(&inicio, 4);
    insereInicio(&inicio, 5);
    insereInicio(&inicio, 4);

    imprimir(&inicio);

    return 0;
}
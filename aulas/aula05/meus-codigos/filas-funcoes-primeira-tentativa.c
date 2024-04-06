#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int info;
    struct fila *prox;
} TFila;

TFila* criaFila() {
    return NULL;
}

TFila* insereElemento(TFila* inicio, int valor) {
    if (inicio == NULL) {
        TFila* novo = (TFila*) malloc(sizeof(TFila));

        novo -> info = valor;
        novo -> prox = inicio;

        return novo;
    }

    inicio -> prox = insereElemento(inicio -> prox, valor);
    return inicio;
}

TFila* removerElemento(TFila* inicio) {
    if (inicio == NULL) {
        return NULL;
    }

    TFila* temp = inicio -> prox;
    free(inicio);

    return temp;
}

TFila* imprimirFila(TFila* inicio) {
    if (inicio != NULL) {
        printf("%d ", inicio -> info);
        imprimirFila(inicio -> prox);
    }
}

int main() {

    TFila* fila1;

    fila1 = criaFila();

    fila1 = insereElemento(fila1, 14);
    fila1 = insereElemento(fila1, 100);
    fila1 = insereElemento(fila1, 7);

    imprimirFila(fila1);

    return 0;
}
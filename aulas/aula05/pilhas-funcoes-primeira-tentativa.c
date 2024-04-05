#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* prox;
} TPilha;

TPilha* criaPilha() {
    return NULL;
}

TPilha* pushPilha(TPilha* inicio, int valor) {
    if (inicio == NULL) {
        TPilha* novo = (TPilha*) malloc(sizeof(TPilha));

        novo -> info = valor;
        novo -> prox = inicio;

        return novo;
    }

    inicio -> prox = pushPilha(inicio -> prox, valor);
    return inicio;
}

TPilha* popPilha(TPilha* inicio) {
    if (inicio -> prox == NULL) {
        free(inicio);
        return NULL;
    }

    inicio -> prox = popPilha(inicio -> prox);
    return inicio;
}

TPilha* imprimirPilha(TPilha* inicio) {
    if (inicio -> prox != NULL) {//busca o NULL da pilha
        inicio -> prox = imprimirPilha(inicio -> prox);
    }
    printf("%d\n", inicio -> info);
}

int main() {
    TPilha* pilha1;

    pilha1 = criaPilha();

    pilha1 = pushPilha(pilha1, 1);
    pilha1 = pushPilha(pilha1, 2);
    pilha1 = pushPilha(pilha1, 3);
    pilha1 = pushPilha(pilha1, 41);

    imprimirPilha(pilha1);

    return 0;
}
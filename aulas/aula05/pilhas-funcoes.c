#include "pilhas-funcoes.h"

TPilha* criaPilha() {
    TPilha* pilha = (TPilha*) malloc(sizeof(TPilha));
    pilha -> topo = NULL;

    return pilha;
}

TPilha* pushElemento(TPilha* pilha, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;

    if (pilha -> topo == NULL) {
        pilha -> topo = novo;
        novo -> prox = NULL;

        return pilha;
    }

    novo -> prox = pilha -> topo;

    pilha -> topo = novo;

    return pilha;
}

TPilha* popElemento(TPilha* pilha) {
    if (pilha -> topo == NULL) {
        return pilha;
    }

    TLista* temp = pilha -> topo -> prox;
    free(pilha -> topo);

    pilha -> topo = temp;

    return pilha;
}

void imprimirPilha(TPilha* pilha) {
    TLista* p;

    for (p = pilha -> topo; p != NULL; p = p -> prox){
        printf("%d\n", p -> info);
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

    pilha1 = popElemento(pilha1);
    pilha1 = popElemento(pilha1);

    imprimirPilha(pilha1);

    return 0;
}
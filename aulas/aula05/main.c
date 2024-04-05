#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

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
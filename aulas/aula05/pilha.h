#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha {
    int info;
    struct pilha* prox;
} TPilha;

TPilha* criaPilha();

TPilha* pushElemento(TPilha* topo, int valor);

TPilha* popElemento(TPilha* topo);

TPilha* imprimirPilha(TPilha* topo);

#endif // PILHA_H

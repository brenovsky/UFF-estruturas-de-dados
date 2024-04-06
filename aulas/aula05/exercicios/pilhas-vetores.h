#include <stdio.h>

typedef struct pilha {
    int info;
} TPilha;

void inicializa(int *base, int *lim, int *topo);
int pilha_cheia(int lim, int topo);
int pilha_vazia(int base, int topo);
int push(TPilha *pilha, int lim, int *topo, int info);
int pop(TPilha *pilha, int base, int *topo);
int peek(TPilha *pilha, int base, int *topo);
void imprime(TPilha *pilha, int *topo);
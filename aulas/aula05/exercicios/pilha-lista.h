#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.h"

typedef struct pilha{
    TLista *topo;
} TPilha;

TPilha *inicializa();
void libera(TPilha *p);
int pilha_vazia(TPilha *p);
void push(TPilha *pilha, int elem);
int pop(TPilha *pilha);
int peek(TPilha *pilha);
void imprime_pilha(TPilha *pilha);

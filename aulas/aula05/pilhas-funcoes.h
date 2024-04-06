#ifndef PILHAS_FUNCOES_H
#define PILHAS_FUNCOES_H

#include "listas-encadeadas-funcoes.h"

typedef struct pilha {
    TLista* topo;
} TPilha;

TPilha* criaPilha();

TPilha* pushElemento(TPilha* topo, int valor);

TPilha* popElemento(TPilha* topo);

void imprimirPilha(TPilha* topo);

#endif //UFF_ESTRUTURAS_DE_DADOS_PILHAS_FUNCOES_H

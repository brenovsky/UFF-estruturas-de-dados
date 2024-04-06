#ifndef LISTAS_ENCADEADAS_FUNCOES_H
#define LISTAS_ENCADEADAS_FUNCOES_H


#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* criarLista();

TLista* insereInicio(TLista* inicio, int valor);

TLista* insereFim(TLista* inicio, int valor);

TLista* insereOrdenado(TLista* inicio, int valor);

TLista* excluiElemento(TLista* inicio, int valor);

TLista* imprimirLista(TLista* inicio);

#endif //UFF_ESTRUTURAS_DE_DADOS_LISTAS_ENCADEADAS_FUNCOES_H

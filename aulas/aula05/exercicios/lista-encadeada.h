#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLista;

TLista *cria_lista(void);
TLista *insere_fim_recursivo(TLista *li, int i);
TLista *insere_ordenado_recursivo(TLista *li, int i);
void imprime_lista(TLista *li);
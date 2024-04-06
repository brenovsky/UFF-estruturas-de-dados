#include "lista-encadeada.h"

typedef struct fila {
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *inicializa(void);
int fila_vazia(TFila *f);
void insere(TFila *f, int elem);
int retira(TFila *f);
void libera(TFila *f);
void imprime_fila(TFila *f);


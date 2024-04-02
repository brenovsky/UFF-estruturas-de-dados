#include "pratica03.h"

TLista* cria_lista (void) {
    return NULL;
}

TLista* insere_inicio (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    if (p == NULL) { //se a lista estiver vazia
        li = novo;
    }
    else {
        while (p->prox != NULL) { //encontra o ultimo elemento
            p = p->prox;
        }
        p->prox = novo;
    }
    return li;
}

TLista* insere_ordenado (TLista* li, int i) {
    TLista* novo;
    /* cria novo elemento */
    novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li; /* ponteiro para percorrer a lista */

    if (p == NULL) {
        li = novo;
        li -> prox = NULL;
    }
    else if (novo -> info < li -> info) {
        TLista* temp = li;
        li = novo;
        novo -> prox = temp;
    } else {
        while (p->prox->prox != NULL && i < p->prox->info) {
            p = p->prox;
        }
        p->prox = novo;
        novo->prox = p->prox;
    }
    return li;
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

int main (void) {
    TLista* l1;
    TLista* l2;
    TLista* l3; /* declara listas não inicializadas */
    /* Insere elementos no inicio da lista */
    l1 = cria_lista(); /* cria e inicializa lista como vazia */
    l1 = insere_inicio(l1, 2);
    l1 = insere_inicio(l1, 3);
    l1 = insere_inicio(l1, 5);
    l1 = insere_inicio(l1, 4);
    printf("Lista 1:\n");
    imprime_lista(l1);

    /* Insere elementos no final da lista*/
    l2 = cria_lista(); /* cria e inicializa lista como vazia */
    l2 = insere_fim(l2, 2);
    l2 = insere_fim(l2, 3);
    l2 = insere_fim(l2, 5);
    l2 = insere_fim(l2, 4);
    printf("Lista 2:\n");
    imprime_lista(l2);

    /* Insere elementos de forma que a lista esteja sempre ordenada */
    l3 = cria_lista(); /* cria e inicializa lista como vazia */
    l3 = insere_ordenado(l3, 2);
    l3 = insere_ordenado(l3, 1);
    l3 = insere_ordenado(l3, 5);
    l3 = insere_ordenado(l3, 4);
    l3 = insere_ordenado(l3, 3);
    printf("Lista 3:\n");
    imprime_lista(l3);

    return 0;
}
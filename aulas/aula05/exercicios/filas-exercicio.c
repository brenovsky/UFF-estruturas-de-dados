#include "filas-listas.h"

TFila *inicializa(void){
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(TFila *f){
    if (f->inicio == NULL) {
        return 1;
    }
    else return 0;
}

void insere(TFila *f, int elem){
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; //inserção no fim da fila
    if (!fila_vazia(f)){
        f->fim->prox = novo;
    }
    else{
        f->inicio = novo;
    }
    f->fim = novo; //elemento inserido é o novo fim da fila
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira(TFila *f){
    if (fila_vazia(f)){
        exit(1);
    }
    int info = f->inicio->info;

    TLista *aux = f->inicio;
    f->inicio=f->inicio->prox;
    //se elemento removido era o único da fila
    //faz fim apontar para NULL também
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void libera(TFila *f){
    TLista *q, *p = f->inicio;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(f);
}

void altera_inicio(TFila *f, int elem){
    f -> inicio -> info = elem;
}

void imprime_fila(TFila *f){
    TLista* p;

    for (p = f -> inicio; p != NULL; p = p -> prox) {
        printf("%d ", p -> info);
    }
}

int main() {
    TFila *fila = inicializa();
    insere(fila, 5);
    insere(fila, 3);
    insere(fila, 2);
    altera_inicio(fila, 100);
    imprime_fila(fila);
    int x = retira(fila);
    printf("\nelemento %d retirado da fila\n", x);
    imprime_fila(fila);
    libera(fila);
}

/* ATENTAR-SE AO SEGUINTE:
- TFila é apenas um struct com um ponteiro para o inicio e para o fim (para guiar a fila)
- inicio e fim são ponteiros TLista (aponta para um nó, portanto dá para acessar info e prox)
- TFila é diferente de TLista
- O ponteiro auxiliar que itera pela fila vai apontar para uma struct TLista
 */
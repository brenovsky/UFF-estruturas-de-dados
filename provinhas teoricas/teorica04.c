#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* criaLista() {
    return NULL;
}

TLista* insereInicio(TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = i;
    novo -> prox = li;

    return novo;
}

TLista* exclui(TLista* li, int i) {//nap sei resolver
    TLista* p;

    if(li == NULL) return NULL;

    if (li -> prox -> info == i) {
        p = li -> prox -> prox;
        li -> prox = p;
        free(li -> prox);
        return li;
    }

    exclui(li -> prox, i);
    return li;
}

TLista* imprimir(TLista* li) {
    if (li != NULL) {
        printf("%d\n", li -> info);
        return imprimir(li -> prox);
    }
}

int main(){
    TLista* lista;

    lista = criaLista();

    lista = insereInicio(lista, 3);
    lista = insereInicio(lista, 10);
    lista = insereInicio(lista, 13);
    lista = insereInicio(lista, 56);

    lista = exclui(lista, 13);

    imprimir(lista);



    return 0;
}
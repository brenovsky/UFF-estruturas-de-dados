#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* criarLista() {
    return NULL;
}

TLista* insereInicio(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;
    novo -> prox = inicio;

    return novo;
}

TLista* insereFim(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;

    if (inicio != NULL) {
        inicio -> prox = insereFim(inicio -> prox, valor);

    } else {
        novo->prox = NULL;
        inicio = novo;
    }

    return inicio;
}

TLista* insereOrdenado(TLista* inicio, int valor) {
    if (inicio == NULL || inicio -> info > valor) {//verifica se chegou no fim ou se o prox elemento é maior que o valor
    	TLista* novo = (TLista*) malloc(sizeof(TLista));
    	novo -> info = valor;
    	
    	novo -> prox = inicio;
    	return novo;
    }
    
    inicio -> prox = insereOrdenado(inicio -> prox, valor);//caso não, vai pro próximo
    return inicio;//retorna inicio para não perder a cabeça da lista
}

TLista* imprimirLista(TLista* inicio) {
    if (inicio != NULL) {
        printf("%d\n", inicio -> info);

        imprimirLista(inicio -> prox);
    }
}

int main() {
    TLista* lista1;

    lista1 = criarLista();
    
    lista1 = insereOrdenado(lista1, 100);
	lista1 = insereOrdenado(lista1, 31);
    lista1 = insereOrdenado(lista1, 10);
    lista1 = insereOrdenado(lista1, 11);
    lista1 = insereOrdenado(lista1, 101);

    imprimirLista(lista1);

    return 0;
}
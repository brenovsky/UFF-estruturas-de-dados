#include <stdio.h>
#include <stdlib.h>


//head of the list is the first item

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

    return novo; //inicio = novo;
}

TLista* insereFim(TLista* inicio, int valor) {
	TLista* novo = (TLista*) malloc(sizeof(TLista));
	TLista* p = inicio;
	
	novo -> info = valor;
	
	if (p == NULL) {
		novo -> prox = inicio;
		inicio = novo;
	} else {
		while (p -> prox != NULL) {
			p = p -> prox;
		}
		
		novo -> prox = p -> prox;
		p -> prox = novo;
		}
		
	return inicio;
}

TLista* insereOrdenado(TLista* inicio, int valor) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;

    TLista* p = inicio;

    if (p == NULL) {
        inicio = novo;
        inicio -> prox = NULL;
    }
    else if(valor < inicio -> info) {
        novo -> prox = inicio;
        inicio = novo;
    } else {
        TLista* a = inicio -> prox;

        /* confere se o proximo ao ponteiro (p) auxiliar é menor que o valor.
        caso seja,significa que está em alguma posição >depois< de "a" (e itera)
        caso contrário, o número está uma posicão antes de "a" e o loop quebra
        quando achar um maior, ou for null, quebra)*/
        while (p -> prox != NULL &&  a -> info < valor) {
            p = p -> prox;
            a = a -> prox;
        }
        p -> prox = novo;
        novo -> prox = a;
    }
    return inicio;
}

void imprimirLista(TLista* inicio) {
    TLista* p;

    for (p = inicio; p != NULL; p = p -> prox) {
        printf("%d\n", p -> info);
    }
}

int main() {

    TLista* lista1;//pq nao dá malloc?
    TLista* lista2;
    TLista* lista3;

    lista1 = criarLista();

    lista1 = insereInicio(lista1, 1);
    lista1 = insereInicio(lista1, 2);
    lista1 = insereInicio(lista1, 3);
    lista1 = insereFim(lista1, 7);

    imprimirLista(lista1);

    printf("\n");

    lista2 = criarLista();

    lista2 = insereOrdenado(lista2, 10);
    lista2 = insereOrdenado(lista2, 7);
    lista2 = insereOrdenado(lista2, 13);
    lista2 = insereOrdenado(lista2, 5);
    lista2 = insereOrdenado(lista2, 6);


    imprimirLista(lista2);
    printf("\n");
    
    lista3 = criarLista();
    
    lista3 = insereFim(lista3, 10);
    lista3 = insereFim(lista3, 5);
    lista3 = insereFim(lista3, 3);
    lista3 = insereInicio(lista3, 100);
    lista3 = insereFim(lista3, 666);
    
    imprimirLista(lista3);
    printf("\n");

    return 0;
}
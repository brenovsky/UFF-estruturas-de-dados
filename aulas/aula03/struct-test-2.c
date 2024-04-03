#include <stdio.h>
#include <stdlib.h>

typedef struct lista {

    int info;
    struct lista* prox;

} TLista;

void cria_lista(TLista* lista) { //ponteiro aponta para NULL

    lista -> prox = NULL;
}

void insereInicio(TLista* lista, int valor) {// inserir elemento no inicio da lista

    TLista* novo = (TLista*) malloc(sizeof(TLista));

    novo -> info = valor;
    novo -> prox = lista -> prox; //novo prox, aponta para onde o ponteiro 'lista' aponta (começo da lista)

    lista -> prox = novo; //ponteiro do começo aponta para o novo inicio
}

void insereFim(TLista* lista, int valor) {

    TLista* novo = (TLista*) malloc(sizeof(TLista));
    TLista* p = lista -> prox; //ponteiro auxiliar

    novo -> info = valor;
    novo -> prox = NULL;

    if (p -> prox == NULL) {
        lista -> prox = novo;
    } else {
        while (p -> prox != NULL) {
            p = p -> prox;
        }
        p -> prox = novo;
    }

}

void insereOrdenado(TLista* lista, int valor) { //consertar erro!!!
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    TLista* p = lista -> prox;
    TLista* a = lista;

    novo -> info = valor;

    if (p == NULL) {
        novo -> prox = lista -> prox;
        lista -> prox = novo;

    } else {
        while (novo -> info >= p -> info) {
            p = p -> prox;
            a = a -> prox;
        }
        novo -> prox = p;
        a -> prox = novo;
    }
}

void imprimirLista(TLista* lista) {

    TLista* p;

    for (p = lista -> prox; p != NULL; p = p -> prox) {
        printf("%d ", p->info);
    }
    printf("\n\n");
}

void excluirElemento(TLista* lista, int valor) {//exclui a primeira ocorrencia

    TLista* p = lista -> prox;
    TLista* a = lista;

    if (p == NULL) {
        printf("A lista esta vazia");
    } else {
        while (p -> info != valor) {
            p = p -> prox;
            a = a -> prox;
        }
        a -> prox = p -> prox; //substitui o ponteiro do anterior
        free(p); //liberar o struct que 'p' aponta
    }
    imprimirLista(lista);
}

int main() {

    int input, valor;
    TLista vetor;

    cria_lista(&vetor);

    do {
        printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Excluir primeira ocorrencia\n4 - Inserir ordenado\n5 - Imprimir lista\n6 - Sair\n\n");

        scanf("%d", &input);

        switch(input) {

            case 1:
                scanf("%d", &valor);
                insereInicio(&vetor, valor);
                break;
            case 2:
                scanf("%d", &valor);
                insereFim(&vetor, valor);
                break;
            case 3:
                scanf("%d", &valor);
                excluirElemento(&vetor, valor);
                break;
            case 4:
                scanf("%d", &valor);
                insereOrdenado(&vetor, valor);
                break;
            case 5:
                imprimirLista(&vetor);
                break;

            case 6:
                printf("Encerrando...\n");
                break;
            default:
                printf("Voce escolheu uma opcao invalida. Tente novamente\n");
        }
    } while(input != 6);

    imprimirLista(&vetor);

    return 0;
}
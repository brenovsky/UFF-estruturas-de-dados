#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    int valor;
    struct No* proximo; //vai apontar para outro nó

} TNo;

typedef struct lista {
    TNo* inicio;
    int tam;
} Lista;

void inserirInicios(Lista* lista, int valor) {

    /* criar um novo nó para encadear
    (e vai retornar o ponteiro por conta do cast */
    TNo* novo = (TNo*) malloc(sizeof(TNo));

    novo -> valor = valor; //o nó recebe um valor
    novo -> proximo = lista -> inicio; //o ponteiro passa a apontar para o restante da lista
    lista -> inicio = novo; //o ponteiro aponta para o novo (inicio novo da lista)
    lista -> tam++;
}

void inserirFim(Lista* lista, int valor) {
    TNo *auxiliar,* novo = (TNo*) malloc(sizeof(TNo));

    novo -> valor;
    novo -> proximo = NULL;

    auxiliar -> proximo = inicio; //me confundi

    if (lista -> inicio == NULL) {
        lista -> inicio = novo;
    } else {
        while(auxiliar->proximo != NULL) {
            auxiliar = auxiliar -> proximo;
        }
        auxiliar -> proximo = novo;

    }
    lista -> tam++;
}

void imprimir(Lista* lista) {
    TNo* inicio = lista -> inicio; //cria um ponteiro auxiliar para iterar pela lista
    while (inicio != NULL) {
        printf("%d ", inicio -> valor);
        inicio = inicio -> proximo;
    }
    printf("\n");
}

int main() {

    Lista lista;
    int opcao, valor;

    lista.inicio = NULL;
    lista.tam = 0;

    do {
        printf("1 - inserir no inicio\n2 - imprimir\n3 - inserir no fim\n4 - sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                scanf("%d", &valor);
                inserirInicios(&lista, valor);
                break;
            case 2:
                imprimir(&lista);
                break;
            case 3:
                inserirFim(&lista, valor);
                break;
            case 4:
                printf("Finalizando...\n");
                break;
            default:
                printf("Opcao invalida!");
        }
    } while(opcao != 3);

    return 0;
}
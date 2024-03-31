#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {//criando struct pessoa
    char nome[50];
    char endereco[500];
    char fone[15];
    char CEP[10];
} TPessoa;

typedef struct lista {
    TPessoa info; //uma posicao do struct serao as infos e o outro o ponteiro
    struct lista* prox;
}TLista;

void criarLista(TLista* lista) {
    lista -> prox = NULL;
}

void inserirNome(TLista* lista, TPessoa pessoa) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    TLista* p = lista -> prox;
    TLista* a = lista;

    novo -> info = pessoa;

    if (lista -> prox == NULL) {
        novo -> prox = lista->prox;
        lista -> prox = novo;
    } else {
    while (novo -> info.nome < p -> info.nome) {
        p = p -> prox;
        a = a -> prox;
    }
    novo -> prox = p;
    a -> prox = novo;
    }

    printf("\nDados inseridos com sucesso!\n");
}

void imprimirNome(TLista* lista, TPessoa pessoa) {
    TLista* p = lista -> prox;

    if (p == NULL) {
        printf("Esse nome nao existe na agenda! Insira-o para prosseguir.\n\n");
    } else {
        while(strcmp(pessoa.nome, p -> info.nome) != 0) {//comparar as strings
            p = p -> prox;
        }

        printf("==========\n");
        printf("Nome: %s\n", p -> info.nome);
        printf("Endereco: %s\n", p -> info.endereco);
        printf("Fone: %s\n", p -> info.fone);
        printf("CEP: %s\n", p -> info.CEP);
        printf("==========\n");
    }

}

void buscaLetra(TLista* lista, char letra) {
    TLista* p = lista -> prox;

    while (p -> info.nome[0] != letra) {//procurar pela letra
        p = p -> prox;
    }

    while (p != NULL) {//imprimir
        if (p -> info.nome[0] == letra) {
            printf("==========");
            printf("Nome: %s\n", p->info.nome);
            printf("==========");
        }
        p = p -> prox;
    }
}

int main() {

    TLista agenda;
    TPessoa pessoa;

    int opcao;

    criarLista(&agenda);

    do {
        printf("1 - Inserir novo dado\n2 - Consultar por nome\n3 - Consultar por inicial\n4 - Sair\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                getchar();
                printf("Insira o nome:");
                gets(pessoa.nome);
                printf("\nInsira o endereco:");
                gets(pessoa.endereco);
                printf("\nInsira o telefone:");
                gets(pessoa.fone);
                printf("\nInsira o CEP:");
                gets(pessoa.CEP);

                inserirNome(&agenda, pessoa);
                break;
            case 2:
                getchar();
                printf("Consulte pelo nome:");
                gets(pessoa.nome);

                imprimirNome(&agenda, pessoa);
                break;

            case 3:
                getchar();
                char letra[1];
                printf("Consulte pela inicial:");
                gets(letra);

                buscaLetra(&agenda, *letra);
                break;
            case 4:
                printf("Finalizando...");
                break;
        }

    } while (opcao != 4);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

TNoA *maior_no_esquerda(TNoA *no) {
    TNoA *atual = no;

    /* loop para encontrar o nó mais à direita */
    while (atual->dir != NULL)
        atual = atual->dir;
    return atual;
}

/*Esta função recebe a raiz da árvore ou sub-arvore e a chave a ser excluída
Retorna ponteiro para a nova raiz da sub-árvore sendo modificada*/
TNoA *exclui(TNoA *raiz, int chave) {
    // Caso base - nada a fazer
    if (raiz == NULL) return raiz;

    // Se chave é menor do que a chave da raiz,
    //procura na subárvore esquerda
    if (chave < raiz->chave)
        raiz->esq = exclui(raiz->esq, chave);

        // Se chave é maior do que a chave da raiz,
        //procura na subárvore direita
    else if (chave > raiz->chave)
        raiz->dir = exclui(raiz->dir, chave);

        // Senão, a chave é igual e esse é o nó que tem que ser excluído
    else{
        // só tem subárvore direita ou nenhuma subárvore
        if (raiz->esq == NULL) {
            TNoA* temp = raiz -> dir;
            free(raiz);
            return temp;

            // só tem subárvore esquerda ou nenhuma subárvore
        } else if (raiz->dir == NULL){
            TNoA* temp = raiz -> esq;
            free(raiz);
            return temp;
        } else { // nó com 2 filhos - pega o maior da subárvore esquerda
            
            TNoA* temp = maior_no_esquerda(raiz -> esq);// salvar o maior no
            raiz -> chave = temp -> chave; //substituir os valores

            raiz -> esq = exclui(raiz -> esq, temp -> chave); //tirar a folha maior da subarvore esquerda
            return temp;


        }
    }
    return raiz;
}

int main(void) {
    TNoA *raiz, *no;
    raiz = NULL;
    //arvore usada no slide da disciplina
    raiz = insere(raiz, 100);
    //subarvore esquerda
    insere(raiz, 90);
    insere(raiz, 70);
    insere(raiz, 73);
    insere(raiz, 65);
    insere(raiz, 64);
    insere(raiz, 66);
    insere(raiz, 71);
    insere(raiz, 75);
    insere(raiz, 74);

    printf("\n\nArvore original: \n");
    imprime(raiz, 0);

    exclui(raiz, 90);


    printf("\n\nArvore resultante da exclusão: \n");
    imprime(raiz, 0);
}
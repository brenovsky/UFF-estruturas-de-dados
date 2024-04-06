#include "pilhas-vetores.h"

int base, lim, topo;

void inicializa(int *base, int *lim, int *topo) {
    *base = 0;
    *lim = 9;
    *topo = -1;
}

int pilha_cheia(int lim, int topo) {
    if (topo == lim)
        return 1;
    else
        return 0;
}

int pilha_vazia(int base, int topo) {
    if (topo < base)
        return 1; //pilha vazia
    else
        return 0; //pilha tem pelo menos 1 elemento
}

/* *
 * Insere info no topo da pilha
 * retorna -1 caso não consiga inserir na pilha
 *         info caso contrário
 */
int push(TPilha *pilha, int lim, int *topo, int info) {
    if (pilha_cheia(lim, *topo)) {
        return -1;
    }
    else {
        //faz a inserção
        *topo = *topo + 1;
        pilha[*topo].info = info;
        return info;
    }
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna -1 caso não consiga excluir (pilha está vazia)
 *         info do elemento removido caso contrário
 */
int pop(TPilha *pilha, int base, int *topo) {
    if (pilha_vazia(base, *topo)) {
        return -1;
    }
    else {
        //faz a remoção
        int info = pilha[*topo].info;
        *topo = *topo - 1;
        return info;
    }
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna -1 caso pilha esteja vazia
 *         info do elemento do topo caso contrário
 */
int peek(TPilha *pilha, int base, int *topo) {
    if (pilha_vazia(base, *topo))
        return -1;
    else {
        //faz consulta
        return pilha[*topo].info;
    }
}

void imprime(TPilha *pilha, int *topo) {
    printf("\nEstado atual da Pilha:\n");
    for (int i = *topo; i >= 0; i--) {
        printf("posição [%d]: %d\n", i, pilha[i].info);
    }
    printf("\n");
}

int main() {
    TPilha pilha[10];
    inicializa(&base, &lim, &topo);
    push(pilha, lim, &topo, 5);
    printf("topo: %d\n", peek(pilha,base, &topo));
    push(pilha, lim, &topo, 4);
    printf("topo: %d\n", peek(pilha,base, &topo));
    push(pilha, lim, &topo, 3);
    printf("topo: %d\n", peek(pilha,base, &topo));

    imprime(pilha, &topo);

    int tmp = pop(pilha, base, &topo);
    printf("elemento removido: %d\n", tmp);

    imprime(pilha, &topo);
}
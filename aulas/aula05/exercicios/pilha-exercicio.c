#include "pilha-lista.h"

TPilha *inicializa() {
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void libera(TPilha *p) {
    TLista *q = p->topo;
    TLista *r;
    while(q != NULL){
        r = q;
        q=q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha) {
      if (pilha->topo == NULL)
      	return 1; //pilha vazia
      else
      	return 0; //pilha tem pelo menos 1 elemento
}

/* *
 * Insere elem no topo da pilha
 * */
void push(TPilha *pilha, int elem) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/* *
 * Altera o elemento do topo da pilha
 * */
void altera_topo(TPilha *pilha, int elem) {
	if (pilha -> topo != NULL) {
        pilha -> topo -> info = elem;
    }
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna o info do elemento excluído
 */
int pop(TPilha *pilha) {
    TLista* temp = pilha -> topo -> prox;// armazena o proximo
    int i = pilha -> topo -> info; //armazena o valor excluido
    free(pilha -> topo); //pop
    pilha -> topo = temp; // o inicio agora vai ser aquele proximo

    return i;
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna info do elemento do topo
 */
int peek(TPilha *pilha) {
    return pilha -> topo -> info;
}

void imprime_pilha(TPilha *pilha) {
    TLista* p;//auxiliar para nao baguncar a pilha (tipo TLista para nao modificar a pilha)

    for (p = pilha -> topo; p != NULL; p = p -> prox) {
        printf("%d\n", p -> info);
    }
}

int main() {
    TPilha *pilha;
    pilha = inicializa();
    push(pilha, 5);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 3);
    printf("topo: %d\n", peek(pilha));

    altera_topo(pilha, 101);

    printf("%d\n", peek(pilha));

    imprime_pilha(pilha);

    int info = pop(pilha);
    printf("elemento removido: %d\n", info);

    imprime_pilha(pilha);
}

/* ATENTAR-SE AO SEGUINTE:
- TPilha é apenas um struct com um ponteiro para o topo
- topo é um ponteiro TLista (aponta para um nó, portanto dá para acessar info e prox)
- TPilha é diferente de TLista
- O ponteiro auxiliar que itera pela pilha vai apontar para uma struct TLista
 */
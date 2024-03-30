//Ler um inteiro N.
//Alocar dinamicamente um vetor de N posições.
//Armazenar os N inteiros no vetor.
//Passar o vetor para um função que retorna o maior número digitado.
//Imprimir o maior número.

#include <stdio.h>
#include <stdlib.h>

int maiorNumero(int* vetor, int n) {

    int maior = vetor[0];

    for (int i = 1; i < n; i++) {
        if (maior <= vetor[i]) {
            maior = vetor[i];
        }
    }

    return maior;
}

int main() {

    int N, maior;
    int* vetor;

    scanf("%d", &N);

    vetor = (int*) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    maior = maiorNumero(vetor, N);

    printf("%d", maior);

    free(vetor);

    return 0;
}
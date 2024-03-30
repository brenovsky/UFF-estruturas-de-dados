//Ler um inteiro n
//Alocar dinamicamente um vetor de n floats
//Fazer a leitura de n valores e salvar no vetor
//Chamar uma função que recebe o vetor e o valor n e retorna o valor da média
//Imprimir a média

#include <stdio.h>
#include <stdlib.h>

float calculaMedia(float* vetor, int n) {
    float sum = 0;
    float m;

    for (int i = 0; i < n; i++) {
        sum += vetor[i];
    }

    m = sum / n;

    return m;
}

int main() {

    int N;
    float* vetor;
    float media;

    scanf("%d", &N);

    vetor = (float*) malloc(sizeof(float) * N);

    for (int i = 0; i < N; i++) {
        scanf("%f", &vetor[i]);
    }

    media = calculaMedia(vetor, N);

    printf("Media %.2f", media);

    free(vetor);

    return 0;
}
//Ler um inteiro n
//Alocar dinamicamente um vetor de tamanho n
//Calcular a média dos n valores
//Imprimir a média

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    float sum = 0;
    float* vetor;
    float media;

    scanf("%d", &n);

    vetor = (float*) malloc(sizeof(float) * n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &vetor[i]);
        sum += vetor[i];
    }

    media = sum / n;

    printf("Media: %f", media);

    free(vetor);

    return 0;
}
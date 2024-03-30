//Crie uma função main.
//Importe as bibliotecas necessárias.
//Leia um valor inteiro N.
//Leia N valores reais.
//Calcule a média dos valores reais lidos e imprima o resultado.

#include <stdio.h>

int main() {

    int N;
    float a, media;
    float sum = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%f", &a);
        sum += a;
    }

    media = sum / N;

    printf("Media: %.2f", media);

    return 0;
}
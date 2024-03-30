//Ler um inteiro n
//Ler n inteiros
//Printar a média dos valores lidos

#include <stdio.h>

int main() {

    int n, x;
    int sum = 0;
    float media;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }

    media = sum / n;

    printf("%f", media);

    return 0;
}
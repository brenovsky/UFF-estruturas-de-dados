#include <stdio.h>
#include <stdlib.h>

int main() {

    float x;

    printf("Insira um valor em metros:");

    scanf("%f", &x);

    printf("decimetros: %.5f\n", x * 10);
    printf("centimetros: %.5f\n", x * 100);
    printf("milimetros: %.5f\n", x * 1000);

    return 0;
}
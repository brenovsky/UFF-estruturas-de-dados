#include <stdio.h>

void imprime_valor() {
    int j = 10;
    printf("%d ", j);
    j++;
}

void main() {
    int i;
    for (i = 0; i < 4; i++) {
        imprime_valor();
    }
}
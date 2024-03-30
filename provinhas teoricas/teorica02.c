#include <stdio.h>

void soma_valor(int* j) {
   *j = 1;
}

void main() {
    int j = 0;
    soma_valor(&j);
    printf("%d", j);
}
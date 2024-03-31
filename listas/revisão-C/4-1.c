#include <stdio.h>
#include <stdlib.h>

float potencia(float x, int n) {
    float p = 1;

    for (int i = 0; i < n; i++) {
        p *= x;
    }

    return p;
}

int main() {

    float x;
    int n;

    scanf("%f %d", &x, &n);

    printf("%f", potencia(x, n));

    return 0;
}
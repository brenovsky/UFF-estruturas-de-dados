#include <stdio.h>
#include <stdlib.h>

float potencia(float x, int n) {
    float p = 1;

    for (int i = 0; i < n; i++) {
        p *= x;
    }

    return p;
}

int fatorial(int n) {

    if (n == 0) {
        return 1;
    }

    return n * fatorial(n - 1);
}

float euler(float x) {

    float res = 0;

    for (int i = 0; (potencia(x, i) / fatorial(i)) > (10 / potencia(10, 6)); i++) {
        res += (potencia(x, i) / fatorial(i));
    }

    return res;
}

int main() {

    float x;

    scanf("%f", &x);

    printf("e^(%.2f) = %.3f", x, euler(x));

    return 0;
}
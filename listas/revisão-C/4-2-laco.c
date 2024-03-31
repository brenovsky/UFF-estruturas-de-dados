#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    int p = 1;

    for (int i = 1; i <= n; i++) {
        p *= i;
    }

    return p;
}

int main() {

    int n;

    scanf("%d", &n);

    printf("%d! = %d", n, fatorial(n));

    return 0;
}
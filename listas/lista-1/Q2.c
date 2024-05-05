#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x, p, n;

    scanf("%d", &x);

    p = ceil(log2(x + 1));
    n = p;

    int v[p];

    while(x > 0) {
        v[p - 1] = x % 2;

        x /= 2;

        p -= 1;
    }

    for (int i = 0;  i < n; i++) {
        printf("%d", v[i]);
    }

    return 0;
}
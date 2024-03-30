#include <stdio.h>
#include <stdlib.h>

int main() {

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("----------\n");
    }

    return 0;
}
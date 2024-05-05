#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int x;
    int previous = 0;
    int sequence = 0;
    int max_sequence = 0;

    scanf("%d", &n);

    while (n > 0) {
        scanf("%d", &x);

        if (x > previous) sequence += 1;
        else sequence = 1;

        previous = x;

        if (sequence > max_sequence) max_sequence = sequence;

        n -= 1;
    }

    printf("%d", max_sequence);

    return 0;
}
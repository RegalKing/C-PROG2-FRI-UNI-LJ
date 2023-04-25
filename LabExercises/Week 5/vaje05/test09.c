
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

char* NIZ = "A quick brown fox jumps over the lazy dog.";

int main() {
    int* frekvence;
    frekvenceCrk(NIZ, &frekvence);
    for (int c = 'A';  c <= 'Z';  c++) {
        if (frekvence[c - 'A'] > 0) {
            printf("%c -> %d\n", c, frekvence[c - 'A']);
        }
    }

    free(frekvence);

    exit(0);
    return 0;
}

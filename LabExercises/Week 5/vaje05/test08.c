
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int main() {
    int* frekvence;
    frekvenceCrk("O VrBa! sRecNa, dRAgA vaS DomACa", &frekvence);
    for (int c = 'A';  c <= 'Z';  c++) {
        if (frekvence[c - 'A'] > 0) {
            printf("%c -> %d\n", c, frekvence[c - 'A']);
        }
    }

    free(frekvence);

    exit(0);
    return 0;
}

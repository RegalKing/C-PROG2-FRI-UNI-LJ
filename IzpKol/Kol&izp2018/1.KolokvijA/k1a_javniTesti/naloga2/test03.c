
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "DE B UKA ZEJA ME IZ TVOJGA SVETA";

int K[] = {1, 2, 5, 10, 11};
int ST_K = sizeof(K) / sizeof(int);

int __main__() {
    int indeks = 0;
    for (int i = 0;  i < ST_K;  i++) {
        steviloInKta(NIZ, K[i], &indeks);
        printf("%d: %d\n", K[i], indeks);
    }
    exit(0);
    return 0;
}

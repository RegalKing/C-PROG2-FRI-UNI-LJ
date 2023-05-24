
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "kjer hisa mojega stoji oceta;";

int __main__() {
    int* t = NULL;
    indeksi(NIZ, &t);

    int i = 0;
    printf("[ ");
    while (t[i] != -1) {
        printf("%d ", t[i]);
        i++;
    }
    printf("]\n");

    free(t);

    exit(0);
    return 0;
}

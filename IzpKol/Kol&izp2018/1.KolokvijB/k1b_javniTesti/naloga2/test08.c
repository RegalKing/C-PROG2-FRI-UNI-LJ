
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "O Vrba! srecna, draga vas domaca,";

int __main__() {
    char* podniz = kopijaPodniza(NIZ, ' ', 1);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, ' ', 2);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, 'a', 5);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, 'a', 6);
    printf("\"%s\"\n", podniz);
    free(podniz);

    exit(0);
    return 0;
}

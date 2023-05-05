
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "wbk_WTRZLwqAZ4uuBewosNwLL1XgfQJF4z6pWLvyQSLKubNWXayfiE5dQctuOfG_alg14m4OUZBwoQdj46EfKXKaGaWflBKyZb6dXkZMxnEsFO3JHi7Kw6K",
};

int main() {
    int stIzhodnih = 0;
    char** izhodni = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%d: \"%s\"\n", i, izhodni[i]);
        free(izhodni[i]);
    }
    free(izhodni);
    return 0;
}

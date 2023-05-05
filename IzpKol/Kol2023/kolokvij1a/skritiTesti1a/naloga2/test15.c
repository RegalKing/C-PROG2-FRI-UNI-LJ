
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "zaA0CLM3JkDX3wa9rbNBvCQnQsBHzqPfQVNrl_3RulhXdWm1htl3T7N72Av5gv",
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

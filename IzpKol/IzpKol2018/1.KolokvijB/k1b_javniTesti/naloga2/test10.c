
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "   de   b uka    zeja me iz  tvojga sveta   ";

int __main__() {
    for (int k = 1;  k <= 18;  k++) {
        char* podniz = kopijaPodniza(NIZ, ' ', k);
        printf("\"%s\"\n", podniz);
        free(podniz);
    }

    exit(0);
    return 0;
}

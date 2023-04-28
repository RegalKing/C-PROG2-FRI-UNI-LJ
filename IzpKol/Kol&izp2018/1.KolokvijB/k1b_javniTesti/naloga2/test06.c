
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "   de   b uka    zeja me iz  tvojga sveta   ";

int __main__() {
    for (int i = 0;  i < 44;  i++) {
        int indeks = i;
        naslednjaPojavitev(NIZ, &indeks);
        printf("\'%c\': %d -> %d\n", NIZ[i], i, indeks);
    }
    exit(0);
    return 0;
}

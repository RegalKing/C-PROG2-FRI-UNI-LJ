
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "O Vrba! srecna, draga vas domaca,";

int __main__() {
    for (int i = 0;  i < 33;  i++) {
        int indeks = i;
        naslednjaPojavitev(NIZ, &indeks);
        printf("\'%c\': %d -> %d\n", NIZ[i], i, indeks);
    }
    exit(0);
    return 0;
}

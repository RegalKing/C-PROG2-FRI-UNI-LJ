
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ1 = "O vrbA! sreCnA, drAGA vAs dOmaCa,";
char* NIZ2 = "o VRBa! SREcNa, DRaga VaS DoMAcA,";

int __main__() {
    int indeks = 0;
    int stPojavitev = steviloInKta(NIZ1, 1, &indeks);
    printf("%d\n", stPojavitev);
    stPojavitev = steviloInKta(NIZ2, 1, &indeks);
    printf("%d\n", stPojavitev);

    exit(0);
    return 0;
}

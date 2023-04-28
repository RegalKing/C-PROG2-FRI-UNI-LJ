
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* n;
    struct _Vozlisce* nn;
} Vozlisce;

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element);

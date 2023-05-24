
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi);

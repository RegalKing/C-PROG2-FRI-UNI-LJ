
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "naloga.h"

char NIZ[1000];

Vozlisce* zgradi(int* t) {
    Vozlisce* zacetek = NULL;
    Vozlisce* prejsnje = NULL;
    int* p = t;

    while (*p != INT_MAX) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = *p;
        novo->naslednje = NULL;
        if (p == t) {
            zacetek = novo;
        } else {
            prejsnje->naslednje = novo;
        }
        prejsnje = novo;
        p++;
    }
    return zacetek;
}

void pocisti(Vozlisce* v) {
    if (v != NULL) {
        pocisti(v->naslednje);
        free(v);
    }
}

char* vNiz(Vozlisce* zacetek) {
    char* pNiz = NIZ;
    *pNiz++ = '[';
    Vozlisce* v = zacetek;
    while (v != NULL) {
        if (v != zacetek) {
            pNiz += sprintf(pNiz, ", ");
        }
        pNiz += sprintf(pNiz, "%d", v->podatek);
        v = v->naslednje;
    }
    sprintf(pNiz, "]");
    return NIZ;
}

void testiraj(Vozlisce* v) {
    printf("%s -> %d\n", vNiz(v), vsotaR(v));
    pocisti(v);
}

int __main__() {
    testiraj(zgradi((int[]) {2, 3, INT_MAX}));
    testiraj(zgradi((int[]) {6, 8, 7, INT_MAX}));
    testiraj(zgradi((int[]) {9, 2, 7, 0, 1, 5, 3, INT_MAX}));
    testiraj(zgradi((int[]) {-3, -6, -2, -4, INT_MAX}));

    exit(0);
    return 0;
}

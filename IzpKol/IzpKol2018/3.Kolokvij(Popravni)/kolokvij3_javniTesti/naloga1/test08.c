
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

#define MNOZITELJ 100003
#define INKREMENT 199999
#define MODULO 333667

int g_r = 0;

void mojSrand(int seme) {
    g_r = seme;
}

int mojRand() {
    g_r = (MNOZITELJ * g_r + INKREMENT) % MODULO;
    if (g_r < 0) {
        g_r += MODULO;
    }
    return g_r;
}

Vozlisce* zgradi(int seme, int dolzina) {
    mojSrand(seme);
    Vozlisce* zacetek = NULL;
    for (int i = 0;  i < dolzina;  i++) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->znak = mojRand() % 95 + 32;
        novo->naslednje = zacetek;
        zacetek = novo;
    }
    return zacetek;
}

void pocisti(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        Vozlisce* q = p->naslednje;
        free(p);
        p = q;
    }
}

int __main__() {
    int dolzina = 1002;
    Vozlisce* zacetek = zgradi(10008, dolzina);
    char* niz = sestavi(zacetek);
    printf("|%s|\n", niz);
    if (niz[dolzina] == '\0') {
        printf("+\n");
    } else {
        printf("-\n");
    }
    pocisti(zacetek);
    free(niz);

    exit(0);
    return 0;
}

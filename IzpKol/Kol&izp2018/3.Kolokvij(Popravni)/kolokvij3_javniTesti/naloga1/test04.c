
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

char TABELA[] = {'a', 'b', 'c', '1', '2', '3'};

Vozlisce* zgradi(char* znaki, int dolzina) {
    Vozlisce* zacetek = NULL;
    for (int i = dolzina - 1;  i >= 0;  i--) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->znak = TABELA[i];
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
    int dolzina = sizeof(TABELA) / sizeof(char);
    Vozlisce* zacetek = zgradi(TABELA, dolzina);
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


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* ustvari(int* t, int n, Vozlisce** podatek2vozlisce) {
    Vozlisce* zacetek = NULL;
    Vozlisce* konec = NULL;
    for (int i = 0;  i < n;  i++) {
        Vozlisce* novo = calloc(1, sizeof(Vozlisce));
        podatek2vozlisce[novo->podatek = t[i]] = novo;
        if (konec == NULL) {
            zacetek = konec = novo;
        } else {
            konec->naslednje = novo;
            konec = novo;
        }
    }
    return zacetek;
}

void pobrisi(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        Vozlisce* q = p->naslednje;
        free(p);
        p = q;
    }
}

void izpisi(Vozlisce* zacetek, Vozlisce** podatek2vozlisce) {
    printf("[");
    bool prvic = true;
    Vozlisce* p = zacetek;
    while (p != NULL) {
        if (prvic) {
            prvic = false;
        } else {
            printf(", ");
        }
        printf("%d", p->podatek);
        p = p->naslednje;
    }
    printf("]\n");

    p = zacetek;
    while (p != NULL) {
        printf("%d", p == podatek2vozlisce[p->podatek]);
        p = p->naslednje;
    }
    printf("\n");
}

int main() {
    FILE* f = fopen("test05.dat", "r");
    int da = 0;
    fscanf(f, "%d", &da);
    int* ta = malloc(da * sizeof(int));
    for (int i = 0;  i < da;  i++) {
        fscanf(f, "%d", &ta[i]);
    }
    int db = 0;
    fscanf(f, "%d", &db);
    int* tb = malloc(db * sizeof(int));
    for (int i = 0;  i < db;  i++) {
        fscanf(f, "%d", &tb[i]);
    }
    fclose(f);

    Vozlisce** podatek2vozlisce = malloc(200001 * sizeof(Vozlisce*));

    Vozlisce* a = ustvari(ta, da, podatek2vozlisce);
    Vozlisce* b = ustvari(tb, db, podatek2vozlisce);

    Vozlisce* c = zlij(a, b);

    izpisi(c, podatek2vozlisce);
    pobrisi(c);

    free(ta);
    free(tb);
    free(podatek2vozlisce);

    return 0;
}

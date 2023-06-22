
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int main() {
    FILE* f = fopen("test35.dat", "r");
    int uvod = 0;
    int cikel = 0;
    fscanf(f, "%d%d", &uvod, &cikel);
    fclose(f);

    int skupaj = uvod + cikel;
    Vozlisce* prejsnje = NULL;
    Vozlisce* zacetek = NULL;
    Vozlisce* sticisce = NULL;
    for (int i = 0;  i < skupaj;  i++) {
        Vozlisce* v = calloc(1, sizeof(Vozlisce));
        if (prejsnje != NULL) {
            prejsnje->naslednje = v;
        }
        if (i == 0) {
            zacetek = v;
        }
        if (i == uvod) {
            sticisce = v;
        }
        if (i == skupaj - 1) {
            v->naslednje = sticisce;
        }
        prejsnje = v;
    }

    int dolzina = dolzinaCikla(zacetek);
    printf("%d\n", dolzina);

    Vozlisce* v = zacetek;
    for (int i = 0;  i < skupaj;  i++) {
        Vozlisce* w = v->naslednje;
        free(v);
        v = w;
    }

    return 0;
}

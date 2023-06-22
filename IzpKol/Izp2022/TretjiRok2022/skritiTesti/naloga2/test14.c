
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* zgradi(char** vrstice, int stVrstic) {
    if (stVrstic == 0) {
        return NULL;
    }
    Vozlisce* zacetek = malloc(sizeof(Vozlisce));
    zacetek->niz = calloc((strlen(*vrstice) + 20), sizeof(char));
    strcpy(zacetek->niz, *vrstice);
    zacetek->naslednje = zgradi(vrstice + 1, stVrstic - 1);
    return zacetek;
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->naslednje);
        free(zacetek->niz);
        free(zacetek);
    }
}

int main() {
    FILE* f = fopen("test14.dat", "r");

    char temp[20];
    fgets(temp, 20, f);
    int stVrstic = atoi(temp);

    char** vrstice = malloc(stVrstic * sizeof(char*));
    char* vrstica = malloc(1010 * sizeof(char));
    for (int i = 0;  i < stVrstic;  i++) {
        fgets(vrstica, 1010, f);
        int dolzina = strlen(vrstica);
        vrstica[dolzina - 1] = '\0';
        vrstice[i] = malloc(dolzina * sizeof(char));
        strcpy(vrstice[i], vrstica);
    }
    fclose(f);
    free(vrstica);

    Vozlisce* zacetek = zgradi(vrstice, stVrstic);
    vstaviH1(zacetek);

    for (Vozlisce* p = zacetek;  p != NULL;  p = p->naslednje) {
        printf("%s\n", p->niz);
    }

    pocisti(zacetek);
    for (int i = 0;  i < stVrstic;  i++) {
        free(vrstice[i]);
    }
    free(vrstice);

    return 0;
}

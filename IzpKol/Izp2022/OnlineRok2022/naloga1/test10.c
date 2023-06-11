
#include "naloga1.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    FILE* f = fopen("test10.dat", "r");
    int stOseb = 0;
    fscanf(f, "%d", &stOseb);

    char ime[100] = {'\0'};
    char predpona[100] = {'\0'};

    Oseba** osebe = malloc(stOseb * sizeof(Oseba*));
    for (int i = 0;  i < stOseb;  i++) {
        Oseba* oseba = calloc(1, sizeof(Oseba));
        fscanf(f, "%s%s", ime, oseba->telefon);
        oseba->ime = calloc(strlen(ime) + 1, sizeof(char));
        strcpy(oseba->ime, ime);
        osebe[i] = oseba;
    }
    fscanf(f, "%s", predpona);
    fclose(f);

    vstaviPredpono(predpona, osebe, stOseb);

    for (int i = 0;  i < stOseb;  i++) {
        printf("%s / %s\n", osebe[i]->ime, osebe[i]->telefon);
    }

    for (int i = 0;  i < stOseb;  i++) {
        free(osebe[i]->ime);
        free(osebe[i]);
    }
    free(osebe);
    return 0;
}

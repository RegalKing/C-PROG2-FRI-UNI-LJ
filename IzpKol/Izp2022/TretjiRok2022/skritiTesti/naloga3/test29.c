
#include <stdio.h>
#include <stdlib.h>

#include "naloga3.h"

void izpisi(Vozlisce* koren) {
    if (koren == NULL) {
        printf("-");
        return;
    }
    printf("%d", koren->podatek);
    if (koren->levo != NULL || koren->desno != NULL) {
        printf("[");
        izpisi(koren->levo);
        printf(", ");
        izpisi(koren->desno);
        printf("]");
    }
}

void pocisti(Vozlisce* koren) {
    if (koren != NULL) {
        pocisti(koren->levo);
        pocisti(koren->desno);
        free(koren);
    }
}

int main() {
    FILE* f = fopen("test29.dat", "r");
    int n = 0;
    fscanf(f, "%d", &n);
    int velikost = (1 << n) - 1;
    int* tabela = malloc(velikost * sizeof(int));
    for (int i = 0;  i < velikost;  i++) {
        fscanf(f, "%d", &tabela[i]);
    }
    fclose(f);

    Vozlisce* koren = drevo(n, tabela);
    izpisi(koren);
    printf("\n");
    pocisti(koren);
    free(tabela);

    return 0;
}

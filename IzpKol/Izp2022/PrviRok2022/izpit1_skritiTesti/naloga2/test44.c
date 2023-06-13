#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

void izpisi(Vozlisce* p) {
    printf("[");
    bool prvic = true;
    while (p != NULL) {
        if (!prvic) {
            printf(", ");
        }
        prvic = false;
        printf("%d", *(p->vTabelo));
        p = p->naslednje;
    }
    printf("]\n");
}

void pocisti(Vozlisce* p) {
    while (p != NULL) {
        Vozlisce* q = p->naslednje;
        free(p);
        p = q;
    }
}

int main() {
    FILE* f = fopen("test44.dat", "r");

    int d = 0;
    fscanf(f, "%d", &d);

    int* t = malloc(d * sizeof(int));
    for (int i = 0;  i < d;  i++) {
        fscanf(f, "%d", &t[i]);
    }

    int n = 0;
    fscanf(f, "%d", &n);

    fclose(f);

    Vozlisce** tabSez = tabelaSeznamov(t, d, n);

    for (int i = 0;  i < n;  i++) {
        izpisi(tabSez[i]);
    }

    for (int i = 0;  i < n;  i++) {
        pocisti(tabSez[i]);
    }

    free(tabSez);
    free(t);

    return 0;
}

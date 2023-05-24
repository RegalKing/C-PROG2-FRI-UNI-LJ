
#include "naloga2.h"

Vozlisce* v(int podatek, Vozlisce* naslednje) {
    Vozlisce* vozlisce = malloc(sizeof(Vozlisce));
    vozlisce->podatek = podatek;
    vozlisce->naslednje = naslednje;
    return vozlisce;
}

void izpisi(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    printf("[");
    while (p != NULL) {
        if (p != zacetek) {
            printf(", ");
        }
        printf("%d", p->podatek);
        p = p->naslednje;
    }
    printf("]\n");
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->naslednje);
        free(zacetek);
    }
}

Vozlisce* zgradiOsnovo() {
    return v(30, v(40, v(20, v(50, NULL))));
}

Vozlisce* zgradiIndekse() {
    return v(3, NULL);
}

int __main__() {
    Vozlisce* osnova = zgradiOsnovo();
    Vozlisce* indeksi = zgradiIndekse();
    Vozlisce* rezultat = odstrani(osnova, indeksi);

    izpisi(rezultat);

    pocisti(indeksi);
    pocisti(rezultat);

    exit(0);
    return 0;
}

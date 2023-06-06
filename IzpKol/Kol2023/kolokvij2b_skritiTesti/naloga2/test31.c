#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {4032, 437, 7209, 7127, 3061, 9172, 7495, 5764, 5758, 3979, 743, 965, 9042, 828, 1177, 9662, 6427, 1443, 5041, 8122, 9859, 6753, 2752, 5055, 3989, 4705, 5158, 4137, 2396, 5543, 2709, 1874, 8859, 3290, 6294, 4845, 1038, 1908, 5842, 860, 750, 8111, 7879, 5369, 4178, 6608, 996, 6084, 1650, 2450, 2176, 564, 4092, 6193, 112, 3999, 3309, 8848, 9611, 135, 2761, 5948, 7410, 2694, 8944, 8056, 7277, 3572, 7789, 4065, 8224, 9556, 2032, 4664, 1445, 2989, 8686, 3031, 8670, 7275, 2746, 8364, 4028, 8841, 6125, 9334, 5133};
int _RAZREDI[] = {0, 1, 0, 2, 0, 3, 4, 5, 1, 6, 7, 1, 8, 9, 10, 6, 11, 12, 13, 14, 15, 6, 16, 10, 17, 18, 19, 20, 21, 22, 23, 0, 24, 25, 26, 11, 12, 17, 27, 28, 29, 30, 30, 31, 27, 8, 0, 30, 32, 0, 0, 3, 33, 34, 6, 35, 36, 37, 21, 17, 38, 39, 40, 41, 11, 21, 42, 43, 3, 44, 2, 45, 46, 45, 47, 48, 47, 30, 6, 49, 50, 51, 52, 53, 0, 54, 55};
int _ST_VOZLISC = sizeof(_RAZREDI) / sizeof(_RAZREDI[0]);
#define  _ST_RAZREDOV (sizeof(_P) / sizeof(_P[0]))
Vozlisce* _I2V[_ST_RAZREDOV];
bool _POBRISAN[_M];

Vozlisce* _ustvari() {
    Vozlisce* zacetek = NULL;
    Vozlisce* prej = NULL;
    int zadnjiRazred = -1;

    for (int i = 0; i < _ST_VOZLISC; i++) {
        Vozlisce* v = calloc(1, sizeof(Vozlisce));
        int r = _RAZREDI[i];
        if (r > zadnjiRazred) {
            zadnjiRazred = r;
            v->p = malloc(sizeof(int));
            *v->p = _P[r];
            _I2V[r] = v;
        } else {
            v->p = _I2V[r]->p;
        }
        if (i == 0) {
            zacetek = v;
        } else {
            prej->naslednje = v;
        }
        prej = v;
    }
    return zacetek;
}

void _izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        printf("%s%d", (w == v ? "" : ", "), *w->p);
        w = w->naslednje;
    }
    printf("]\n");
}

void _preveriIstovetnost(Vozlisce* v) {
    int i = 0;
    for (Vozlisce* w = v; w != NULL; w = w->naslednje) {
        printf("%d", w == _I2V[i]);
        i++;
    }
    printf("\n");
}

void _pocisti(Vozlisce* v) {
    if (v != NULL) {
        _pocisti(v->naslednje);
        int pp = *v->p;
        if (!_POBRISAN[pp]) {
            free(v->p);
            v->p = NULL;
            _POBRISAN[pp] = true;
        }
        free(v);
    }
}

int main() {
    Vozlisce* v = _ustvari();

    printf("Prej:\n");
    _izpisi(v);
    printf("\n");

    izlociDuplikate(v);

    printf("Potem:\n");
    _izpisi(v);
    printf("\n");

    printf("Istovetnost ohranjenih vozlisc:\n");
    _preveriIstovetnost(v);

    _pocisti(v);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {8326, 2418, 7357, 4983, 7540, 8592, 5462, 3530, 2927, 4359, 405, 3186, 2825, 9290, 5921, 675, 450, 720, 3145, 2657, 1805, 7109, 193, 1319, 7443, 1234, 6259, 564, 197, 4427, 4700, 4679, 6363, 572, 5400, 5941, 8441, 6121, 9586, 6792, 2649, 2481, 3948, 1231, 6325, 4588, 9878, 9051, 6315, 7938, 9013, 6818, 2567, 3484, 5930, 767, 9757, 8774, 8790, 7319};
int _RAZREDI[] = {0, 0, 0, 0, 1, 0, 2, 3, 4, 5, 0, 6, 4, 0, 7, 1, 0, 1, 8, 6, 9, 8, 1, 8, 1, 10, 5, 9, 7, 5, 11, 5, 12, 4, 13, 5, 4, 6, 10, 8, 14, 15, 15, 15, 16, 16, 6, 16, 17, 5, 15, 15, 0, 18, 19, 4, 20, 21, 5, 22};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {8992, 9064, 4391, 4018, 3763, 322, 2567, 3358, 4255, 4180, 729, 3457, 9853, 6338, 2797, 1596, 1857, 9821, 3583, 634, 6433, 8063, 4337, 4479, 9910, 1210, 6327, 2044, 564, 4210, 7129, 5097, 3869, 2531, 5785, 9071, 6669, 7865, 1653, 7558, 5301, 4835, 8757, 2908, 2623, 9796, 7717, 5784, 6589, 7260, 3900, 1759, 690, 2697, 16, 7871, 1838, 303, 1782, 7627, 3105, 4935, 8825, 8538, 8644, 8506, 8204, 8990, 1671, 993, 833, 7536, 1462, 5406, 559, 4746, 3094, 7564, 7410, 5072, 174, 1530, 6744, 4145, 4777, 7766, 2924, 3446};
int _RAZREDI[] = {0, 0, 1, 0, 2, 0, 3, 1, 2, 1, 0, 4, 0, 5, 3, 3, 6, 4, 4, 7, 4, 0, 1, 0, 8, 9, 10, 11, 0, 0, 12, 0, 13, 14, 15, 16, 0, 17, 6, 18, 2, 14, 19, 4, 20, 0, 21, 20, 22, 20, 23, 4, 1, 17, 24, 13, 20, 4, 25, 15, 26, 2, 27, 2, 20, 28, 29, 0, 30, 31, 1, 2, 32, 1, 3, 1, 33, 34, 2, 1, 10, 35, 0, 36, 15, 0, 37, 38};
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

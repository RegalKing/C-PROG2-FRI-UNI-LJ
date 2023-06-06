#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {1462, 4491, 307, 9051, 6823, 1892, 744, 8938, 2716, 1162, 2647, 2623, 6948, 9615, 6020, 8845, 2718, 9038, 5351, 7727, 1994, 1783, 7527, 2912, 7082, 9567, 1561, 9071, 5865, 673, 9220, 546, 6039, 6184, 4312, 9903, 6154, 8814, 3510, 3753, 3590, 7932, 1919, 8657, 5550, 5594, 5993, 9828, 614, 8421, 4756, 8493, 9194, 3080, 8764, 1668, 5486, 5482, 6481, 1930, 9641, 1494, 8910, 6897, 4869, 1234, 7224, 2214, 7776, 7372, 7889, 3284, 6640, 4946};
int _RAZREDI[] = {0, 0, 1, 2, 3, 3, 4, 3, 0, 5, 6, 7, 8, 9, 0, 10, 11, 12, 6, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 20, 24, 25, 26, 27, 28, 29, 30, 31, 22, 32, 33, 27, 34, 35, 36, 37, 38, 28, 32, 39, 40, 20, 41, 42, 43, 12, 5, 22, 36, 44, 27, 26, 11, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {7766, 2307, 2182, 1586, 8206, 2069, 7617, 5820, 1393, 9674, 3855, 8656, 2008, 7554, 7839, 6362, 1576, 4050, 3444, 8087, 5597, 4448, 357, 6205, 3018, 901, 1027, 4347, 8506, 3013, 7622, 7769, 669, 4229, 946, 5583, 6356, 4690, 8624, 9716, 6689, 7833, 8376, 6001, 9732, 4168, 5442, 3820, 967, 807, 6120, 1233, 9957, 7209, 6525, 2587, 1069, 4710, 7897, 2110, 4044, 3128, 7316, 5291, 7707, 58, 872, 7731, 6023, 1274, 3579, 919, 9283, 8711, 8106, 8952, 4096, 6508, 9574, 2801, 1761, 2233, 7826, 689, 6275};
int _RAZREDI[] = {0, 1, 2, 0, 3, 4, 2, 5, 6, 0, 2, 2, 7, 0, 1, 8, 9, 2, 10, 2, 9, 2, 11, 12, 2, 13, 14, 5, 14, 7, 2, 13, 15, 16, 2, 17, 1, 5, 18, 19, 20, 0, 2, 21, 7, 22, 7, 13, 9, 23, 24, 25, 25, 26, 2, 27, 2, 28, 29, 2, 30, 31, 32, 2, 17, 13, 33, 34, 35, 31, 36, 9, 37, 2, 7, 38, 39, 40, 19, 41, 17, 0, 42, 43, 28};
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

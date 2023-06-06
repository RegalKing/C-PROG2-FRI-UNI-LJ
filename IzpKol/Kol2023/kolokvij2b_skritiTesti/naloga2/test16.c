#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {3032, 4944, 4364, 936, 4848, 5488, 3156, 7915, 8980, 1986, 675, 5031, 7676, 6646, 2148, 2656, 6929, 5458, 9401, 8156, 8375, 5019, 7223, 193, 6649, 3373, 3024, 9917, 1184, 7639, 2965, 3886, 4466, 5463, 3030, 5615, 4344, 6036, 4942, 1337, 441, 3041, 1064, 5856, 9562, 4494, 100, 5180, 6657, 7281, 6173, 7633, 7836, 5033, 832, 9936, 2961, 766, 3401, 8731, 3409, 7136, 2951, 486, 1694, 8652, 8858, 5473, 3697, 2294, 7607, 3790, 5466, 6870, 6617, 3242, 8605, 8068, 5341, 5624, 8638, 5794, 4824, 1599, 8644, 9757, 315};
int _RAZREDI[] = {0, 1, 2, 3, 4, 5, 6, 3, 7, 3, 8, 9, 10, 11, 8, 7, 12, 13, 14, 7, 15, 16, 17, 18, 19, 20, 21, 22, 15, 8, 8, 23, 24, 25, 0, 26, 27, 0, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 29, 26, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 49, 70, 71, 72, 73};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {5327, 469, 1482, 2731, 3869, 2653, 7117, 2098, 9230, 1587, 8752, 3529, 1536, 2423, 3409, 2454, 792, 6771, 1113, 7237, 4491, 2148, 9251, 9409, 3355, 6618, 9280, 3322, 1473, 2229, 3306, 6942, 5858, 4477, 2827, 316, 4657, 5382, 4452, 4504, 2152, 2925, 180, 2307, 1992, 1985, 431, 3314, 5535, 6351, 1468, 9610, 6808, 424, 827, 7014, 5083, 4368, 9125, 9240, 8333, 2997, 9788, 920, 8358, 9372, 6260, 6836, 4849, 6376, 1982, 8733, 7085, 3693, 7374, 5863, 3996, 9206, 8667, 4482, 6372, 7809, 2001, 6827, 9962, 4544, 9952, 8158, 3308, 9109, 8603, 5614, 8390, 1787, 2803, 4073, 5626, 2052, 4767, 8109, 4990};
int _RAZREDI[] = {0, 1, 2, 3, 4, 5, 6, 7, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 19, 21, 22, 23, 24, 25, 26, 27, 15, 28, 29, 30, 1, 31, 32, 33, 34, 32, 35, 29, 36, 23, 37, 38, 37, 39, 40, 41, 42, 43, 44, 45, 11, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 5, 58, 59, 5, 60, 61, 62, 63, 64, 65, 17, 66, 67, 68, 69, 70, 71, 72, 32, 73, 74, 75, 62, 46, 67, 76, 77, 3, 78, 79, 80, 77, 81, 42};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {5095, 7210, 9475, 3361, 5688, 5019, 3354, 8433, 2528, 5951, 4108, 2045, 8221, 4478, 40, 444, 1845, 2284, 286, 1645, 9318, 6271, 3161, 8315, 1728, 4806, 3276, 7137, 763, 5331, 6273, 5546, 2639, 6979, 9214, 2647, 528, 1589, 134, 5695, 1464, 3943, 8795, 7684, 279, 7881, 9353, 8524, 3038, 5968, 4341, 7348, 1445, 5139, 3239, 9210, 5560, 7364, 8347, 1157, 3471, 9531, 1856, 1616, 3939, 9376, 6690, 6642, 5301, 9153, 8431, 4560, 139, 5561, 5988, 2491, 7036, 9211, 295, 966};
int _RAZREDI[] = {0, 1, 2, 1, 3, 4, 5, 6, 7, 1, 8, 9, 9, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 14, 7, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 20, 17, 29, 30, 31, 32, 33, 34, 35, 36, 28, 37, 1, 38, 39, 39, 40, 14, 41, 25, 42, 43, 38, 44, 45, 46, 47, 48, 49, 50, 51, 29, 52, 53, 54, 55, 56, 57, 58, 43, 59, 60, 1, 61, 62};
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

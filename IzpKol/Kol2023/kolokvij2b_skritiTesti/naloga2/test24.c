#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {3256, 8994, 679, 8873, 25, 8428, 816, 7497, 7404, 981, 214, 9400, 3486, 6126, 2805, 3665, 8694, 2688, 2668, 9133, 1702, 992, 435, 8135, 3313, 5024, 6915, 7976, 5546, 3072, 1499, 7762, 7518, 3995, 8092, 722, 2873, 5641, 4290, 255, 163, 4280, 9315, 9983, 3918, 3481, 7885, 871, 2062, 3309, 1526, 2876, 220, 232, 640, 277, 5917, 7259, 8632, 5237, 7692, 5495, 9490, 6533, 2110, 1421, 746, 5208, 112, 5918, 1616, 4412, 1414, 1204, 8161, 7991, 8921, 2183, 6344, 2363, 3128, 5473, 3377, 3315, 5566, 441, 3027, 5257, 1801, 3987, 4727, 2138, 1884};
int _RAZREDI[] = {0, 1, 2, 0, 2, 2, 0, 0, 3, 2, 0, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 5, 2, 5, 2, 0, 4, 1, 1, 4, 1, 2, 1, 0, 0, 1, 2, 1, 1, 6, 0, 1, 2, 1, 0, 2, 4, 7, 2, 1, 2, 8, 1, 2, 2, 4, 1, 9, 7, 2, 0, 2, 2, 2, 0, 2, 9, 10, 1, 1, 0, 2, 1, 0, 7, 2, 11, 2, 1, 2, 1, 0, 11, 2, 7, 2, 8, 1, 2, 0, 2, 7};
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

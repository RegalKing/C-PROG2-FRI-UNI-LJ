#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {9027, 1864, 6574, 9241, 1850, 3206, 2810, 6048, 877, 5099, 1458, 1488, 6222, 3585, 1459, 4475, 8287, 6705, 8227, 9789, 9263, 104, 939, 2902, 7306, 4798, 1420, 5986, 6006, 8127, 6776, 8424, 7280, 4036, 2534, 3844, 4359, 2046, 3763, 2414, 9268, 952, 7414, 9869, 2596, 9478, 4591, 9519, 5756, 6136, 3461, 9571, 3948, 5004, 8510, 2904, 1786, 899, 1947, 5911, 5144, 5828, 3251, 1863, 9300, 3679, 4577, 6058, 6541, 9008, 8929, 1262, 645, 1076, 6155, 487, 3045, 8186, 446, 9835};
int _B[] = {3244, 778, 9027, 9008, 1697, 6155, 446, 2955, 9789, 4591, 8510, 3234, 9081, 2414, 4359, 6232, 8314, 3491, 5537, 4072, 1340, 8672, 487, 645, 5426, 4253, 2810, 6893, 6705, 2780, 1420, 104, 7639, 8627, 9263, 6516, 9820, 6048, 2925, 9519, 7227, 6754, 3763, 2132, 1786, 8892, 877, 2904, 3844, 3251, 9571, 2217, 7273, 8929, 418, 8411, 2046, 3948, 3120, 8521, 4036, 8424, 5985, 4719, 9271, 9497, 2190, 8177, 6136, 6006, 1380, 1515, 4190, 3318, 4524, 9723, 7065, 23, 2145, 8140, 2736, 9484};
Vozlisce* _I2A[_M];
Vozlisce* _I2B[_M];

Vozlisce* _izTabele(int* t, int n, Vozlisce** i2v) {
    if (n == 0) {
        return NULL;
    }
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = *t;
    i2v[*t] = v;
    v->naslednje = _izTabele(t + 1, n - 1, i2v);
    return v;
}

void _izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        printf("%s%d", (w == v ? "" : ", "), w->podatek);
        w = w->naslednje;
    }
    printf("]\n");
}

void _istovetnost(Vozlisce* v, Vozlisce** i2v) {
    for (Vozlisce* w = v; w != NULL; w = w->naslednje) {
        printf("%d", w == i2v[w->podatek]);
    }
    printf("\n");
}

void _pocisti(Vozlisce* v) {
    if (v != NULL) {
        _pocisti(v->naslednje);
        free(v);
    }
}

int main() {
    Vozlisce* a = _izTabele(_A, sizeof(_A) / sizeof(int), _I2A);
    Vozlisce* b = _izTabele(_B, sizeof(_B) / sizeof(int), _I2B);

    printf("Prej:\n");
    _izpisi(a);
    _izpisi(b);
    printf("\n");

    Vozlisce* na = NULL;
    Vozlisce* nb = NULL;
    izlociSkupne(a, b, &na, &nb);

    printf("Potem:\n");
    _izpisi(na);
    _izpisi(nb);
    printf("\n");

    printf("Istovetnost ohranjenih vozlisc:\n");
    _istovetnost(na, _I2A);
    _istovetnost(nb, _I2B);

    _pocisti(na);
    _pocisti(nb);

    return 0;
}

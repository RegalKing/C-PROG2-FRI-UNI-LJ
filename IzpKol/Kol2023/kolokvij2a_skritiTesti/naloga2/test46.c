#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {9781, 9104, 5337, 6641, 8357, 3460, 1617, 2071, 4109, 6648, 9854, 5452, 6846, 2446, 3512, 3569, 6790, 9394, 7130, 9434, 4457, 5038, 6430, 3432, 6573, 4105, 458, 3126, 2260, 1017, 3505, 8706, 9525, 6343, 7260, 5103, 5821, 5223, 7278, 3749, 345, 5939, 3462, 8983, 2438, 333, 9001, 8592, 3013, 7320, 4584, 283, 2036, 5174, 2353, 7386, 533, 9686, 8, 2759, 3643, 5266, 9, 7871, 9275, 1086, 7447, 5226, 8156, 8355, 6320, 5921, 8876, 238, 262, 7672};
int _B[] = {3460, 8355, 3126, 9507, 238, 5821, 8394, 5103, 4109, 7810, 458, 1594, 4457, 8876, 8706, 4584, 5452, 5226, 7213, 262, 2438, 3505, 1017, 5038, 3172, 2260, 2071, 9408, 5436, 9275, 3512, 1890, 6320, 7386, 6846, 3303, 533, 1535, 7260, 37, 854, 7898, 6641, 3462, 9566, 9738, 1617, 3563, 6232, 3569, 7672, 3020};
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

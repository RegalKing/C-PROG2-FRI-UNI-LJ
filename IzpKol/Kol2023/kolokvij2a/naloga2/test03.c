
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {5, 2, 8, 3};
int _B[] = {4, 1, 7};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {8568, 9655, 9196, 2495, 6683, 6333};
int _B[] = {9970, 4442, 5153, 7443, 2478, 2173, 1696, 2495, 6825, 6030, 7126, 9479, 1363, 9932, 1653, 4191, 6837, 9903, 6050, 2871, 3573, 6477, 6683, 7111, 1933, 6635, 2932, 4304, 3665, 4521, 5951, 5317, 4649, 6520, 517, 6002, 9946, 1253, 3476, 4456, 2272, 7659, 7461, 6084, 6969, 4203, 8038, 67, 7591, 8817, 8754, 9952, 5340, 1598, 2826, 3008, 9646, 3565, 9519, 1766, 2848, 7385, 2743, 843, 1585, 5901, 70, 9041, 454, 2690, 2554, 9906, 2567, 3644, 2211};
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

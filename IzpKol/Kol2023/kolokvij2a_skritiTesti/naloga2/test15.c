#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {2031, 0, 7194, 8793, 5524, 7667, 7859};
int _B[] = {8983, 3674, 4615, 2700, 5933, 7449, 9856, 6975, 9656, 9096, 3035, 854, 3539, 1985, 5131, 3335, 6808, 7971, 2232, 4647, 6661, 5852, 8609, 6668, 7869, 6684, 3150, 5750, 7667, 1813, 314, 9977, 9508, 9835, 6189, 9523, 518, 77, 7250, 1495, 6602, 5644, 409, 9154, 5357, 2148, 6664, 1609, 1082, 3931, 7194, 9892, 9078, 9120, 370, 2139, 2465, 9013, 5746, 4652, 7942, 5465, 9158, 8097, 2116, 2807, 4070, 3871, 7572, 7643, 9612, 2806, 5524, 1834, 443, 27, 1825, 2100, 720, 2031, 2549, 661, 3024, 4137, 475, 1821, 6036, 3937, 4600, 5838, 2805, 2188, 6844, 4755, 2904, 4104, 2745, 1071, 8793, 8191, 7793, 9576, 9492, 8630, 8843, 1648, 718, 6482, 2345, 8288, 5409, 6882};
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

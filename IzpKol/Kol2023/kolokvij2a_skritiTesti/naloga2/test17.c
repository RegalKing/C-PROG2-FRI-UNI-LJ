#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {166, 1138, 4608, 3272, 7645, 8457, 3146, 8011, 4381, 360, 4092, 3698, 8512, 421, 8042, 353, 2281, 8823, 2194, 5300, 4861, 4163, 977, 1010, 8932, 4089, 6139, 9208, 5815, 1324, 3764, 2744, 6475, 4960, 6024, 3767, 12, 4172, 4432, 2260, 7585, 7031, 6381, 2998, 7266, 9364, 8739, 8782, 278, 9506, 4539, 7703, 6465, 9213, 2378, 5761, 5942, 5490, 6145, 5875, 5615, 3637, 1667, 10, 8437, 9153, 6759, 1227, 6488, 9082, 2386, 9508, 7501, 7683, 7144, 9254, 2801, 9331, 222, 7571, 5677, 2096, 2610, 9481, 2496, 2189, 1493, 915, 7687, 2630, 6739, 9940, 4102, 3667, 6457, 4889, 5277, 2108, 6791, 7423};
int _B[] = {9208, 6932, 4, 3667, 3088, 1263, 9369, 4561, 3300, 5123, 2209, 6951, 1427, 4172, 7843, 5645, 3038, 1010, 3970, 7031, 9992, 9879, 2744, 3767, 2221, 9153, 1667, 623, 7130, 5543, 3255, 7370, 2481, 3535, 4089, 1305, 3460, 2372};
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

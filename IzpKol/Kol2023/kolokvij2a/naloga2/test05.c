#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {6991, 2058, 1487, 2972, 6635, 666, 1242, 8053, 8575, 4753, 7414, 9276, 3413, 7612, 6520, 4879, 3315, 835, 7287, 1805, 9691, 9794, 5754, 8684, 38, 3560, 7539, 1475, 6556, 9433, 3744, 3363, 5616, 631, 7348, 8074, 6705, 4379, 9169, 8109, 9033, 6388, 3139, 3941, 7767, 2024, 3401, 9131, 1803, 2848, 6075, 6298, 4816, 8164, 6965, 9255, 2901, 8991, 5167, 6195, 7951, 1408, 8761, 3148, 2097, 9637, 85, 1424, 4799, 4994, 3382, 5884, 7791, 2224, 2254, 9357, 6080, 3004, 9040, 2198, 5481, 2946, 6891, 9964, 4183, 9695, 3935, 9088, 7803, 5580, 3919, 6704, 4468, 992, 4332, 5277, 8003, 673, 8076, 1866, 126, 3055, 2103, 6851, 1567, 6531, 7426, 6822, 5648, 2642, 8427, 5859, 6948, 2432, 9097, 3124, 3810, 6926, 4552, 3171, 1764, 1148, 142, 1951, 5816, 8024, 5709, 4133, 9877, 8690, 7712, 4344, 3588, 3659, 6853, 7095, 1436, 5432, 8374, 6104, 5922, 8611};
int _B[] = {1436, 4638, 9357, 5572, 5526, 5490, 6853, 2835, 1808, 4332, 8511, 1628, 3171, 2800, 7516, 8003, 6329, 85, 5541, 5575, 7767, 3977, 1408, 9088, 2024, 1017, 8074, 7880, 5917, 120, 8076, 1815, 5754, 4344, 9794, 5859, 6427, 6851, 289, 142, 38, 4813, 3492, 9410, 2946, 9637, 9695, 4928, 7053, 6076, 9566, 1951, 7612, 2628, 9949, 116, 5432, 223, 2101, 3637, 9186, 2695, 5800, 3129, 6635, 2792, 3124, 5616, 9169, 378, 4749, 3687, 5613, 8991, 3282, 4143, 736, 5163, 9155, 1308, 7539, 5890, 3401, 9531, 3254, 9725, 5542, 8028, 4725, 2224, 7305};
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

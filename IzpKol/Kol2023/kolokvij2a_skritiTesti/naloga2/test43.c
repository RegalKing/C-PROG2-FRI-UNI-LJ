#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {5145, 7605};
int _B[] = {317, 9272, 9494, 8741, 958, 7238, 6416, 5844, 5480, 9615, 7933, 897, 406, 6049, 8735, 1655, 3323, 3830, 1518, 2591, 1521, 1268, 5192, 2540, 4704, 9253, 9739, 2393, 565, 5436, 6748, 2543, 624, 3715, 1679, 5327, 6201, 7664, 4844, 365, 9932, 4448, 3386, 6277, 9091, 8426, 440, 2357, 8326, 2131, 9960, 2780, 7000, 6132, 384, 5672, 4866, 1769, 8006, 101, 1175, 2913, 2071, 7212, 6550, 2879, 2799, 4202, 5358, 7605, 4802, 3238, 1356, 8537, 2727, 4072, 1476, 9039, 9648, 458, 817, 8039, 1271, 5086, 2448, 439, 4253, 9402, 4747, 7974, 4018, 5648, 4120, 5625, 3842, 8023, 4230, 211, 8003, 9565, 9882, 6840, 593, 4838, 1749, 8401, 9847, 4550, 3725, 456, 1950, 7780, 8308, 8233, 9803, 2232, 8965, 2657, 9451, 5946, 328, 2811, 6354, 6667, 5473, 36, 1589, 813, 8818, 7904, 6353, 6617, 6478, 2866, 875, 2641, 3211, 2498, 6974, 7193, 5151, 3784, 3203, 9837, 6554, 7513, 6637, 5657, 1540, 538, 9764, 4416, 3539, 4070, 668, 1799, 1409, 4673, 9738, 1399, 6087, 1402, 1708, 6811, 5081, 9961, 2260, 2824, 2166, 8579, 5247, 237, 4309, 1102, 5566, 6408, 8360, 6575, 259, 4810, 5439, 7628, 1823, 6358, 3498, 5239, 4288, 2347, 6426, 5150, 5951, 6171, 3730, 9836, 1395, 1184, 6788, 7940, 4861, 9292, 6364, 413, 7308, 6260, 4076, 3535, 8875, 2679, 5179, 4270, 9954, 6295, 4456, 5956, 6735, 1578, 8417, 1654, 9823, 9866, 9693, 8752, 9526, 9538, 1955, 1800, 617, 4346, 8954, 5208, 2974, 9025, 1230, 7109, 8747, 6770, 6509, 2827, 3049, 7837, 7567, 1143};
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

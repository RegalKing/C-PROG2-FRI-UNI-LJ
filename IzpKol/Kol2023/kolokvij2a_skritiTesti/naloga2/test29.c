#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {6327, 3814, 3113, 115, 4563, 3359, 3062, 171, 7585, 6422, 8012, 5502, 3079, 9417, 4619, 3444, 8802, 7218, 6699, 2403, 4100, 7088, 7188, 5322, 211, 1467, 8881, 7077, 7158, 4606, 7975, 3229, 1836, 9641, 2841, 774, 3298, 6080, 1981, 9424, 5254, 2389, 6162, 274, 5192, 2730, 591};
int _B[] = {5938, 2840, 6327, 4040, 5322, 7354, 4915, 4083, 1467, 444, 6466, 1885, 4496, 5631, 2089, 6162, 2660, 1591, 3790, 5254, 6936, 6816, 8843, 3477, 6779, 9297, 8359, 1230, 2730, 9641, 9377, 9142, 8146, 4623, 2352, 7901, 1046, 1757, 9119, 4435, 3062, 8802, 961, 1349, 4193, 300, 513, 6360, 7044, 8052, 145, 9607, 5661, 4665, 6478, 5817, 4439, 4619, 7188, 674};
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {1739, 4292, 8311, 26, 1503, 8117, 3164, 1401, 4135, 88, 700, 9701, 5755, 346, 6144, 4630, 5385, 6073, 7850, 8825, 8994, 3254, 9926, 6595, 363, 8567, 2652, 2250, 424, 5946, 2825, 8997, 3220, 5725, 9475, 8133, 3690, 2191, 3117, 7310, 8012, 1288, 4935, 149, 4987, 6668, 6849, 9993, 192, 754, 1124, 2475, 4514, 8404, 42, 5493, 6895, 4851, 6506, 7120, 1509, 9188, 2584, 8411, 163, 25, 8675, 9275, 5688, 5232, 2465, 5157, 9164, 4403, 7492, 8219, 9444, 5967, 2554, 3491, 9744, 913, 590, 1282, 1772, 4583, 4618};
int _B[] = {1509, 9287, 3995, 2234, 5189, 8346, 6775, 684, 1768, 5193, 5340, 4583, 3477, 1480, 9653, 2776, 602, 2645, 3254, 6983, 88, 2033, 1086, 1665, 7968, 7990};
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

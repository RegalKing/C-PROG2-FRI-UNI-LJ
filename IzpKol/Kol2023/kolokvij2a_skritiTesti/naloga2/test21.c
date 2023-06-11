#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {64, 7835, 1659, 3893, 1645, 3105};
int _B[] = {5321, 376, 8583, 6012, 1205, 3313, 1336, 893, 6775, 1703, 3061, 5826, 978, 3950, 3865, 5487, 1030, 1896, 6805, 1535, 3397, 2798, 81, 2843, 6337, 5127, 9522, 9183, 1422, 2516, 2805, 8827, 451, 7776, 234, 7609, 3407, 9049, 9484, 9641, 6874, 4239, 456, 7799, 4801, 1167, 9115, 6501, 9087, 2492, 1555, 2243, 7288, 5195, 4778, 1561, 9433, 8046, 9573, 4828, 5139, 2866, 5692, 9477, 7643, 3663, 768, 1084, 5016, 9100, 5778, 8645, 1267, 3048, 8294, 9323, 1659, 227, 7952, 5200, 3523, 6025, 8443};
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

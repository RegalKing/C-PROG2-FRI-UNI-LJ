#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {3692, 4415, 9390, 2381, 5388, 3480, 9507, 1627, 3076, 7230, 6177, 9293, 8785, 7110, 1794, 4815, 959, 7303, 5950, 1855, 3321, 5244, 3329, 9318, 7773, 988, 9848, 9549, 3072, 7943, 6771, 8259, 4500, 5372, 492, 7491, 1348, 7115, 8343, 1367, 6851, 9344, 6962, 1971, 6788, 5939, 7517, 8679, 3866, 6179, 1710, 5087, 4418, 3818, 3456, 4347, 6354, 4637, 7866, 7760, 6586, 9537, 1174, 8476, 9912, 1643, 9595, 6463, 7777, 4686, 8813, 2387, 7600, 9596, 4761, 3510, 4683, 8187, 2002, 4231, 483, 6020, 3528, 5838, 974, 2589, 5922, 4064, 9915, 5080, 4985, 829, 2262, 3969, 4978, 7650, 4561, 4653, 9301, 5285, 1111, 258, 6680, 2718, 9175, 4302, 5522, 3323, 7487, 8468, 9340, 6377, 8404, 3031, 6283, 488, 6134, 3260, 7683, 422, 5591, 1219, 2675, 5546, 8539, 7155, 627, 4067, 4820, 3064, 7245, 614, 102, 2795, 2875, 8417, 2517, 2276, 8641, 623, 9195, 6394, 6599, 3855, 5402, 5057, 9744, 5517, 3765, 9478, 4534, 9729, 3496, 4139, 7161, 6735, 9736, 7422, 8347, 1998, 3661, 1858, 3409, 3156, 6462, 7046, 4529, 7193, 5909, 5741, 2094, 300, 4583, 1823, 8601, 3230, 2620, 7137, 2186, 5563, 5281, 2347, 2247, 9958, 4677, 23, 1760, 8722, 662, 8620, 4167, 6421, 6610, 8302, 1984, 5376, 8137, 7217, 4722, 1549, 3647, 6112, 2647, 2512, 8174, 3582, 3427, 6372, 2287, 4264, 8350, 8088, 465, 8437, 4039, 6603, 7296, 9782, 8127};
int _RAZREDI[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 1, 3, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 3, 0, 5, 1, 0, 0, 1, 4, 0, 0, 0, 3, 0, 0, 0, 6, 0, 0, 7, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 4, 0, 10, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 12, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 13, 10, 0, 0, 0, 0, 0, 0, 4, 1, 1, 14, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 16, 0};
int _ST_VOZLISC = sizeof(_RAZREDI) / sizeof(_RAZREDI[0]);
#define  _ST_RAZREDOV (sizeof(_P) / sizeof(_P[0]))
Vozlisce* _I2V[_ST_RAZREDOV];
bool _POBRISAN[_M];

Vozlisce* _ustvari() {
    Vozlisce* zacetek = NULL;
    Vozlisce* prej = NULL;
    int zadnjiRazred = -1;

    for (int i = 0; i < _ST_VOZLISC; i++) {
        Vozlisce* v = calloc(1, sizeof(Vozlisce));
        int r = _RAZREDI[i];
        if (r > zadnjiRazred) {
            zadnjiRazred = r;
            v->p = malloc(sizeof(int));
            *v->p = _P[r];
            _I2V[r] = v;
        } else {
            v->p = _I2V[r]->p;
        }
        if (i == 0) {
            zacetek = v;
        } else {
            prej->naslednje = v;
        }
        prej = v;
    }
    return zacetek;
}

void _izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        printf("%s%d", (w == v ? "" : ", "), *w->p);
        w = w->naslednje;
    }
    printf("]\n");
}

void _preveriIstovetnost(Vozlisce* v) {
    int i = 0;
    for (Vozlisce* w = v; w != NULL; w = w->naslednje) {
        printf("%d", w == _I2V[i]);
        i++;
    }
    printf("\n");
}

void _pocisti(Vozlisce* v) {
    if (v != NULL) {
        _pocisti(v->naslednje);
        int pp = *v->p;
        if (!_POBRISAN[pp]) {
            free(v->p);
            v->p = NULL;
            _POBRISAN[pp] = true;
        }
        free(v);
    }
}

int main() {
    Vozlisce* v = _ustvari();

    printf("Prej:\n");
    _izpisi(v);
    printf("\n");

    izlociDuplikate(v);

    printf("Potem:\n");
    _izpisi(v);
    printf("\n");

    printf("Istovetnost ohranjenih vozlisc:\n");
    _preveriIstovetnost(v);

    _pocisti(v);

    return 0;
}

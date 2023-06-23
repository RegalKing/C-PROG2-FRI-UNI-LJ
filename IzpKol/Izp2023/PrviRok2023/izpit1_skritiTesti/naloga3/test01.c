#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga3.h"

#define _VISINA 1
#define _SIRINA 1

#define _RANDOM_A 691
#define _RANDOM_B 929
#define _MODULO 997

Vozlisce* _MATRIKA[_VISINA][_SIRINA];

int _mojRandom(int r) {
    return (_RANDOM_A * r + _RANDOM_B) % _MODULO;
}

void _napolni() {
    int r = 781;
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _MATRIKA[i][j] = calloc(1, sizeof(Vozlisce));
            r = _mojRandom(r);
            _MATRIKA[i][j]->vsebina = r;
        }
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            if (j < _SIRINA - 1) {
                _MATRIKA[i][j]->desno = _MATRIKA[i][j + 1];
            }
            if (i < _VISINA - 1) {
                _MATRIKA[i][j]->dol = _MATRIKA[i + 1][j];
            }
        }
    }
}

void _assert(bool b) {
    static bool ze = false;
    if (!b && !ze) {
        printf("\nNapaka -- izdelava kopije!\n");
        ze = true;
    }
}

void _preveri(Vozlisce* v0, int mesto) {
    if (mesto == 0) {
        Vozlisce* v = v0;
        for (int i = 0; i < _VISINA; i++) {
            _assert(v->desno == _MATRIKA[i][0]);
            v = v->dol;
        }
    } else {
        _assert(v0 == _MATRIKA[0][0]);
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _assert(_MATRIKA[i][j]->dol == ((i == _VISINA - 1) ? (NULL) : (_MATRIKA[i + 1][j])));
            if (j != mesto - 1) {
                _assert(_MATRIKA[i][j]->desno == ((j == _SIRINA - 1) ? (NULL) : (_MATRIKA[i][j + 1])));
            }
        }
    }
}

void _izpisi(Vozlisce* v0) {
    printf("Po vrsticah:\n");
    Vozlisce* v = v0;
    int i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->desno;
        }
        printf("]\n");
        v = v->dol;
        i++;
    }

    printf("\n");
    printf("Po stolpcih:\n");
    v = v0;
    i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->dol;
        }
        printf("]\n");
        v = v->desno;
        i++;
    }
}

void _pocisti(Vozlisce* v0) {
    Vozlisce* v = v0;
    while (v != NULL) {
        Vozlisce* w = v;
        while (w != NULL) {
            Vozlisce* temp = w->desno;
            free(w);
            w = temp;
        }
        v = v->dol;
    }
}

int main() {
    _napolni();
    int mesto = 0;
    int vsebina = 471;
    Vozlisce* v = vstaviStolpec(_MATRIKA[0][0], mesto, vsebina);

    _izpisi(v);
    _preveri(v, mesto);
    _pocisti(v);

    return 0;
}

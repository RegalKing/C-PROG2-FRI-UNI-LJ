
#ifndef _NALOGA3_H
#define _NALOGA3_H

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* levo;
    struct _Vozlisce* desno;
} Vozlisce;

Vozlisce* drevo(int n, int* podatki);

#endif

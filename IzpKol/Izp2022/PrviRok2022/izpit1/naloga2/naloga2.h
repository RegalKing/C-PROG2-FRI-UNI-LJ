
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct _Vozlisce {
    int* vTabelo;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce** tabelaSeznamov(int* t, int d, int n);

#endif

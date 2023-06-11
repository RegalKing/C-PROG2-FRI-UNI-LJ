
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* zlij(Vozlisce* a, Vozlisce* b);

#endif

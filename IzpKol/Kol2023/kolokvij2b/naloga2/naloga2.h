
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct _Vozlisce Vozlisce;
struct _Vozlisce {
    int* p;
    Vozlisce* naslednje;
};

void izlociDuplikate(Vozlisce* zacetek);

#endif

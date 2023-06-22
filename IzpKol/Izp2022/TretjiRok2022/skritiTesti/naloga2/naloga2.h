
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct _Vozlisce {
    char* niz;
    struct _Vozlisce* naslednje;
} Vozlisce;

void vstaviH1(Vozlisce* zacetek);

#endif

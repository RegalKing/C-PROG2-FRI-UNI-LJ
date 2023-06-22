
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct _Vozlisce {
    struct _Vozlisce* naslednje;
} Vozlisce;

int dolzinaCikla(Vozlisce* zacetek);

#endif

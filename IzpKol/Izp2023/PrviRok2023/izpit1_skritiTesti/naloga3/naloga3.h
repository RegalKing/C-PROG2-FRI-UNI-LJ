
#ifndef _NALOGA3_H
#define _NALOGA3_H

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int vsebina;
    Vozlisce* desno;
    Vozlisce* dol;
};

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina);

#endif

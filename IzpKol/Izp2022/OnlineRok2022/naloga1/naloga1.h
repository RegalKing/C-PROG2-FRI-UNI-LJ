
#ifndef _NALOGA1_H
#define _NALOGA1_H

#define MAXFON 31

typedef struct {
    char* ime;
    char telefon[MAXFON];
} Oseba;

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb);

#endif

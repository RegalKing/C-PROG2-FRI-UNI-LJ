
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

Vozlisce* ustvariSeznam(int stElementov) {
    if (stElementov == 0) {
        return NULL;
    }
    Vozlisce* prvo = malloc(sizeof(Vozlisce));
    prvo->naslednje = NULL;

    Vozlisce* prejsnje = prvo;
    for (int i = 1;  i < stElementov;  i++) {
        Vozlisce* trenutno = malloc(sizeof(Vozlisce));
        trenutno->naslednje = NULL;
        prejsnje->naslednje = trenutno;
        prejsnje = trenutno;
    }
    return prvo;
}

Vozlisce* naprej(Vozlisce* v, int stKorakov) {
    if (stKorakov == 0) {
        return v;
    }
    return naprej(v->naslednje, stKorakov - 1);
}

void pocistiSeznamRek(Vozlisce* v) {
    if (v != NULL) {
        pocistiSeznamRek(v->naslednje);
        free(v);
    }
}

void pocistiSeznam(Vozlisce* v) {
    if (v != NULL) {
        Vozlisce* w = v->naslednje;
        v->naslednje = NULL;
        pocistiSeznamRek(w);
    }
}

int __main__() {
    Vozlisce* v = ustvariSeznam(300);
    Vozlisce* p = naprej(v, 75);
    Vozlisce* q = naprej(v, 234);
    printf("%d\n", razdalja(p, q));

    pocistiSeznam(v);
    exit(0);
    return 0;
}

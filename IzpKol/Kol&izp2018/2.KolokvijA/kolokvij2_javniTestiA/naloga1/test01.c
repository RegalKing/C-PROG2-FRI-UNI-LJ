
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

Vozlisce* ustvariSeznam(int stElementov) {
    if (stElementov == 0) {
        return NULL;
    }
    Vozlisce* prvo = malloc(sizeof(Vozlisce));
    prvo->naslednje = prvo;

    Vozlisce* prejsnje = prvo;
    for (int i = 1;  i < stElementov;  i++) {
        Vozlisce* trenutno = malloc(sizeof(Vozlisce));
        trenutno->naslednje = prvo;
        prejsnje->naslednje = trenutno;
        prejsnje = trenutno;
    }
    return prvo;
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
    Vozlisce* v = ustvariSeznam(3);
    printf("%d\n", steviloElementov(v));
    pocistiSeznam(v);

    exit(0);
    return 0;
}

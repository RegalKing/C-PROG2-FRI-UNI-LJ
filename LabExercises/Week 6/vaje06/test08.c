
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

void pozeni(char* niz, char locilo) {
    int stOdsekov = 0;
    char** odseki = razcleni(niz, locilo, &stOdsekov);
    for (int i = 0;  i < stOdsekov;  i++) {
        printf("%d: <%s>\n", i + 1, odseki[i]);
        free(odseki[i]);
    }
    free(odseki);
    printf("----------\n");
}

int main() {
    char* niz = "svoje_delo_oddajte_najkasneje_do_nedelje";

    pozeni(niz, '_');
    pozeni(niz, 'd');
    pozeni(niz, 's');
    pozeni(niz, 'e');
    pozeni(niz, 'z');

    exit(0);
    return 0;
}

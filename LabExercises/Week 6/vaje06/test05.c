
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

void pozeni(char* niz, char znak) {
    char* kopija = kopirajDoZnaka(niz, znak);
    printf("<%s>\n", kopija);
    free(kopija);
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

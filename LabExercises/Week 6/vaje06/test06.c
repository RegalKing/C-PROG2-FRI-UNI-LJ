
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

void pozeni(char* niz, char znak) {
    char* kopija = kopirajDoZnaka(niz, znak);
    printf("<%s>\n", kopija);
    free(kopija);
}

int main() {
    char* niz = "";

    pozeni(niz, ' ');
    pozeni(niz, '_');

    exit(0);
    return 0;
}

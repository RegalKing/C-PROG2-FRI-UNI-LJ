
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
}

int main() {
    char* niz = "prijazen niz z enim samim presledkom med besedami";
    pozeni(niz, ' ');

    exit(0);
    return 0;
}

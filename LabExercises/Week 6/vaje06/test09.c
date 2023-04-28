
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
    char* niz1 = "";
    char* niz2 = ";";

    pozeni(niz1, ';');
    pozeni(niz2, ';');

    exit(0);
    return 0;
}

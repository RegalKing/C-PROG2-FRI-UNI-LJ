
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZI[] = {
    "O vrbA! sreCnA, drAGA vAs dOmaCa,",
    "kjer hisa mojega stoji oceta;",
    "DE B UKA ZEJA ME IZ TVOJGA SVETA",
    "Speljala Ne Bila, Goljfiva Kaca!",
    NULL
};

int ST_NIZOV = sizeof(NIZI) / sizeof(char*) - 1;

int __main__() {
    char** t = zadnje(NIZI);
    for (int i = 0;  i < ST_NIZOV;  i++) {
        if (t[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("%ld\n", t[i] - NIZI[i]);
        }
    }
    free(t);

    exit(0);
    return 0;
}

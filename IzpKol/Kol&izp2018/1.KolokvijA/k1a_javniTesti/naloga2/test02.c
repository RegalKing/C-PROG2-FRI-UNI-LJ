
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ1 = "kjer hisa mojega stoji oceta;";
char* NIZ2 = "KJER HISA MOJEGA STOJI OCETA;";

int __main__() {
    int indeks = 0;
    int stPojavitev = steviloInKta(NIZ1, 1, &indeks);
    printf("%d\n", stPojavitev);
    stPojavitev = steviloInKta(NIZ2, 1, &indeks);
    printf("%d\n", stPojavitev);

    exit(0);
    return 0;
}

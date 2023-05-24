
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __main__() {
    int indeks = 0;

    pojavitve("a", 'a', &indeks);
    printf("\'a\': [%d]\n", indeks);

    pojavitve("a", 'b', &indeks);
    printf("\'b\': [%d]\n", indeks);

    exit(0);
    return 0;
}

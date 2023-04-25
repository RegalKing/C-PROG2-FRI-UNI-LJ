
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

#define N 1000

int globalna[N];

int main() {
    int indeks = 100;
    int* kazalec;

    indeksInKazalec(globalna, &indeks, &kazalec);
    printf("%ld\n", kazalec - globalna);

    indeksInKazalec(globalna + 200, &indeks, &kazalec);
    printf("%ld\n", kazalec - globalna);

    indeksInKazalec(globalna + 500, &indeks, &kazalec);
    printf("%ld\n", kazalec - globalna);

    indeks = -1;
    kazalec = globalna + 600;
    indeksInKazalec(globalna, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    indeksInKazalec(globalna + 200, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    indeksInKazalec(globalna + 500, &indeks, &kazalec);
    printf("%d\n", indeks);

    exit(0);
    return 0;
}

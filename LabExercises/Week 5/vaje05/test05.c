
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int main() {
    int* t = malloc(10 * sizeof(int));

    int indeks = 0;
    int* kazalec;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%ld\n", kazalec - t);

    indeks = 5;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%ld\n", kazalec - t);

    indeks = 9;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%ld\n", kazalec - t);

    free(t);

    exit(0);
    return 0;
}

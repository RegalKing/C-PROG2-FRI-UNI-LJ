
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int main() {
    int* t = malloc(10 * sizeof(int));

    int indeks = -1;
    int* kazalec = t;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    kazalec = t + 5;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    kazalec = t + 9;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    free(t);

    exit(0);
    return 0;
}

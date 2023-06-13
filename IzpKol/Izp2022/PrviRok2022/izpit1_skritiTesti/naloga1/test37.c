
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int main() {
    FILE* f = fopen("test37.dat", "r");
    int dolzina = 0;
    fscanf(f, "%d", &dolzina);
    char* niz = malloc((dolzina + 1) * sizeof(char));
    fscanf(f, "%s", niz);

    int vsota = sestEj(niz);
    printf("%d\n", vsota);

    free(niz);
    fclose(f);
    return 0;
}

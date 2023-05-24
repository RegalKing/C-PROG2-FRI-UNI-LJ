
#include "naloga2.h"

int __main__() {
    int sirina, visina, stBajtov;
    uchar* pike = preberi("b.ppm", &sirina, &visina, &stBajtov);

    printf("%d\n", stBajtov);
    for (int i = 0;  i < visina;  i++) {
        for (int j = 0;  j < sirina;  j++) {
            printf("%4d", sivina(pike, sirina, visina, i, j));
        }
        printf("\n");
    }

    exit(0);
    return 0;
}

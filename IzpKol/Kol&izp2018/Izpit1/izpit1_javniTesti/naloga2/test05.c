
#include "naloga2.h"

int __main__() {
    int sirina, visina, stBajtov;
    uchar* pike = preberi("b.ppm", &sirina, &visina, &stBajtov);

    printf("%d\n", stBajtov);
    for (int i = 0;  i < stBajtov;  i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", pike[i]);
    }

    exit(0);
    return 0;
}

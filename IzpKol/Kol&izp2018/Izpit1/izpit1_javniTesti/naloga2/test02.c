
#include "naloga2.h"

int __main__() {
    int sirina, visina, stBajtov;
    preberi("b.ppm", &sirina, &visina, &stBajtov);
    printf("%d %d\n", sirina, visina);

    exit(0);
    return 0;
}

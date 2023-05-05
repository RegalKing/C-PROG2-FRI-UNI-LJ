
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "IEkjvR1iW06r7vt32B9O26FBLgchj7vQUiSOm",
    "FHGQZTGUIXiFuj1rMOFnWXsLsQtV1apgZAxzC",
    "mbbbk3ln4VdnjPLWpn6NoAEGvTUesqp4_fajb",
    "oygCL2syu1VDmDDS6_ssgrKmPqU_f0WW1a6w3",
    "TQIF6zN8KsfOPUOzhMIJgaqve1nCEg0jW1gYq",
};

int main() {
    int stIzhodnih = 0;
    char** izhodni = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%d: \"%s\"\n", i, izhodni[i]);
        free(izhodni[i]);
    }
    free(izhodni);
    return 0;
}

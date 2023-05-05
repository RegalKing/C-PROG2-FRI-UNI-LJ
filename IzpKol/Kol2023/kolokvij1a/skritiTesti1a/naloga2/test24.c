
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "eFk",
    "Cvp",
    "xpi",
    "Nac",
    "8mV",
    "ACF",
    "Vbr",
    "NRm",
    "fJ9",
    "iPd",
    "im0",
    "Zbn",
    "OC3",
    "MyX",
    "myZ",
    "eiu",
    "ALo",
    "UMj",
    "X_U",
    "8Cj",
    "R6Z",
    "KHj",
    "a5r",
    "Hkn",
    "tK5",
    "hGe",
    "YMi",
    "kEF",
    "D7A",
    "Qtf",
    "D_d",
    "69z",
    "z3T",
    "WhF",
    "p_m",
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

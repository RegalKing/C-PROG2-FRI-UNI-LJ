
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "j",
    "oATnLWVbESLjPaE1DiWmk",
    "McWT",
    "aTp1eo_I3YnK",
    "hcm9KrEPqOcw2ZgTJxCinFS",
    "PPu3E6qV",
    "BOLRYHWvY3ELs9LGOK",
    "8Mybppln70WtKJPepVI",
    "ELD2kU4K4ZlE4YNLyguLAl1",
    "EIJ",
    "338pL2TkF4b",
    "FEGcseanOXMz",
    "eS1X",
    "cC4O8bpaaX",
    "mdIVE",
    "Bd8RcedN",
    "HCZkXYENntxdLg5H0R",
    "j",
    "zRSSIIK_Ci141mVd20p",
    "hDgmVv",
    "bAXu",
    "Eh0l",
    "MOukTCTrsiFGuKcUoGY0",
    "SJzkJyNxZG5K0ojjQRhlVOeLe",
    "HPdSloEXpRLyX4yDa",
    "lIe543",
    "s1",
    "InbZtWiziYvj5Uew68a",
    "dHVTuvQeG_ss0UpE_37zf",
    "ekM_f",
    "S",
    "tqoJqordI4FjkdWUnOtQY",
    "RJprObHsFbMvI6NMrQd77or",
    "aVdO6Y",
    "3uFjq",
    "AWD8D",
    "wO7ZC06Fsgp_",
    "N4Btb7VEmrDDyGls",
    "3G_NQX",
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

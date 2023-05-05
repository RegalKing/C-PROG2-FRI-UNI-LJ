
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "Eb7m",
    "aeZQ",
    "ob9B",
    "fwhR",
    "qhfG",
    "x_c2",
    "vdsl",
    "M7gx",
    "OGzh",
    "Ojpe",
    "BjVw",
    "evJN",
    "z9cI",
    "C0VF",
    "dYnU",
    "nbJs",
    "Z1z4",
    "hfdJ",
    "i3aL",
    "whYX",
    "Pz7J",
    "SVa3",
    "TPK3",
    "jxDd",
    "Vt0U",
    "Ss2D",
    "O3SG",
    "UMSD",
    "Nvp7",
    "dTez",
    "HOVT",
    "59ia",
    "NEJB",
    "l73N",
    "X9aQ",
    "isU7",
    "a78x",
    "BvMD",
    "WFQE",
    "C0pv",
    "2LrQ",
    "_Gtt",
    "8JUN",
    "h6Su",
    "a69A",
    "sw6y",
    "avyp",
    "ZpXG",
    "baem",
    "aj9j",
    "KNyT",
    "v1El",
    "GAFx",
    "LmOx",
    "u6FD",
    "ORec",
    "kF4h",
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

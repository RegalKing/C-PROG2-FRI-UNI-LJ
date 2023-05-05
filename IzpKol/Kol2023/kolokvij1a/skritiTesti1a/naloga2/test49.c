
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "ws",
    "y7y4rdshMbdf",
    "qKGskqaz4YXHB",
    "ueTXx",
    "wJ",
    "V1Ix3CR7_lNj",
    "Z",
    "ldFa7Z",
    "m",
    "BvP",
    "BjKYjPj",
    "3tBAIqpI8jLi5",
    "dIxz",
    "swtrG50B",
    "TWy28TKgeVGA",
    "TcDMKhywe",
    "l36Vz",
    "2KXaRVOOLFQ",
    "sK",
    "K8",
    "Z",
    "hBkNCwXjV0",
    "TkQ0BCsBCB",
    "6eJJe5ZQg",
    "TKogcbTLDFEBo",
    "5N2DtjO",
    "I",
    "MI",
    "_GKQuHq",
    "ALL",
    "4vT7AdylQzht",
    "c",
    "Q2",
    "dWVmS6TC7qkLK",
    "nX2",
    "lnm_",
    "xcY53DBUvo",
    "LkLqwqI9pAHAL",
    "jNE",
    "8RMchb_OKij",
    "Su",
    "SkrvLr",
    "wK1TcAFaSPNeQ",
    "AKMjx3X",
    "r_Z2aYiS7e",
    "VNrRUnab",
    "LC1k_GZFcBKEF",
    "Ukw9",
    "7R",
    "SEyMXl",
    "HIY",
    "si6QgNbxGkgk",
    "U8xz8arOOi",
    "N",
    "0",
    "nea6PGzONy",
    "vPKGf",
    "gaW",
    "QSt8Afu0gCJX",
    "RV9h",
    "oqbn7U",
    "d",
    "W",
    "5nQepSHnZR",
    "FAP",
    "BDr",
    "fu",
    "OfM2qHZnQld5Z",
    "xy5oSrFhZDNIg",
    "xXOUzAVry51p",
    "VACT",
    "1fik4EJ",
    "gT",
    "oEGgT9I",
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

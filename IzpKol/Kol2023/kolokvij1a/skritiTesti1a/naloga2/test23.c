
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "T1v8",
    "mrEr",
    "uwEV",
    "EHUW",
    "vyIM",
    "RGmh",
    "8ElB",
    "Xzls",
    "9kSJ",
    "Yp5d",
    "CFIE",
    "0avw",
    "2ZMN",
    "GcUQ",
    "XXrk",
    "ueeP",
    "WTzG",
    "hPqB",
    "v6Fz",
    "Y2Ay",
    "dCK7",
    "dtM3",
    "JNeD",
    "o9Y8",
    "oVJj",
    "YJkq",
    "lAZk",
    "Ajyo",
    "wGax",
    "D1i6",
    "a0WQ",
    "VVG_",
    "bA1E",
    "tN4Y",
    "1xoV",
    "TC8c",
    "Jrz9",
    "I78D",
    "fFpz",
    "kZUe",
    "IGaV",
    "JiIx",
    "vX3A",
    "GMQS",
    "Zvsl",
    "u22p",
    "kslR",
    "Wq73",
    "TExi",
    "5BIy",
    "IbiY",
    "iMEw",
    "etZd",
    "LFiS",
    "mD1j",
    "TFqb",
    "OCXW",
    "vFgt",
    "P_To",
    "rMUF",
    "ZGih",
    "kcPv",
    "gSQn",
    "sBZW",
    "NRp5",
    "smOE",
    "WtCo",
    "3AOr",
    "v00L",
    "3tbc",
    "QqGO",
    "23ec",
    "k1wS",
    "O2L6",
    "aZR1",
    "6749",
    "c1Fl",
    "zSKm",
    "_7SN",
    "8eKH",
    "nQ6J",
    "LG3A",
    "LGgi",
    "nMqO",
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

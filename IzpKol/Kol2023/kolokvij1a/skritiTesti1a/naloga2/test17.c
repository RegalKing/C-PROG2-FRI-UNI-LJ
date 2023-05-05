
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "sHi",
    "5Zk",
    "Hd4",
    "hm5",
    "kLQ",
    "HAX",
    "NjR",
    "YqF",
    "iD3",
    "zEg",
    "jBQ",
    "10a",
    "df9",
    "ueT",
    "e8l",
    "vJk",
    "zDR",
    "_tD",
    "xzO",
    "tXj",
    "9Tu",
    "odW",
    "gKF",
    "x4N",
    "zqd",
    "IbQ",
    "eZh",
    "gMm",
    "ccq",
    "Vcj",
    "Q2B",
    "uFO",
    "LSQ",
    "ci4",
    "xBV",
    "sDA",
    "KNp",
    "_jr",
    "a74",
    "bZj",
    "IwK",
    "cgo",
    "PPk",
    "BE3",
    "TXn",
    "JmC",
    "zd_",
    "L1t",
    "4if",
    "QJj",
    "7rk",
    "Brf",
    "Gjm",
    "VWZ",
    "CzH",
    "YmM",
    "QBw",
    "gt1",
    "nw4",
    "XOA",
    "hRM",
    "Tw3",
    "HOV",
    "v03",
    "lki",
    "o6T",
    "wjI",
    "2pH",
    "W1i",
    "Ep7",
    "iDf",
    "kfg",
    "eaK",
    "I1U",
    "XYK",
    "I1i",
    "La0",
    "s6Z",
    "hhx",
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

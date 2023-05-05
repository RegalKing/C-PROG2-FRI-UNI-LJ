
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "V6C",
    "8Jg_ocbH26N",
    "ZCaeZn",
    "Ka2tvUDEi",
    "y0h",
    "W5xh8bF7SW",
    "bwlpxpjXML",
    "GkT8IiINgsI",
    "5QBXd",
    "9rQP",
    "tSf",
    "z4",
    "ptznb8",
    "E",
    "egB1zO",
    "a",
    "Uolu08UCu",
    "sni4Dor",
    "JTFMujfzuhP",
    "G85",
    "alPXoVuwp",
    "1",
    "1G",
    "dKXFF98Ln17",
    "O",
    "T7Gee",
    "j8Oky",
    "5SMn",
    "h",
    "lJDNl",
    "qRVYt8pNq7",
    "eJLHFep",
    "W",
    "A",
    "7Aj7p7",
    "iNuBdLz",
    "zoZ",
    "T43",
    "fCQK",
    "QmzcYPs",
    "fMbFc",
    "Dzbg6b4G",
    "M9",
    "iU7SLKX3x",
    "uB9RUyj",
    "UBvq",
    "NHd",
    "JixAesJjw",
    "yj",
    "zvDITaqEd",
    "2_t2L",
    "a3pT",
    "fGlE",
    "A",
    "YFutS",
    "3eCyH",
    "Omh",
    "2Zn_P39pQ",
    "O",
    "C",
    "MXXA",
    "S_",
    "OJ0nVn",
    "GVL55HB19E",
    "w2o",
    "xHxdtp",
    "Odif",
    "1Cg_E",
    "FBglBK",
    "qw2e8rNiyY",
    "rzxpV4y",
    "0n1WdyK",
    "NO11MbI",
    "6tGw2NV",
    "Hhatg69",
    "CW7WZrh",
    "z",
    "n4rSVgV0",
    "V1pvikyTD5",
    "nZm9o",
    "kb",
    "agvfJ",
    "mzP3suyhd93",
    "2",
    "zXGl",
    "RYbJb",
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

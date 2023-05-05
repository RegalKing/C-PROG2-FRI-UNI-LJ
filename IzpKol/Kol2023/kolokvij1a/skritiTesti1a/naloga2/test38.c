
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "nzO67iS",
    "X",
    "KEFTxXzD6pJiZeqqnb",
    "RTOl0188l23DILVyt",
    "FE",
    "pmKVzrERuFVRAwlR",
    "sMgbPha2C9LJbPnAu",
    "e8MIjeB",
    "ka",
    "IRFhZro",
    "ElHI2n2QqYvOdCs",
    "rS2M6lyg4mXrjymyi",
    "ykTNoYla0LnNhBkRmc",
    "u6w48sYEDgHCo",
    "rn",
    "zJO",
    "Ld",
    "ETgQL22XS9BE2ALUBpw",
    "sgCGJ_w9vO",
    "WAhe",
    "jo",
    "DlgJdQ",
    "sFUureE1DkZ",
    "0qPl",
    "mgd2YyFT2U5zO",
    "sCYsrqd24ej55u2e",
    "0jXnGLdmxKepH",
    "yquiPkjLI",
    "vqYOrrRyxNS6z9b",
    "XcSPGhfYMS",
    "MvezKfVZMy1c9tFME",
    "Lvp",
    "5InLWPxBEC",
    "QxSddIPbZcXlveF4",
    "dl2k3RhxWMho4F5s6j4",
    "1TeZLqVC",
    "76l3nv",
    "zfEw",
    "5IF9Ofhc",
    "hbbk",
    "nkcU45ffElN1zV",
    "APOZyGheViehK4H40",
    "OBJ_5hzjEO7dr",
    "tZ4nVlwfESXppfR7",
    "gcv",
    "U7gQG141_GhmG8Yi",
    "p",
    "OtU8mnKT",
    "ZpWpZ95PyijH",
    "zQ5",
    "H4_rfZJdcSDlJQ4bsOD",
    "S7Ftu_dkr",
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

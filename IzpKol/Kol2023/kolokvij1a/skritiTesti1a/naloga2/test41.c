
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "2_hA",
    "VIwfaz7CgaMS9f",
    "6XJQ30lEd1nS",
    "uzf9JA4ziuReF",
    "D09doqP41k",
    "q",
    "P9LNThXzqCoJ1C",
    "oyxuaPtbxQI_iq",
    "bQUj",
    "3oJ_uoO",
    "fIheIH",
    "IdT74CeX5rx5l",
    "GrjfBSyKF",
    "TsGWrA7kP8",
    "brXmFYaTN",
    "8WKLVdC4n",
    "eIwjji",
    "ANg2NbyTDwDq",
    "cDpYl",
    "fm",
    "fjRj",
    "soXi4NRAhIm",
    "48q",
    "ExZebfFqU",
    "h9gA7Mfb",
    "nv",
    "Ie",
    "tz",
    "Ow_aZ0onoN",
    "dVzQKJTuTk4H",
    "BcR",
    "9maLyfZWav8VNZ",
    "DH6oU5CS",
    "gyNcYUKc4ylsec",
    "BaQk",
    "TKwdb9441S",
    "jIWyY9QxorzFV",
    "5",
    "6V0_aYwc74",
    "4lwf0bbWgB",
    "dNPXRbP0v1r52",
    "bT_D",
    "u",
    "JgY",
    "seG",
    "Er",
    "Qre3u",
    "yR4985r1ebXf",
    "EuuYSnFiam",
    "VlE3gbys2",
    "_p4",
    "qcqFMtBYPinXQ",
    "QDrCwYr",
    "Hx5_",
    "gH6jjLWSg3",
    "w7wgvZdFSIxH4",
    "bA0uaA",
    "9A",
    "VUaa",
    "zq",
    "uC8ULLErr",
    "nHdm5rEwf0PVI",
    "Nz",
    "dqt",
    "SIF3s",
    "kb",
    "G84xdKrrd7tfWT",
    "9YTpgE",
    "4L6asW3",
    "kUziiY0a",
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

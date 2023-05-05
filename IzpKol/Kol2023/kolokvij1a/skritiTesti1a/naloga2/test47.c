
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "f_7Q3zoe4G0rwPxt62Sw",
    "4bUo0T6QXhMIQXK511SYX1s",
    "mRQfninBG",
    "ME_NrzyRJBQrJS7gwobAMaz",
    "FToIY7YgFp4gDs97T",
    "YFY__uQIWwgt",
    "nq5",
    "j5sqQOmGDFdXSTF0",
    "ygP",
    "Jf",
    "tuPcFG",
    "wbgndNC0mgrQV8tCGBolqHM9",
    "Zf__jXHSAL",
    "dWd3gdip0IM",
    "CgPaEusZ0gQzEaH9B8V4poe",
    "vMLDqw32",
    "D",
    "1CEaD",
    "NqFA1y6C3g7nP",
    "zmGrEDrSkWwfZn4FaUIU",
    "7_",
    "HLk9KoljNzzOV86m19IItcZWT",
    "53WejnFGUExGkFcH0aBT9wgGX",
    "p5MJpA2vqZbo",
    "zDZRXeFH0u90OVkUhG1X",
    "GOIGFERRpFFEV",
    "_vhbXgqFwr1yEimey6l1",
    "chjwoXechmIf5WTpyuHhQEuu",
    "jxXBynFLAm3kD",
    "YdAYAnhDJyUeERR4Yxw",
    "AccBm",
    "LkFVghMq",
    "BF3xd0mMi",
    "unV42GJZ",
    "GcIMgYNwI8volzn_TrA",
    "9zHuN7",
    "ECggtD9ZGAwTm_",
    "WxaX",
    "LR83AEYjuxlgV0w9lp3",
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

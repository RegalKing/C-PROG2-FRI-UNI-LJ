
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "IoxAXmBBCsWC6Ex1F2zT",
    "tatRpXClCi7IwFO",
    "We5XIenuNV8NJQV",
    "r",
    "RRYZKMXZ0ZzXni6vZzFeVCwUS5fMV",
    "9",
    "7edn1t2klCJbTtuN0ydDT7nMOnJv1Ke1",
    "Egt6OLIX9x",
    "KTwXkTO",
    "bv7FsDfCJjvHh",
    "N9IFwFBKgU",
    "1h87i1KJi2s4T6sfBQG85EZU0W38",
    "inFpHeHCYZdjXxjpHh5ZIckiiv",
    "pGGBzu4CRfHsCLM5pj81VbuFVP16jL",
    "pjuxeUqiB6c83NsP1QDRx6tSxd7Cg6pxoh89al",
    "CFhew7g16t",
    "KrX3TmkK2lKJ3rYllzxM9KN",
    "U8DZw40Yemt4_Jl",
    "_F9",
    "4L76gAD4oZhNfdda0CkaKy8879S",
    "ZmEL",
    "ZIVRac1MoL_V6Iv2wCt",
    "7H7wz4Rf3kcYrEyR7EtEe2K4aenEjIBI",
    "2UZVsUCXktNX3BWSLDjwg1keLrAeq9eOh",
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

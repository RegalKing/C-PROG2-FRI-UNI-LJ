
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "JNxKaRZ7uSKE",
    "0ji7XYVx3xTr",
    "i67EToC3eaU1",
    "k7xmoqtEgWxW",
    "SAVKwuyvi8gE",
    "2Kc9zv36Z_RH",
    "on6OMx7e9y9f",
    "KU918F9nTzBU",
    "7uXeCGdQL9jR",
    "LUG3rddV0Rvj",
    "zovu38QFZDlh",
    "xDqN9wgyET7e",
    "sOP3_ztOPVYw",
    "MQCr0Nh9Idpx",
    "K5qnV38hbuwG",
    "a5Gr94FiaRXh",
    "rPj6h4qVsYe6",
    "FcsjvF_IouSm",
    "Mf5dPXnUOwHu",
    "w84o0nmqU2Np",
    "5JaMOfOSWuF1",
    "ybVWj3M08jFS",
    "yH7_kfWNnIjw",
    "QsiNeIXuYmLg",
    "JTNw4iBt9kRM",
    "i4EDaWpFad7W",
    "OaqYgUSY21Bk",
    "s7N3LRAPM_kb",
    "mA1_GVWGBuoJ",
    "O8IN6TQilde1",
    "h8K3AelUO6T4",
    "qW38pR1OlQFL",
    "u3JWmrRzjPoG",
    "JKifWkpPdUnq",
    "YCvfXcQhpQ0O",
    "pqv8I7v34wnf",
    "PUO_8TokFuLa",
    "sKjIZT1UPnmr",
    "AtDVkf70wLkV",
    "mIe9_0oRgs7E",
    "EjqDG2TgYIzw",
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

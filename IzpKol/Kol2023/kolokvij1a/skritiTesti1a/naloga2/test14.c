
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "P9tAZzuVNs22BDtlJE_9xTbYzgpMiN_2okeXisaoZSVWCLfcVJkYBrfhpq07puIbE4ZmBqpmtEsUDek3UK89l_c8ZZ5uetrGV736BB2G4vRQgneliYdhIqIgFMWoQH5UhIB5BBCVeWq9Zmu4bW5TA0YERyY5w8XPuVzedxMS_ec9LQinR1lrLRId5f85shtf91vo4wmmtdzvvhdmHD_hkdihpAhgapm0_fL7RZ8vZ9Nb6JfwS5hlWDNA1V5Trm2XGc9tURRCxbj3YUnSt2dzr8d0wK9bfMgnUzOUzYJ55AgimtDTwzDKluAba3nfKEzAYXb437BtRZwYFMMOXCO3CJuX6k8F5h8AtJCc4HwxKo7dIDPgpgFvMcZ5y5V7Hft2Eq8RVh0d5Y4FBt8rzbhAVF_OnMm7MbJOnhoV1_BpXt1X0JuB9U95uHByLXjMOv1C3blfXHAIaecBHvFTl6QnQw571k4HMwnw0YOinWxjpwVRvhkVVI6YEKs0wD7V5pirZ6OV48oTs8mRaKEK78HIQHw2s7TR8Q5yVCnV1rCmHvNGirmZZTc7XtAHrPe4J65s7CFNe064Li_ZBF7dxVZ1NDtWszCBGNkK_ND4Jaryq0z3KTmM5wayY",
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

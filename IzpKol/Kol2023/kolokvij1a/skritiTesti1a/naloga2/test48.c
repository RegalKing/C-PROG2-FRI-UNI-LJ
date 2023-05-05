
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "f3U3k",
    "RRkatTNDKSULvyn1jKuv6J60Kq0UL",
    "CggzgnVwyMo58gPycUVA9mNvOf",
    "lrUCKGjQf05QurhzA6_qNowBAm0",
    "puKKulhhMJ8N381byKb9J",
    "IcgtrQ1nMeEae",
    "3YZWlrQQ_Hd_tqOCEFA",
    "A",
    "bjJGGFJnXYRZSUn",
    "ggM",
    "8xS5",
    "IGgVHKuwRXq3o6UGrGMu4VmOohE",
    "kU5vzTiURnMsHPGD",
    "WnuoUDC_VAa4P",
    "_VEvS_wNavzmO_HWTUAgkPAc0u",
    "2K",
    "mMpi3rP7HlO",
    "ELJyJcQeNFEYrdBD6A3cBGt4e6",
    "W4LbDjxZGchuhSyt6f70eRe5oOa0",
    "rMu_",
    "g6Z15OsfwGhKbJNf4yT",
    "b92yfhsng8aNvjrh",
    "A64QVV_Cqxr9xEJqXGLKoHRWE6LyP",
    "7dh6jcaEZJ",
    "WWW2tkfLK",
    "EFBq98x0Cn",
    "rcm8RMHtUaE_zl2S2d9whhQZ",
    "PJnhQ4sTIp1CTQS",
    "pKMAAW",
    "mbgfsCEr5fti",
    "1hEN",
    "q4aM0F8eolVb4BcDZtFvaqXsBL",
    "x_RhFkQoC_5tsA1Cnbksv58hEw",
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

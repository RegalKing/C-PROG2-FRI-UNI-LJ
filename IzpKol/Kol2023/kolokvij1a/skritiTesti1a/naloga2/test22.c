
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "0KDARVumgRjkQz8iJbph6JsBIyR_c3H5wDpQcfmEKm7wAWTWCsj8WLfLBShjlR4bgUNowNHvnyB_MW6sLjyn73SYPg3SpJiuLd51nFPAgamQtE2_L_AXmpYWtYjfF14ykV4sXenXQtzNwl1aBDV_NXKFi_GWHozS03hveP9jHmmOf",
    "VKwUf4ARbZUifNm_Y1vpdsA3DtRfQlXXRAGPAHwnLjGJi_QhKoWikCVKdRwj8JImkfo76lRS4Rn8zvzqjKoxxPYVLLFIysxVuhBSHw6MaWTfbHsyHkBSRxGu8DxELRTHHP3IJ1YwfwigQACB3LAFTK3V0pNJbrAlJwKfyg9HC9rsM",
    "JYiXNGIzj0d4HkK2zCovHkRWF5rlzdfeM5BK_GuPeQ41crF1yJ2qtb1FBbgs4ZL847QlZNEcQqVqHvWvFYU58e2BdubTYhWZZ6EXBDJg6H2jjBBos6Ov2LptxKBHxakdq2gFXZpmu3gDlR5FjGDNM2AAdHS_chG1dhEx_UXlfERUE",
    "Jtz4aOiANfoun4I8pGrGN_jrKPVjPEpCskZ_HGZwyF9OB8lGFIKmiibED40HovHe_dsjHLLbgf0Dve6uCbyVqA3DThzgcd1AqdnTFJT6dQRMXIvx3L94XkARf8JjBt6bHArvL3mwGgznY6SqIgcTGSvJrvMWRnXz1ZuX7NO67xzX8",
    "kX38vza9tQ_QTonIfDSsElvu9PIcGhYXQHAjsP_LUM8RMjYk6lrTx0AbuQEuNLEN06elMh4pa7BWCGuGZkcksbVUPbmoQ3jnWUNaNnA4hSg4ScUJHorH1lrnDRTO7gwQ4q_eUWNUntAJSAq4IHZjY5KYcnpgvQBGAg83stTq38Rvz",
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

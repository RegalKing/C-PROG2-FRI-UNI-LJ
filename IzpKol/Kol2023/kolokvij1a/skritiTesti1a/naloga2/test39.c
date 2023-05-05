
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "y8vJ4AC4ak",
    "eSPnKtr1381",
    "1pEqYX_lZFaS9tZr4",
    "uSXolL_HVH",
    "k9_nrc",
    "AFljE0dyFk18f2U",
    "GIBliYOX3OfBNRUu27",
    "8S8WW7Rb6P0Ogpv6JyFK",
    "pzXurPnb_ZBDkM",
    "XWBoBQGUv",
    "wXqMMaT0u7y2ZslN",
    "7BouC",
    "NrS8",
    "tAQatso5A",
    "Sc",
    "sqmHWVxwUjCWSszfcP",
    "zc2jQyXtHcB",
    "DfEp97I",
    "Y3TyGO",
    "7zMBfVn5c8KPf",
    "kYpw6ANFXEH3Juj",
    "FM3GDZH7C6BzbbXCLGe",
    "9yR9aS_uAuh",
    "VLdrikqU",
    "ZPVEInmWf",
    "8S",
    "SDJJOP3emtVc7r3",
    "PaDQN6x8",
    "DXiO5KZR5edeCShbJkF",
    "2Oc3W6kaFCx9W",
    "Pyn3",
    "Xv4yhF_z_7B0NONv",
    "1",
    "Wg_uYh4PgHJZhVLE",
    "H2mB3k",
    "a0LdvmvNjl0",
    "ZdJknL_2o61e",
    "rQBCD2knuroHNJWEruK",
    "UrcDYjRBN12Vg1E",
    "d6",
    "ReDbkJi8vyfn2UD4",
    "cUes4By7Kz_Eda6Q8cz",
    "pLhHpPrlrqSEg_q0gr",
    "1gugmb6p3Zg6rF43i3Tz",
    "zZY",
    "ro3AjI_XM",
    "AfnRojef0uybwJW",
    "FTpCNSPdZ7VoReep0qJ",
    "5u42afAxVQP_mV7m1U_o",
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

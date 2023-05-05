
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "40rXtv8_fJazvA",
    "JDckY9lgOMD",
    "d",
    "FeJo79",
    "yqJ6YVZrUsnys",
    "Lb3GmBA6PIsT6",
    "fMK4KJJQG0",
    "1Frcl5MB3giuIao4vSRREo",
    "eZ0cIa4ksmH5FL4FKP11KL",
    "rSp",
    "6Qa6wpb3Txkbtffsl",
    "EeT5Cxzpj",
    "xY0KZe3O_t1TysQet_v",
    "yrDCRUhqgxcOb0",
    "6AmAgic",
    "oD9",
    "Z",
    "ZC",
    "sAUjmL3eV97baAMCGxSGmU",
    "W2UX_",
    "NnyBcThKk",
    "nIF52",
    "h81Zy",
    "9Tgx0x5TGV7VYX8Yvz",
    "oGOBCmzKIjCrMPzoXz",
    "agieiF66BmNq8OxFD55y0wWxe6",
    "LYFp8imxyTnZST6p",
    "RlnN7ZxbIbujq3fjIBK98ar2Djm",
    "9m",
    "2AFFpiuYqAIKr8XF",
    "QzfX4mRBnC92BPZH5C0Rt",
    "I2AHf8",
    "vBr5SNzRREhUZFGv",
    "QJCRqm",
    "d8Cpovl",
    "Ck",
    "olg1UHtGFu14NS",
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

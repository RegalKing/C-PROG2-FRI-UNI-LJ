
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "Yo3",
    "7M13UM5lGUI",
    "Sku5jImEYCK",
    "OqnFtAa2PFYJvUW9t",
    "D125epM",
    "uwhrfK_uf7bD8yDeH4",
    "hA",
    "yAoRnh",
    "7WHsk0xFpAkAw659L",
    "iJiVOmYOHNKfWNS",
    "EEvADDWqpWFk8KhQ",
    "vJMHt",
    "9R1To8mcK9Wf_Asp4h",
    "G_8",
    "oVNArr9jCIMv2DxL",
    "FdwrKNWsjR8wO",
    "20",
    "GHyYy",
    "7qbh65Y8wBn2zVLV3",
    "0csb7gldN3JF",
    "czdXeFmP",
    "G7SOyPQ21OQdvCA",
    "2UxVf",
    "WjZgs3uSqAq5",
    "_FRRGBB8bvxQnM",
    "tdlhE",
    "gJPUvmqde",
    "hYUBYift",
    "xoxCg81krazGJ",
    "62",
    "LWHiZRuYW",
    "oIaOhEyhZIH9Mqsq",
    "HtOiwDnrJyH",
    "ddyzstfPx5tLrYrO0",
    "hHhQxff0miPBiA",
    "1qt",
    "8XeEqS",
    "qDEE_oEVCC8nIzDc",
    "FWHTr",
    "rvBc1782o",
    "zgfVkwOs7m8",
    "3l",
    "tzFtQYulSueiRmN",
    "tWCRTtvvAjyGZ",
    "m",
    "aL4wgT6nMgV",
    "8TZUlJbWUNkmedX",
    "FdQAVhj",
    "xdRNmbSfPN",
    "6rl6cjlVequDnO4FR",
    "nOqD",
    "5",
    "ShedFoW7",
    "x1kq7C0D4Br8Z",
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

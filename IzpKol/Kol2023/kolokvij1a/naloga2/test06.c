
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "dndDlW_W_",
    "wWnnYOFz8",
    "N4u6nlYxC",
    "gfdgCTJfl",
    "Tb16IhYSM",
    "9RJiBsVaf",
    "XHjb6_wIs",
    "HOIt15yci",
    "FeXJZu56J",
    "EqzjiJq6J",
    "aFVFE9w7Z",
    "UgoXT7lx2",
    "uXTWGAFoE",
    "rWRl05Uz0",
    "BPv5FUBef",
    "suGPnzyV9",
    "NYVGK4d3O",
    "3WvMpFxaq",
    "lcZz0A7ll",
    "SUsJsrUaY",
    "wHoeOgnd9",
    "HhOGiRc_1",
    "lVJ388uwW",
    "aLYmTjPgU",
    "0eTfVICLi",
    "h70wC6TGz",
    "XiFAaZF5Y",
    "L5I7xvwb4",
    "MghzPxuyB",
    "9s4ZoHq6w",
    "FhLz3sTVY",
    "q6Mf5TgBk",
    "HUhkW8lWW",
    "Ij2f7htIn",
    "js7pKupGO",
    "JJ0ZOaF4V",
    "ELD3pgl6n",
    "QC33II3N4",
    "D3m3lg6cU",
    "ZDCEFJm2l",
    "8pkdodwrZ",
    "wC6WBXAe5",
    "sUgkjL4Ni",
    "QVOov8Y_m",
    "CABf5pEs5",
    "4h6mcyxJX",
    "N7oyLfEMH",
    "0r1WWEE9C",
    "HmO7AKrmK",
    "yX7Ejrp0Y",
    "iYeHG2c3m",
    "2qmodIGdN",
    "KbVREPU4y",
    "9yS8QRf0N",
    "2osJPdQDb",
    "EoruvDiUZ",
    "jih73TzEa",
    "vqgv_OEWy",
    "q53oH64ow",
    "SvFmljjp6",
    "WsVeDQb6d",
    "6JrXuPLmE",
    "VQ10z1yel",
    "DZU65c5M5",
    "LXj0EtEFn",
    "XuxMamS9V",
    "yPNdRwjzT",
    "uTo5Y5jIw",
    "fExsO26m7",
    "dbzFgMTfk",
    "0LzA9vwaZ",
    "Gv4LlwGi_",
    "BCtAdDnze",
    "yBfaWZOqK",
    "1UmnslqHR",
    "xG1yPGkcU",
    "wMmTmynQb",
    "jkSl_m7vP",
    "59dFSO44w",
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

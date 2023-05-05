
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "zAX6p3smFvz8Qj1wILHtvbX7GPtIiMH34Xnh7EgX",
    "o3Yrbu_0ZU0UnKoj39iWWAVB2BBe17LJzaNegS_M",
    "xSuMM6LBjj2rmbYKikw83LC3FDvZGzQkGtbeDT4g",
    "PnQnZBy2gZfSSmPNJ8hV6z97acc8_cF82zCuqqjA",
    "mXR3MbnVnlG4ze0bj9L3vlSNZNFXOjFgqpr9fztp",
    "ZdaK9pk0aG9fEcwlRAurXUTiZ2BWat69r0U3sVCj",
    "6esCto2O9bCI7Xjjsqww7mf0UuZJyB2g2pZqEFoa",
    "HdB1ycrofo2agWBVG_TeqvLxU4EnCGI9g5kCwMmh",
    "xJ5CK70XkDfV4aU_67eVZVHaPG2STqmHiOk0aLOu",
    "kEa4FqyjJ8niOLzno9vZm71v2KCgPZ2fGcvrJ55d",
    "a_s7qwxlNHupnbDb1_a28ZD1zOFs8hGMxOFC7r0j",
    "nU2vEHWa4QNhYuKgEkhTpItTk1uGMQL_5sr30Wva",
    "Sao3gARNVGFcEx9WxjpNxWltsMieKZ4EWvgi8xhu",
    "VQKhbWV4xnu9TlmpruNZZCY6t4vroajU7BLTtZCx",
    "CDNKNDUd_1Ne2YDdLfQlmjz9BLd4wxQ2G8ioBEBP",
    "eHn8vO_Q9MPh30_VlTBmpXFIqlVjwiH8Wn964dVS",
    "W6h_VUuZQUYp6KVIO1RDirCLwk2khXBiOGdN56eY",
    "3pUsJeMEMvEkS9DK65RtA39xRLXq68VWCD2Cfiei",
    "ylgKUvVhlRyQ3R104n9KOJTzGr7XNOR5ZWc1BPN3",
    "PD5gw43x32zUXCpF69LWgFFjuehXYrSa7SAy4d7e",
    "YV15DXM6fISTEy_IV7GWmaPcGtFou9n2YJAiroEx",
    "YRWgdz3_wxt0BsvP5RPXyXpfP3fabvsbnbYujjaP",
    "Q0CcVgEAHq3nVPRxMwuaMjLmJHUU3pb_pWWre5AZ",
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

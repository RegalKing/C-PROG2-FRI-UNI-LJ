
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "Lfaik4i3NzLBF7nEULo5Jif90lItXDXQjBGWOs7fbVno6igVUS8AzDcN8maGZWniAYXN4IUoANQnjDcyOmcYiYJEtYyEXKyKa4cMBhmLCdZ4Gw3QnI_9zeG1MXjns8KHWPYdIFdj4UC3bcTxizRQq48SKpbL21bbyReij7cAFtNTwUtRSdyfFvAZZ9KVCxC5dGuh7ZXY7c2gfz_rU3m5Yr_3nWivmycUwwOnJENyeF5MKlpA6Ido6tdj86RLgnX1Gb10Gsw_iiZ5ZuUlmXfRvkNEdNoYFDD2jUJVhB9j6edKyJTdZo5qMqQPsE0SfxNGMEoS5c9Bo9T8RL4YSLox6JqrCSBjqO77YTNROgGU3gGXMkGlt3wq8ESO6BvQ4ZuGvybScWeqWMfaVTOTMEY3si7bN7fRWGM5vMHpomLWdHD3xbioU6QhSivefAMOfeJc_1BlPKBhyNcPSybw6fMxtGTeD8eSCqxT9dbdXtKtgWQWszWdyiJYTqlODVIy3eDhlP66uvtL_",
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

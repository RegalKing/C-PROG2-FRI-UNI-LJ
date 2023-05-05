
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "7bBNN_XXl9KvRTJNLCotr74pNl2G61dzj17rEQH2dOcopnbYQ6IrDt4qeeVeWblkzc8Mc8SHpRVZa59cnR4vdPdQ3t1VuZqanonRwDi_2rXr1hQ29q2CbMhhro4AbmrdyDfDLLuPPsGjaCJny6I4p0FFqYakTbh0KyjDPhhrvJmVgB8tgabh5YRlAjWX5QqxfMvgPk9iEiNiMK2uxMmvvHymAd6O4fz3m7X2TbifBEXnDH73uKq1BnKpEgxh6AGLE7vFu8uf6XvQx4gxTEBUcEMEYkKf_O29_nkfeF4anEF8sXr96O9DWwl6_vyC8kuTwPhNT5yqnZBeoisjqDLZfjf0Z1tFfEUXx2F58hHbXFJTDUFhwsTHeIevSRKOxlyv_PwVwU1OAaH8PGOnmXsSH7K8aIA0JziktNbo6Sz9Pz5PfGFzIGYToX6DwiWK6N50YPglH8v7Pcf6shuSA_D2SOfiCQrA6FRseJZqECb2",
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

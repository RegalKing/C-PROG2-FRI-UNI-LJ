
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "LlN93ob3dALgOl10MhsUUzpkLXp69lpkiDyAUzSMeXKbamuF4_XZeOMbL2NFCTrTXZ8IsxuXDfx648jwvCpg0m3RAQ9hO6koI9eRpBZT4VfWZ9ISA1XlGRA8wNFQZURlvI3Bz5fyxsywoDx60mStV_R8fazkLAeWRYOxhHINQTTlA7aXec8H8Sng1Vj2DSVBJ1WzSxkNJ8yRWmjqSlZCVi5jWRQra0KcGTretnBNqihYT3Cnj8Pf1RxlwOdrgZXTwe08anzfixU3R0Yz2ZKFsJY83mbcsaUsSDgdBxtwoRPXf0f1ENIn7PRdhP47K_J83fbaoSFdMyPL3w8nz_nXzZxgO15pb_cO99_PmOXalkXAjnoSrrkILC9ubnOZhd6FjOWB2MDfvSm2L_jQAXpiH1Bk1AGEWc21WMgVJzPmmmYsrwvp8bGnssrZxZheOY79M81afI_v2eJG6ZR3jLGQilAwbhYbsMQM2rbz8NhiZY9TjM8_HwUNgJIOx32OiNrPjxmJcaWubb7wrGhPp1m_9JdYRXsrEoy3YF7g0rdni9UTBtA1wG7pOOKSBzs_Bwg0d5OlVjPw8DPjVjo2lfFBvXc7B4DlbMfnn3zWyXU1QQFSamtanYhFuN2yedORdmUetF8a62UfMbEFjnaNiV1FzFwLgKdYBtdukV9E4UJmmovEiUb9zXudEMHWxMU5fGWFeLYMqulcZCJMlM3srPrnuGOdGHkcEXajM_HF0Zx9c0mhMdtTB4g9TZd8PPOUyTc3NlsrVU6wcKVpVGeupBkj9oJJwh0G2qjFqxWT1bPSZYMs_Z0a7aQYEj7QMutJWI7qSjP_cIqulbhf5vKGWfImcfBJankJX2RuwcXPhfNpAi5gDuJqGHITJceLOMCXc3UciDaP_PaZFdZ6eWLMD6UazDC4cuJJX4vBrFomvVg5BORUVm66WUDJ48sMaKLdz1KphZC8ZtVgq2BgR848vL6MMqWE",
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

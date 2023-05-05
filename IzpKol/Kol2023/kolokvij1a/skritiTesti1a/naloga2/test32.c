
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "KdpQpYc9X",
    "C3BZYF4EWvEWfQ6YciH",
    "jV2xliqRQTyR",
    "gQ3RIaEP6JBK6d",
    "Q9IBamk3cPTFh_QDCW",
    "GJ1Kl",
    "ykzi14Ah2iCb",
    "wGfJ7qMoeN5o",
    "N25",
    "trC5J",
    "p3d2Vtx",
    "_YGgWhbkCtu9Mbp2E",
    "lP",
    "hzJFr9yhl1gf_C",
    "EVLKiw1nVbf",
    "P2Nr4wpswDMxM",
    "d88_I",
    "x0",
    "MZsBQqDy1PQuSTNNN",
    "cKlIWYV00N",
    "a7",
    "jIUaANev6Y5p",
    "VbUydjTtOzKWNT",
    "aMC",
    "qkygL2RNkkCo",
    "foy",
    "jwCj0etCLIXJhXmqxY",
    "JeumVJbDCc",
    "xfR3fdfM",
    "I",
    "R9PM7YNkyQq",
    "Qgn",
    "Q",
    "xOZnsPAK",
    "SUvqbQ6KRT",
    "FAxeFBuq9k8mIAbaos",
    "ybmb0Pi1eCt1xHKI",
    "vwSbUp5",
    "BK8PA3yO43d9k",
    "SHtgtA",
    "fRvPVWadzLWb",
    "kWrvdX86gg_v5xla5",
    "h1JE",
    "bTrm6BGxE7bcRmJLn",
    "i2",
    "lR3Pg6CxYgr",
    "PAI6KTuHhnFz3",
    "d9z6pTbUI2wlXdG",
    "kb4PpYNHSddFH",
    "9kkax32NnGuYTMCwdb",
    "jSs38rBW6RMQ",
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

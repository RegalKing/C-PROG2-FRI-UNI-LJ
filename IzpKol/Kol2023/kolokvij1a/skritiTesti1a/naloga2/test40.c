
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "0qgmcu0bxJgeISSEjn9LQ4Vjor70THCLET",
    "SCkbGhD2F4Nl1Hr9ZBPRyRtdXPxtPg3as8Fuz_iZdv",
    "iglH6TBMFZRJz1qg",
    "HAmZpSLqjr_qOs6XICWQpG9jH",
    "1",
    "7oNCXtGwR",
    "TdybOzU2qARAKT9q6JV6EtceIDkxvBV",
    "6dtLqxarRgwXpNiBTyhZY8uhGIbvT3qhhB3",
    "6DGEpahif",
    "3_0XlGuF_Q9VBkiQ236TGNs5mzRKkNXyMJNs2F3O1Pf91f",
    "tGVhrJl7gi80cULc_eUgITmZi8vkDKS5bTQOau70V52",
    "UWSMBRvuUWjU8vdBv3jwzDeTwqIkm5QlI",
    "dtWkiHy6n_5m_fPV1JXvDz28cZ9MwteHQedSqHASWDvB5",
    "gXzln_3P9GPG_t8B148iPNPoMWM1t6e1rTbtaqUzFkxRT_tDqK7h7Z5",
    "IK1y7nVLgl0ADz_4vmNQcLcl38m9bqKGAGrms_w1U4szkAb",
    "1sCH99szqseRrtS01Eu",
    "yLlf6Uwb9cEJ6ZBNMMALOoIi2WaBEbGGkWAZzR6BjKjkGecigUcl",
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

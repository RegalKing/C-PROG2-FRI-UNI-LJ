
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "RVFG90pXF9a3PS",
    "Zj4sSmfLN",
    "HBYxcLTpl",
    "LiRmrD",
    "pIQ95l",
    "8rJjZ5rd_Hx3WdO",
    "n_oJvZmJUKrf2HwaO",
    "iNM6ff7E",
    "N4mDs1Xe",
    "9",
    "qwwvz7v8Sbve8RsDm",
    "1qE",
    "0",
    "bMTCFvsy6gakeu0FR",
    "D",
    "xaVsvRqGkqI3_F3",
    "duEzb3N4Q5e",
    "DlkkIXKzX3XEh4",
    "HgYX7JCqWerS75ZT",
    "85Y4dhg4MnOCaS_",
    "_",
    "m",
    "0",
    "ClXdQ",
    "OCjWs3",
    "gWyWjzKp0YxtIE",
    "xaJGHyc1RtOliLy",
    "NTKKCApwUt",
    "YfzSqUitLmEP_",
    "hIzMg_ck",
    "rzUdmEWXdqabs8b6o",
    "2x49gNjL0RtScJiu",
    "hZfVs9GqzkOylz",
    "8XNIL",
    "Ekft2KREmD_",
    "VwlL",
    "P",
    "SmLiYBxb0AEZyA",
    "HeAIPSv8oE",
    "9nMVcI",
    "SOT8DU",
    "I",
    "kP",
    "n3ZbelWgQ2Pj",
    "oqx",
    "Nh_AhW",
    "tMS1LGtx0Sk5qWzN",
    "4OI_PyoNH",
    "p1",
    "Vo",
    "mgJFUZMtI4y",
    "M91NoK3fdBtI",
    "vGnN5C",
    "M",
    "mq6",
    "56rgzrAlo",
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


#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "e1_rJ7Kob",
    "dW2J7",
    "fmv",
    "Gv1",
    "AdYHrQe",
    "7BS0rVm",
    "fm2BTMW11",
    "bF_",
    "dhRdInbx",
    "n",
    "cpPv2yWqEL",
    "RegVei6",
    "nC6zlc",
    "8TPh4v",
    "jiTUh",
    "5yGJd9Oqg",
    "ZAAmO3PRtMwA",
    "6zrTyy8z3yZM",
    "SQtxdjm",
    "E_2H",
    "nm5yJ3D",
    "HxC56p",
    "_PqPkHTN",
    "_opzeIy6",
    "o_nzETtKHhT",
    "GUVWNaNv08_",
    "hLVeD8m6",
    "dAoFJ",
    "vJN",
    "TF",
    "oM2PD6yXZt",
    "uyeG1",
    "dZcvC",
    "x",
    "jnNXIOMQoAS",
    "c",
    "3MBwDExHDb",
    "Y3",
    "2Uc8rHiB8",
    "w2Sq2qTG",
    "WlTd9q1H",
    "PiAEcwnmw",
    "IoLg6Ah",
    "dotE",
    "gnk",
    "_",
    "pd8GaUat",
    "jMD",
    "vk0nBz3nnf",
    "PJOpzP",
    "yMGXiKnbV",
    "2rko3",
    "wK8_uAN9sD",
    "2LRu",
    "gc",
    "V5S3cIY2nJFe",
    "0a8t_VG",
    "5uwT",
    "xf9Tsi1",
    "t",
    "kOqd",
    "myIHD7YOI",
    "TPUghfG",
    "0U",
    "KJmWvGVxGMfK",
    "cnRW",
    "toH1",
    "dKArDg",
    "7W",
    "vgFO",
    "lbapHt0",
    "rEI",
    "AeeA",
    "2_",
    "1x2GaE",
    "TUGr2yl",
    "36MK34",
    "BXEfAMUFW",
    "ILiSSfaFyPP",
    "zvOLZgruVvs8",
    "08LaqQycSu",
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

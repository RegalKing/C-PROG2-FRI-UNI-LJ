
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "O2mkdCBWPg5L0gudzeq35GgEbUz",
    "ecObbbN3Jlllc9qtH36s8dmo8f6",
    "5EhkFCZ5qjK1gVmGcZR_N39MVj_",
    "Pj4ljYJp8w1ZcP2CcdeYlkb7AIs",
    "mGSyNGVYyxQb1MlkiPkL5txEVXB",
    "RJcv1ryUmQK92SyrvOLMPoOvOzX",
    "WBVBQ68x0aYMgnz6PWUuL5kMEIl",
    "lc2ZHBmU4rStSbdnl0hQKrYEX86",
    "lssaBb_Dzi6tay1a88FGKRQ4KLU",
    "2p7exJrBIpZsoknL9516VqhUO43",
    "SMJ4IzGtJrLCdaNU4ZR3xXuD2yQ",
    "dJ7Nro_v8FPIU_zRUgmFBN47h9h",
    "PvlUbkC7fMty9SnXh5vCBQkZlDI",
    "qu481eb5czOnc3gGCJiKjEXlaxe",
    "8_kKt1CSqUPIZbRHI3VE9GBPexv",
    "UsiJlxvzVbdsKh9YWLCNDj5_tkb",
    "DVx53OnuNivm_B4L6VqyajlGS4D",
    "aQGEpB2NJVronP2QLnt6bPTtrDj",
    "I5Pjx3qxQVse9uZ482E7JI0a3co",
    "bOR58cn6O2JCP5f38cno1DdNBOa",
    "TB0OTY4l8Dmof_rLAFLNhLs6FZA",
    "Y4dL3C31ms_RIzllzoMG1TsWhVz",
    "3OrTzoCkGq7VOwBi_kPyGk1A0oy",
    "rUdeGcRNKO9MW065DMWS95SAHGU",
    "MZqA2cNCGxPKJfsaKnbmm7abijC",
    "AzKxID6PPgx6B3y29omF9IJjbMJ",
    "GXLt4Fz0ev0buHC3l8Sr5_csKs8",
    "FOBmnK1yifkOUtgzkDb7W2xHVS4",
    "mCM61VNLeflwgDb58I8XWdaTFfP",
    "Pn_s_HyfMdZwCXXbEspxMxqRa9a",
    "Mwf0ez7BPAqE_hbhTHc4QHLpZMF",
    "DlPhSDrvr06i5MD49953z7Ymt6H",
    "5tQcarupdXEEC7QBbxjTLJ804Gg",
    "zfAXoolvoI5nZOuxPHW43rVdNJU",
    "w0oNucwjlRmTKX_VetLzRt5tQuZ",
    "V7rt6E59CkgCCnDXqyjPYmVvPcD",
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

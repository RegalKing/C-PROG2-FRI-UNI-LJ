
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "D6GsH0dPdXKGTbOsAZIy8QUO_wT",
    "iTLBi1mfXbaeARborgU7XRkk6hA",
    "DXxJ4J3REjVtTGJrLmxZIgV2CEz",
    "QFXbZmeG1hz9Jlff2RYXzpiHzJZ",
    "K2paTFMqCkcj74iZsWdgmhMISUR",
    "4hJN8JczBSm1bHO5UZpQFhc6daj",
    "XbkyT_uIueYZX5GW_LuRouO0rcH",
    "wnnSw8Z4mdnRu0ZBE_zPdYK9wK5",
    "k9fZi0aRUIx0cn6nfndOu1N6ZAy",
    "1FlSIuO8px2n3XcoBG8cDfvs6bu",
    "nStkNY4fVWljyqRfV5vquD_hagi",
    "8VqDotinLb_ptmkRMyrd4ESZCxM",
    "ICLufu4zo43Sax3W4gGTLoN3puw",
    "2sNey4ycWTIKhbf3AWFNCB03gxG",
    "XYJVQbqw_DggTllJTYrSxVZFczX",
    "sUp3yHpRFm5uEY3bNf1TiONikWG",
    "fdTL_7NXHFsoO9Ow5NrGDrWOtRw",
    "hhqyyiKUIsPFDdMSx6lb0Bvqa21",
    "DBza_shZEMp7XL0K8gzSmAW3ji_",
    "FmtXuW0eQlZKlBoDma9OLctrDZm",
    "aWhl8KPPTsGOvd76izkkWsWRtOf",
    "Na1LNWndTCPw1NFCj52mPJ8eg7W",
    "D1rCi_H6w63qZqeD6NcEqcSzCpZ",
    "xqOQYJvr06kwjQGSEjCGuVDVW0X",
    "DFaUTnETTBNp00m4mom24SCyO1B",
    "8T_9FIuWcW9XnaCgIP_AFDjUkqG",
    "ZT_LgvnnHHqKoV8wObuVVYyceeQ",
    "DArCYZUEmj_lZgpT3h9dQCI8fmt",
    "_KIRuueDNNpgOlc03sg7bk6N8Yd",
    "wMll07N7bHSgCe3IrrsyUkOjZMP",
    "o9d2QNTARqhBo9i4HHKerKq8dN7",
    "8ifJwzdgMK3KTCBNOWkzA7YQEDp",
    "AwzKKUVLLZAvK7JTZ6T8nycptng",
    "K9UIWY2AjNbPVTCDfV3gLYF9yix",
    "7QoP0XvaneQHYMA7jLrmHPgV2eX",
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

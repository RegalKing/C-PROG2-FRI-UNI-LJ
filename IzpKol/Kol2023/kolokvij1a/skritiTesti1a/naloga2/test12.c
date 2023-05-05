
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "CsAZOa4zuX1F_hTnQExHQmQqoXm_WGkbO1hI8tacDcEWbH1LpSjKxhFwQNDJ0H_obxAuZ7XKFYKd2bsOjwYnPtcRUZ5wTkTGB4Uh8TFsEb7KzbTGHE_BDJSbi6GEuWWvE5VHlmyx62GIBuWNUkROCK6yaHGnWsZkVYo7BbPF23KcBnk65jum4Px373N6KWtsckd",
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

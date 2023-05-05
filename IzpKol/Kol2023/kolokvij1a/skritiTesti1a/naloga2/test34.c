
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "XjYh3HjQ9tbVC",
    "R",
    "jT3BtB8TjBBW36vvtGHiWXCI0eb",
    "zNOuXC5wxdiVXSM",
    "xq3QNZrPtI",
    "qD4ecXIl6lBH1eRts0UOtDRbF",
    "TO_aN6lqBKQNbV8ueAQz",
    "JAFfHPtDsOD",
    "9P2QELjYEv",
    "uuC7NySP4ahEuX7vGfmzVRBByHaOADOF",
    "69i12",
    "uxPqbHw8wzvyTTnfHQZfsyU",
    "lvWMOSl2s0suHT6noRVdJ436qMCO",
    "eNFEQ5T49mUgsGj0soc0Q",
    "TKZ7PlI2mjigWZ2mtYFO5vYcEvTsUgO_",
    "4tkV4K56oH0v",
    "B7YrDtP_",
    "c7yYk",
    "lWmmj",
    "UW6F6CLdp",
    "NUdhQ0w7A",
    "6UJoHczIxtw5t9q",
    "8n30AZ9JVIOPrpMbpVsiRqCHMsD4g",
    "uytiVXg7AtKTW0r",
    "XyffWkKLJ3Eo0jyNQvGCn4aFgItVT",
    "rV",
    "mh0AV0hp3Jkw",
    "SbDYGjmZFjBLpE",
    "rihBqz1SuiN",
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

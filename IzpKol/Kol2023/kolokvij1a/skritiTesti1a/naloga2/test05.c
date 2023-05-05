
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "VW_ZOPrtGFYTX1jg5iDkBuiF4D3VRwCNX5STheHUJkbJOI0kPZE8N99D5fuABkVXW1vt1v1_lbOK2rE1GdXhaT7V2K1xCvcdoXvEYNBwQZViAkROmTnufbV_mAaUAz5NjTzJgpNMSNvggzcBeEqindcW527YO9NM6oWQ4ysJuyrYVxpiCcEd4ZmLrsJ07Ro5kv3QeE1TYkLcsMfOCfxyuq9DX6ZarVPIl6yTNg3Ru6Aus9Oe43F0z9m8XDjPSL0qdcSFgAonNTCW89ir_pC9JrK6L4OjGZyUckoPVfGkvQaWIsxwoUZHaE1r0HJwkZSHhKgF48KwlFQEgvEpEC1ecxgadTsQ3ipM1PyZnuolg4yoA3nvHQUtTI_FGvZ12Q5OuA0_iRxtfA3c2q_TusxXl9qXlHpg1ubdo9rxBFD4dEWWUgjHTW5JXXiwu0RLkf5MRU1tiF1wetqKOg4htd2EVoEGh8bdHhg_nX0Qc9JWGgDH5Xklcyd94T2oI4i_mYH1qKYTOVinyEo6XNME8YPiBPsJTAdo5oFfiykcsy7EBGAbcAX4NyZ4tTvhKqT4bMgbHRAG7ik11zK78_UK7VTu7c63",
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

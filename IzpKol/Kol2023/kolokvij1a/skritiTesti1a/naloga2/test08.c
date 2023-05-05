
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "i05uob_A0ILYfZslz787NQeR0aWE2WtjFoI4VUUgGur0lvA3wjhfDJFLXrK1n1U20j7magiQIgupbhJWy6QcSSScWrRY5TGOEDG9acNAjZ738ECyLAich1pvb7T212QV5sxvSSCBfpa7LHyZlqvTdKLkCAmWMVFjelKMplHDnLIqqtwpaaSbhi3O_gZF4iVjnxSpxzdTcisiu1Lih4ZdoGsLHxhoZTD6gMY8CUzecft1LrWV62oW4msM5VuZ9tDuREmhTrN8LCFRT6HSI9f0vaFJCzZ4KTO6cM0nq6eTtI8aq59eRG785IM22WEfyr2UYlemxCsnfaX4fAUtCknYnnWdUATQ3YRLDT0me17iLWaAFignflB5p4CdfHUSMzpnVSNT5pMGkL_dbBplaKPkYT8p0w9aBz6K3ZHrwzSYf7pSz6frDKg445A73B8yQ6i2_HiN4Wcz2L9UY0BmchKE9RWXAO49s6aYMBT0pIjNgQcrMST2yJ54JTnR6qmaoEhwsZWznraQsOeUS_nDLXvFqxUbwEXyN1RWPnkBDu7PDIyCf3AVVzCEDA4oYMXSzUXXlDVREYOJra4ceEc8o7TB14Tax0WKEJJKg9BnpE4AqXmiUTwwZyZtFS3vCeRL7XNCqHBsj_E9Iom25fyBWUQlGglkEL1UxlgmbXKFGqfk3GP6vQ7X4pVZyono9gne8ywZteSddg5TwwujMPYv8bSRw3tqgs1CF85qLuL25jssOsTXjFb3UIX4I5DsZXDAVtGKfT0nRZ8zb1yDBcQF2vreoIXiFnIAeVJqZFHlWZTSHcHCwXAm6SNmiv9dZogQ0O2Qpal",
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

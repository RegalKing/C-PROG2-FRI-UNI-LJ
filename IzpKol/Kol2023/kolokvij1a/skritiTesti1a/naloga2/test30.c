
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "27lU3dlq7L66",
    "pp0WN1oz8tiu",
    "AcQBG6MvXKjM",
    "j7O_dTL3AbaV",
    "EGWTGz4a48Du",
    "AsSmmP6fYom3",
    "zg7fPjgwxxYx",
    "gymbvJKgFLDO",
    "HA7Ni9IO19xW",
    "1enSlpQkl0Z9",
    "wXE3Ehq5_bO0",
    "mdJg9koYCiNP",
    "YL2_udQqGbzr",
    "ZyM4XijOQ7GM",
    "4Y0wkFLKEICS",
    "s9ppNnpCBy75",
    "3chRzPwsl4RZ",
    "gqUbxd93Jmvg",
    "VriQTRNZENnp",
    "lvOht5QGkBuw",
    "puYFlDHbqgVB",
    "LdHA1264_62u",
    "xKHzeBzrCyzH",
    "EnbvXjTA8Bx1",
    "gCRWg0T0hSpE",
    "Dy4HKZq8JaiX",
    "LQuI1KDkTPdi",
    "A7cZfKrlvkiO",
    "xP_GJxcdYvV0",
    "jwG2GU_c2vxS",
    "IGUPX050C5F4",
    "pC9xkMMbRHJA",
    "HIpTsEfQh5UN",
    "K4UfLRO2xJGQ",
    "HuPKT6HzHKHH",
    "8d6v5sBUjJds",
    "nZ7J0QxN1b8b",
    "QG0xj153jTMW",
    "ftwWPLbbRjbw",
    "5_m5GPuk2fxD",
    "RbaMmVwU6Qdc",
    "TpwWuE0ATRHX",
    "HjQ3xMLOfWRn",
    "YxlC3J1JBPd4",
    "LKY_g879kDS9",
    "dqP0TFdyZQqV",
    "w5PNbrjk0S9m",
    "nO_3SiAIh_mp",
    "z1KLY6cEy0wb",
    "xrTGe9HnAm5c",
    "08CHFXQvZsZk",
    "S8jYQfEqzu4d",
    "8PgnxT7gM5Hr",
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

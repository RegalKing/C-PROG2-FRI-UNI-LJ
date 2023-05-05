
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "DVbwiltJoTUyZAVa4lNSx1dYGzmKPKH2YI35gXE7qco2jbIWbzaBfP3bTzux_XC0gkrNiM6OuGfgYBHk1F0e3I0zjPGvnQjfDVw_37W0BChor1i2DtCbJD07zDNQvAGQHWJH7MKsPUsbwMWZh6Bpqty5xg5mitCbP_kZkPFNseM2s3PkcgNC9ymwaxaWNE0P3J1snM4lEAz8UjsNu5KKWkE6b2uoBWyAkQpJZo9zNhPUH32gUFsK2LD9nyyVBQiKd0ysN87DFcGMthcxExmW70Y0WbUO5mr7Ndc4H7ygejD_9hX3bY2TJcwlKF6K0H9b00S9razRK5uSTP1RpNDW4Ce6h5Xoi6DuMljBL9_PExyA04c8Kwv6TJXU31CF5IuZmLkU11lqVAEWSKorgfeiQ_cKWGdstD9z_4y6DtvrLcyTnynlBceb0yGn10IsmLSlZDtewuKcPIANsY0oIp5No7I2OJp5bmyQMHv7gYqQ590oYYikWMqatwxOBkAvvNQxQ8mlqYwF_J_uA282uXmf6XBh8UA3TDaK7FSlmEm0gNq8aCdMS5L8OFYctWe_OBtdPuTfm9WpQNyDLfXQymwWpTm440AzXG77K994Se0n_rkZhoqZS5i6Rimot3Z0tBOIXUm2fU6OxP8flz5BbOa6moYK_aAmHgncZ37P6FJxlgJglxtjrSJ9NgATRmDHDLaFQjCnqRfA5U5PUIGVUIb7VEKbmzLlCW74GSURC1Z2iEB4v6Yns_0O5E8LMXbI5gAeIWCA20slUC8Jpp6lByrlEUZVY3r20uvZOlGs6SYkPhkPC1w4Bu_IopKhvaY94WXj0VLBbvRquSChLgt6xaeT3kyT5KjHjoiUYD6mlZpF64ie1h8SzoXaaFaYOKldllCDyrwEuY9kAtMjWOk3siIvKvyE2gpQ8P6beFpz3PgFhbmYRXab2cfHN2pXLeGsxDBPOrbKOsF473vQ5F8KRD6oP0H8wkk47Rxi1mPX894L",
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

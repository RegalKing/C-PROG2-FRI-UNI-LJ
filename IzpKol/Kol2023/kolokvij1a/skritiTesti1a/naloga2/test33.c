
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "N4wWb6GkHlSls7F6_xnF4pc5zq6O6S3Q_zCF2paIpVEze6A5HRMiN9eMCD6_4lSWN1OkdU4JWNLuY__dh75Asq4c16ot504Ph6DVBE_AyrCaKEK",
    "VZoGh0RAgrUjaQlNGepn88OIVidgDus5YYurBQxi6DLrUUpwf8RY7k4fg099SuZoSFqKfyOzeQg5NHgy9BUHN4W",
    "ZWGFgIEvbouUWOH91SClXNoM49mkYYF5hwC1OZ4qQdsEikIf8qGQ7VDEDUvSyTONVqicuHCWcZQ",
    "M6CBrN3I_UlPTK1mV9qi6aC83X_VLQHN3wZtX6hgLTdmGC0Cchb7bE6n4_nvVaj58Ig29SI13Apf3xXOi3b3VkrtCfraU7iJq",
    "bZ38N",
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

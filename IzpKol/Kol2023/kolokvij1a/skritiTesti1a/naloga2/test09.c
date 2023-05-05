
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "Mb88zwxhW6RQopVRqrfB6XkCQtQf2Skj04Veh2VV6JGbNUdofARPwv6tsnedAfrDS5jhHf7SbLQL7Mi4bUp9Br8cJV1DFOMqS3MC70jzh10bSp7OCumpNTOoGMSATWIqPaJ4tYVTk7SK7dFVTGavSFLhl6GUFGzL71Kp6D8CHddgtNQXC7qP5f3o6OyiEPpCmDUK59eVNnUriN7kVNrRJMH5FFvv8Gq1CnAyfRnIJ7nMteHvxTiP52rpcA5Pni2NiHX52wTdH8kZ7by7NzjVn0YFZUq0OkOx5IVsI7COHyHFLBUInZvO",
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

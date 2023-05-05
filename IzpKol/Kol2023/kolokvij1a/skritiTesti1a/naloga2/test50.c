
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "E0GqTS2_GpPovw_o6t1K8oiGX_CWfgwr6tefDvIUTcHShsZSNwbXnyz8abrH73zBJzfJWFuFH0KXykplSPlqD6HnzgXur8t52WrPlE_aiyLbAJ7oreL_6QqjppqJcWDg1vQzX9jFHgWIXdL7qxzvjnS3X95GuUkCW9dOlZbJUbafG31KuKQjSTcMEaq5tj9glULXIKEUzvsoO1mZClp3s5LczXkURy5kUo_pPqMnrmHhPetU25YGjtHQrcxdh6fJvacjUvMwuI_oFz7sVapgNrpyBXQRDbMQdLPUonO3cGAyD6tEDjr85fBtypZhcAzzETOWV1j3bK38n9ZTcrvWxVbmPN7SevPFXch1gNKwc9QbzIKwRfugoS6TsYPoUXNlr68F",
    "lKTeDVsAhnGPn_Od3lB8uhassYL_Gq7pf53JUWNoIeDKFlR4lK7VrASYbFWmlNyVbJMF4id5GCtO6lBZoA186t4DLxCwY_HxVUWwa6qqbdwB8PzRTMm1IOyhcv1NJXpOKCt86Js1PvBKuKim9SHRPL38xArrnZnKJOl4evoRaBzPGYLXomeVcshnn71qDRANom6jQvC282QqybrqPwFxkQTga25zTqKGJzjDCPZD8hL46MzhfTvsoUX8stUvrKvSgMMWLfuWKofgbx",
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

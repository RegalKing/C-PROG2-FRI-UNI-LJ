
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "1HSP1SxXslXjYDIyQxzQkfjEdeqHGpe2eAmBsasTjL2mt4sw_nNivoj7uOuDOp2qJh1mMrUKq7PgB5r8N0W2d4J9WvTU1xczwFZfasxh2IvFcB7WvQF1T9g12P89tLOEYdYeH9B5eLKJWogcAEg2PdVW6bSH_8PbEypD1T521dCDN4k2bqKbNbvkIMTFKKMNtfRLwbQKLkQ03E59JhdnxqZzpLtsscbuPw8td1IeI1Bo9ssG8UQ8hJG1jw5dZKSiBBSp6J2hesaRYIRANmiANCkG69pT8xyf6tYfzMjsfZjsDobvL6zktNYmDmcfiRCNJwvIHbbXlMK8iBa2QkdkTr302IZjpuKXGYOeQc69ShwFst3WmIO4wSV8FaJrg1Cst9noVp6BicBnUhtHnT7KgbpVkeWcmLVz_ODsrGQZGBqnMk45xJ9g_dmGFok8WuOdO_k2Zlg_tOeU1CwPb0QNylWgcqa6YtjPzyEXqR8bvWsYLUdnakAtkDs1xXuZrjwEtualYZ97CI1FnJD4BHxIF4LlLT4dknzHhO8HktG4si6bzPPBRoukY5c20bwPT0663tv1uXg1cXZPtS_9BkmKrQAeiq53Wos4IrRPZ9ojtNGM6H7OiAUS5RAft6JHWMREfrL7r6MU_HG6QraFWjPOt9kR9rtKX2rOSSAnQdMGtDmuZHEiu9uzW9rZ54rCBHRc5kfP38r_BxJIipGz4Has6A5euzehYXXLptSEoTRU_CnX477NL2FWawroieZNkZxQtK2NSLA1RDqq7jlN34ja5lMdZ6CUrcYI9517iskZ1HYM3wRFXr0QLUUvxSMYznUN",
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

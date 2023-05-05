
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "EqC3zdavGc3E0LVRpM3H6AdhCBMHyG9v0JqoQrRxT0vAxEd5fYc_yeZx6gxXkvKoUoUvA56DzDQe_dRrttLZ7i3k7Yn5ijBERITn2KtRwiM_ARXV3GXYyBB19VifLewe_PQ2w0r9r5OVuPXe_XwCgBnYMwzsiZEUHK68ARA_jthx9mCTOeR71RROm4kkuxQ8I5sjvingCo3_iNPJwflNqFrurmETKnnuBqBKYwv6i7rnKWXbMD1QMwERrCmvWmfaUXnVr2euNTXhGzGCV2dUIvUNfJ8LCXU7El0q8FEOSOn2loJOsK59pKAAnQGbC9Dai7K8t6MGouBO9QlVF98WOXOrhJEMifpnk8RX9lkiVi2uNIGppA4Lu5vB6OGd2jIMsiOyrNu1tLQlSIRAUk9hGMYNE8Vxi62mZdXqypz6o6dYPVmLaTj1FK779QPYTR861JmKxz4YC7NeepLF8iOszphHwGQZrzItWHNe_wVVC6KSf5Qmk1QmpoOiuaZUCb8rVESsuKOVVysMnxp5KmlKZUInPiAllu3iaXWCOkevoRY2CKZ2W9sAFJi1MnytQoSPJTPYFhiBbyUMdnuGL5ppM9csXxtC5fJ59qTFoJfyl80pl8wc73oC5Oj7FWOFy1gmJYo4_t1Xtt5rsmQ0CE0iiTT6QfhQC98UD7oGq3qi4S40vfhO0FM1wz28BsIaNVjmwpyA8v_CSLOq21qEvHxLDM6NDAbywPQOaM1pu4ZauwTYq_10DrQvp4BgywYwrQMttLhxToQbHT2OWaYBic3GSBRwjloJaT3H03XCnGOkWNOpom19B_BG96luGpkZKaicA5EdQnMCjKT1k3wpAD2PDBlcJXWsUcW2Pp9_mlqr7GjuLHLSwGiCfcQE1DLfZzfjqrTsbOqgjT",
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

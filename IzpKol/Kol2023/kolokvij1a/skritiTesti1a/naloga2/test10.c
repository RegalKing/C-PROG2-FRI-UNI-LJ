
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "NQSJdQV_OAjwSKkPkhHVsgwqU6YOUIVl9glkzMXbNh52R16FmO2qF5ZFfApuPY_rQU4TDD1ctSGcWzfkn5N8RS39GKe019S7YTIOcUSgGaDW0zJOgKCmLfk1JpN95bmDB10LnLZH4DozZQjpZBZ9vPOQJ5Y3rtk_hJt0k_HDr9_OIT_4Z7Wgn9PnMxT4lmsFwkzVk4OLmev7z6v1TFSdkZXV8LtedJ1aGIgQmPBy1AR56A3mwiOKed8WdT3uGU_NFPFG49Isut_dPHlYODCKHhJsGXagFQnl7SWtIfhWB4AfQG2KmrnZ4Qz4IwGpKNkn5sYhrmodAGwCLlIU7Sj9Z7lsWJYgQ6oEK0RVxujIuXOsBp9_scGBUeANqb7h_R3CMKAdkASWv_gM0zK1Hr_vA713LUILiREtLY40G4pI_iY3TsvvMbKZDTTc2WEoXXTtJuc1wAquhwXcgAFI8XKq3I1tbYFxGG2VKu",
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

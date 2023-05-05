
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "GB",
    "G3ELkq1cdfpKrEZuoxBEELffn65UC4E8podzhGzpRuv8uHhrwEHIl_jfj64OjDWkwLeJqiHHWI6IQRigW4Qz",
    "JU0voEwk7gZaf6ORW3F5sbv3vs3eLViP9lLD3QgElLKo9C9uDGqavUJgGcQDto",
    "S9Ys2Ka85wJf_F8Z",
    "LAfRl7Bt8R",
    "CQ1g1VEbcF893F9Q4D7eSfyoTOpc5Kn",
    "dnvUF9b82K",
    "r5Z5CUMrZqDeirxC5V",
    "s5Zknv88oaLjjZ_lwM8G6hksj1ybRN4qtWoPaNrqjBLQvw3rUUqFv42YxURLqMnw",
    "Th2OEPxrj7",
    "4D4RwPvw8rYyhEFhdP_NLk16QeB99ifAjeyGal923yzTGlqYvX76QXL1cldglTvQki8RvNz4gNK",
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

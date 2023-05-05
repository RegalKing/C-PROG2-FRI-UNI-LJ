
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "UMPnHmnIY1r7kbs06Vzkn38cXcyP7ihVoQDnIX0qyS1Hd0McFX4PiAejuBK33oYO4sbK9IN9slHxsApbxIGgGowKrQzsg5Zen8teS",
    "5WiOHndUYyUgYJRwyCVnc4m9gA1QQu8dqeTU6_nMSQi2tIN8s7Dca7bmHSbY2wyeZOMHgVWnMaEGscNeUYKLwUj9tX4xBmfaAy19J",
    "cch4t1ww_b6UQgYW10WdEJx28ZBmBVxqXIFImO_XaHjEgumv92CGlVaqwHtgeE0Lp1NyxnBNE9cc1GZSPqx6jFJRsrsq70IBorXtr",
    "dpE8rtQqlcUztjNjnt9KCRg5M32O78vD9OiRkrVhbNNGQHut5blHhVSK6Jf5i9nEHAJhMLRuBZgELd5Z25QHMMy2FSXR8fvXwqEOD",
    "p_m9M33jCd3vz4GDQ2aAuUVDVhka6YD4XZ3e2IeacpPZQfzFAQxOzBtI21v9XE5sIPg12cK01HSvspL95oYG9am_t0ce0exIISOdI",
    "EihybgaJu4EuYVt9MbSnP921Hr6HgvWW1tFHu97MHSx_03CsjjzL6YRW8IVImeQUy8HqSIrtjs6oDlFaQwLOvJWro2JgIMYO9pZAk",
    "ZTveR1VDzhlzVTC9hK_aEKu8e3kePQiNJ4wQDpqclolPtClcTS71nHlBoi0m40O62UnwMB6fcGghyXNdJKdtY3Oi7LzO82rqnm55Y",
    "4AkxBfeHw6Hs1XNvabT5IVopetdDmyRWY8Ke2BMqAl9L1MUk6J0UaIz0kuQoykqklqDvgU6HVqpdMlv9QnSLpxTmhJRBPEAkfIUqW",
    "MaFaCG0E35RyLatDDc_tu4Wg1Aa9lesHWBpRNpWj4r4kNapaAO8RVL5LXojoQk44zvIG4Z6jWBq0hc8PbNoA8lPafPBloYpE8mYG4",
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

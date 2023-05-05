
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "4o07oxOBswayQHyLdiUSycUmpgH9bdPZsoO6mBWLlQ3Jc7JkHOdDpzOx8aaTOQYYE5FbpHPY3xefDqfZapoAxjaHL3sM22pAIXfmpiEvoRdasHVhIu65PlC7EXTIYRjSnggH1GjD86AeyWSfjZYEdCa7HCDumZ5zks62wnQUuT34Bdtclb1Kvih_DTCvh9Vo544oDXd6mN0J5YxxIomP_kuzw1qh53B0z_kmKBBtJgux3yDkUoP_RxeulPc04DzsaycJvc1IGwzJSA_OPjVhYVkNSbIfhc_UVf7Ihj6zg4Nq3Ve2QhS9AUNqBbeeQAFS8AosKMoWB8LGh30dhc6qBpKy3qFZZ7fnxyYpOc4kEQgaBC9uLqKwK9Nos90TmvHfuzQ3h0hEwhvb_oS56vuhpD0pR6Jw7oei6awP9FCj0ec0QZGRzwU0oZaBnLQSzKDhjmYtXwO00HOuZ52CE8W1YkIIkgj6vvt3iR9yO8mf9zsbwSn_mDK_Q9e63ZcEjqdksYFIciidSXTZQGFtyKsDxm4iVHfMM7_DkCQvlmwlY9qDSf22qWAn462t0GrIOmvpCiEkvFOkwIisppGOQQkdx4cEXL7QlZaV2teGQaHzue7XHcENUzpqDGDimRCMgCVrYS4Ywn44pj_8MCblCoAo4fxCAv3EZ9YxvV8HggWeezlcsF9yMAqfQGglty3aJAe5cTs75eShMXPupOq75MSL81JNJV7g21JOaCLjrvCcHvIZ_mRDIlSM0Sh6sNSKXkcIRS22HFOvn8vX_yIOCjOk1AazgWQCory1nETDTwX3q6txSmJxN9tixtooWozYxSNcnHEDtX1nNWaF3azaYaqJkeCbqc8YTd3bGIVz9IO67fXerelnNA8h9Ja6zYQRzcnreiYzOJ8T4Ou9B7gLfSZAXJN4Bkku6eoNmZf",
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

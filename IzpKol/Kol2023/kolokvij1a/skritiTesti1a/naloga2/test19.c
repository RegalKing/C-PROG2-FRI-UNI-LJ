
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "JTfSBVscJi1czCSkupd0",
    "rlu5yIBvhHjvkCmAnS6g",
    "J1F5CZe0jhVTEpta_g9i",
    "f4RXUVFNLfU9y4B6hTrh",
    "yvgxU5AYHbpffdXX4YvJ",
    "Q7OJIH5JAP2P4cUD6UVO",
    "_W86cnH65OIU9soz7Y5B",
    "0UjAGTmyuVYFKcSns2GM",
    "l16xQ1QXIFnecRP1hk2V",
    "k9ntD0kN_mj_QhmvANmp",
    "rRCabcG7VX3wmIdwVADY",
    "p4_Inbh9QAZJMerEZEKz",
    "cPUAkBxEYQaz9UHRTQ2o",
    "LlMcWSNZPICts48oYQ4j",
    "J3bok6wP1KRO71985Rug",
    "VCJNcw4Y6kIus2O9W5r8",
    "H_7FRZ0mLFb6xmYZb3kn",
    "8BD20ghQ2yCMNBlfGKSB",
    "nOREXbuKs_FVOPzvM43J",
    "QBFMAtIL1aX6bIJh6zBs",
    "9yxdDPW1oup7CokczUy2",
    "ugoPAr8sx1Xd7FLIM_bw",
    "_dkLFGie0TZFDqh9nZci",
    "O19Rr_LW3l2mo63DE7R3",
    "9fmMiSWG3a9uzym5RL_T",
    "KY15xRbtEbB3BrgtICxQ",
    "pJiVZ7salpNpffhmrEUy",
    "Y7vdqo_pJlYdUVnJPjHq",
    "kOGQUVEauLcq2fof7105",
    "pioUFZRutJwAoADqi1Lk",
    "KaGXZMfWKKMb7sXMa1fm",
    "Q_I32MLYo7p9Xv1nTaM8",
    "0FfWSOPvaCS1a5RnmsNy",
    "tyWXZ8LFDydhGoL_Pjqb",
    "KR6JgKQOmqXtftcLeAKr",
    "q5GjRMB6S64ubYNWJc3V",
    "GwvbyNGp30Mj5VSnA66B",
    "5fyuQsKh7ix_oM329XBn",
    "eMUVQprjraTpjbiNRaeK",
    "ZSslG7xJ3wOXqE0Ys2qo",
    "SKZa4UAve3NIEwoV55aF",
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

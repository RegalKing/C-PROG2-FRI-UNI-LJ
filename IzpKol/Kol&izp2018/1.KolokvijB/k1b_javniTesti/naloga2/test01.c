
#include "naloga2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NIZ = "O Vrba! srecna, draga vas domaca,";

char ZNAKI[] = {'a', 'V', 'A', ' '};
int ST_ZNAKOV = sizeof(ZNAKI) / sizeof(char);

int __main__() {
    for (int i = 0;  i < ST_ZNAKOV;  i++) {
        int indeks = 0;
        int stPojavitev = pojavitve(NIZ, ZNAKI[i], &indeks);
        printf("\'%c\': %d\n", ZNAKI[i], stPojavitev);
    }
    exit(0);
    return 0;
}

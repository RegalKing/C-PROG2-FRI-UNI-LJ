
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1],"rb");
    FILE* output = fopen(argv[2], "wb");

    int* stevilke = calloc(110000,sizeof(int));
    unsigned char byte;

    int counter=0;
    while (fread(&byte, sizeof(unsigned char), 1, input)!=0){
        stevilke[counter]=byte;
        counter++;
    }

    // for (int i=0; i<counter; i++){
    //     printf("%x ", stevilke[i]);
    // }

    unsigned char* new = malloc (counter*sizeof(unsigned char));
    int bincounter=0;

    for (int i=0; i<counter; i++){
        int current = stevilke[i];
        while (stevilke[i+1]==current){
            i++;
        }
        new[bincounter]=current;
        bincounter++;
            
    }

    fwrite(new, sizeof(unsigned char), bincounter, output);

    return 0;
}

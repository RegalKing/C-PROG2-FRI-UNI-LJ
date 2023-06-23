
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

    int* stevilke = malloc(100000*sizeof(int));
    unsigned char byte;
    int counter = 0;

    while (fread(&byte, sizeof(unsigned char), 1, input)!=0){
        stevilke[counter]=byte;
        counter++;
    }

    for (int i=0; i<counter; i++){
        printf("%d ", stevilke[i]);
    }

    unsigned char* new = malloc(100000*sizeof(unsigned char));
    int bc = 0;

    for (int i=0; i<counter; i++){
        if (stevilke[i]==27 && stevilke[i+1]==201){
            new[bc]=stevilke[i+1];
            bc++;
            i++;
        }
        else{
            new[bc]=stevilke[i];
            bc++;
        }
    }

    fwrite(new, sizeof(unsigned char), bc, output);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char* vrstica = malloc (100001 * sizeof(char));

    int active = 1;

    while ( (fgets(vrstica, 100001, input)) != NULL){
        for (int i=0; vrstica[i]!=0; i++){
            if ( (vrstica[i] == 32) && (active == 1) ){
                continue;
            }
            else if (vrstica[i] != 32 && active == 1){
                active=0;
                fprintf(output, "%c",vrstica[i]);
            }
            else{
                fprintf(output, "%c",vrstica[i]);
            }

        }
        active=1;
    }
}



                

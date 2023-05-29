
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

// (row[i]=="C" || row[i]=="c" || row[i]=="S" || row[i]=="s" || row[i]=="Z" || row[i]=="z")

int main(int argc, char** argv) {
    
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char* row = malloc (10001 * sizeof(char));

// int eligible=0;

    while (fgets(row, 10001, input) != NULL){
        for (int i=0; row[i]!='\0'; i++){
            if(row[i]==34){
                if ((row[i+1]=='C' || row[i+1]=='c' || row[i+1]=='S' || row[i+1]=='s' || row[i+1]=='Z' || row[i+1]=='z')){
                    fprintf(output, "%c",row[i+1]);
                    i++;
                }
                else{
                    fprintf(output, "%c",row[i]);
                }
            }
            
            else{
                // eligible=0;
                fprintf(output,"%c",row[i]);
            }
                
        }
        // fprintf(output,"%c",'\n');
    }


    return 0;
}

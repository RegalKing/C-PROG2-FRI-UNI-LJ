
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char* temp = malloc(100000 * sizeof(char));

    while (fgets(temp,100000,input)!=NULL){
        for (int i=0; temp[i]!='\0'; i++){
            if (i==0 && temp[i]==32){
                while (temp[i]==32){
                    i++;
                }
                i--;
            }
            else{
                fprintf(output, "%c", temp[i]);
            }
        }
    }

}



                

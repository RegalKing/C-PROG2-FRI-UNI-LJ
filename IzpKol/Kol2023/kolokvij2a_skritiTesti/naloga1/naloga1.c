
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* input = fopen(argv[1],"r");
    FILE* output = fopen(argv[2],"w");

    char* temp = calloc(100000,sizeof(char));

    while (fgets(temp, 100000, input)!=NULL){

        for (int i=0; temp[i]!='\0'; i++){
            if (temp[i]=='"' && (temp[i+1]=='C' || temp[i+1]=='c' || temp[i+1]=='S' || temp[i+1]=='s' || temp[i+1]=='Z' || temp[i+1]=='z')){
                fprintf(output,"%c",temp[i+1]);
                i++;
            }
            else{
                fprintf(output,"%c",temp[i]);
            }
        }
    }

    return 0;
}

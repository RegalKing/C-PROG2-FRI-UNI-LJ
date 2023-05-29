#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_LENGTH 1000000

int main (int argc, char** argv){

    FILE* intro = fopen(argv[1],"r");
        if (intro == NULL) {
        perror("Error opening intro file");
    }

    char* row = malloc ( (MAX_LENGTH+1) * sizeof(char));

    fscanf(intro, "%s", row);
    // printf("%s",row);
    FILE* input = fopen(row, "r");
        if (input == NULL) {
        perror("Error opening input file");
    }

    fscanf(intro, "%s", row);;
    // printf("%s\n",row);

    FILE* output = fopen(row, "w");
        if (output == NULL) {
        perror("Error opening output file");
    }

    fscanf(intro, "%s", row);
    // printf("%s\n",row);
    char character = row[0];
    // printf("%c",row[0]);
    
    char* last = malloc ( (MAX_LENGTH+1) * sizeof(char));

    while (fgets(row,MAX_LENGTH+1,input) != NULL){
        // fprintf(output, "TEST: %s", row);
        for (int i=0; row[i]!='\0'; i++){
            if (row[i]==character){
                strcpy(last,row);
                break;
            }
        }
    }

    fprintf(output,"%s",last);
    printf("%s",last);


}


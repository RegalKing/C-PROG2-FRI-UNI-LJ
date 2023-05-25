#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

int main (int argc, char* argv[]) { // lahko tudi char** namesto char* []

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    char* Row = malloc ( (MAX_LENGTH+1) * sizeof(char)); // plus ena zaradi null terminatorja na koncu
    char* longestRow = malloc ((MAX_LENGTH+1) * sizeof(char)); // plus ena zaradi null terminatorja na koncu

    int maxLength = 0;

    while (fgets(Row, MAX_LENGTH+1, input) != NULL) { // fgets deluje kakor kombinacije sc.HasNext in sc.HasNextLine v javi pravi furst
        int dolzina = strlen(Row);
        if (dolzina > maxLength){
            maxLength=dolzina;
            strcpy(longestRow, Row);
        }
    }

    fprintf(output,"%s",longestRow);

    free (Row);
    free (longestRow);
    fclose(input);
    fclose(output);

}
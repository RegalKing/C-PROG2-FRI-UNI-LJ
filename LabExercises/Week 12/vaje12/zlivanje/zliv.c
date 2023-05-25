#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_FILENAME_LENGTH 100

int indexOfMin(int* block, int stDatotek) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < stDatotek; i++) {
        if (block[i] == -1) {
            continue;
        } else {
            if (block[i] < min) {
                min = block[i];
                minIndex = i;
            }
        }
    }

    return minIndex;
}


int main (){

    int stDatotek; // number of input files
    scanf("%d",&stDatotek);

    // Now we must create a table of pointers to opened input files

    char* imeDatoteke = malloc ( (MAX_FILENAME_LENGTH+1) * sizeof(char));
    FILE** inputs = malloc (stDatotek * sizeof(FILE*));

    for (int i=0; i<stDatotek; i++){      // open the input files
        scanf("%s", imeDatoteke);
        inputs[i] = fopen(imeDatoteke, "r");

    }

    scanf("%s", imeDatoteke); // read the output file name
    FILE* output = fopen(imeDatoteke, "w");

    // number of files where we already reached EOF
    int finishedFiles = 0;

    // block[i] = current element of file nr. i, or -1 if we reached EOF
    int* block = malloc (stDatotek * sizeof(int));

    // first elements of all input files are put into block
    // if a file is empty we write -1 in it's block[i] spot

    for (int i=0; i<stDatotek; i++){
        if (fscanf(inputs[i], "%d", &block[i]) < 1){
            block[i]= -1;
            finishedFiles++;
        }
    }

    // for (int i=0; i<stDatotek; i++){                  
    //     printf("%d\n", block[i]);
    // }

    while (finishedFiles < stDatotek){ // print out the lowest number in the array
        int indexMin = indexOfMin(block, stDatotek);
        fprintf(output, "%d\n", block[indexMin]);

        // the number that we write in the output file now must be replaced by the next number in the input file of the output number, or -1 if we have hit EOF

    if (fscanf(inputs[indexMin], "%d", &block[indexMin]) < 1){
        block[indexMin] = -1;
        finishedFiles++;
        }
    }
    
    
    



    for (int i=0; i<stDatotek; i++){
        fclose(inputs[i]);
    }

    fclose(output);

    free(block);
    free (imeDatoteke);
    free (inputs);

}
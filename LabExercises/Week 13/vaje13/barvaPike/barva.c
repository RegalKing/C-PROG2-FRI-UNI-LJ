#include <stdio.h>
#include <stdlib.h>



int main (int argc, char** argv){

    FILE* input = fopen(argv[1], "rb");
    
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    char* string = malloc (10 * sizeof(char));

    fgets(string, 10, input); // preberemo P6 \n

    // printf("%s",string);

    int width, height;
    fscanf(input, "%d %d", &width, &height);
    fgets(string, 10, input);
    // printf("%s",string);
    fgets(string, 10, input);
    // printf("%s",string);

    unsigned char* binary = malloc(3*width*height*sizeof(unsigned char));

    fread(binary, sizeof(unsigned char), 3*width*height, input);

    int index = 3*(vrstica*width +  stolpec);
    printf("%d %d %d", binary[index], binary[index+1], binary[index+2]);

}
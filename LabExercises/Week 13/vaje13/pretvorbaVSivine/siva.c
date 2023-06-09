#include <stdio.h>
#include <stdlib.h>


int main (int argc, char** argv){

    FILE* input = fopen(argv[1], "rb");
    char* temp = malloc (10 * sizeof(char));

    int width;
    int height;

    fgets(temp, 10, input); // read useless P5 and /n
    fscanf(input, "%d %d", &width, &height);
    fgets(temp, 10, input); // read useless /n after the numbers
    fgets(temp, 10, input); // read useless 255 and /n

    unsigned char* colors = malloc (3*width*height*sizeof(unsigned char));
    fread(colors, sizeof(unsigned char), 3*width*height, input);
    fclose(input);
    FILE* output = fopen(argv[2], "wb");

    unsigned char* grays = malloc (width*height*sizeof(unsigned char));
    int colorIndex = 0; // index of the component of the current pixel 
    int grayIndex = 0;

    for (int i=0; i<width; i++){
        for (int j=0; j<height; j++){
            grays[grayIndex]=( ( 30*colors[colorIndex] + 59*colors[colorIndex+1] + 11*colors[colorIndex+2] ) / 100 );
            colorIndex+=3;
            grayIndex++;
        }
    }

    fprintf(output, "P5\n");
    fprintf(output, "%d %d\n", width, height);
    fprintf(output, "255\n");

    fwrite(grays, sizeof(unsigned char), width*height, output);


    


}

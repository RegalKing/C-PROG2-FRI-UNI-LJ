
/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int main(int argc, char** argv) {
    
    FILE* input = fopen(argv[1],"rb");

    char* temp = malloc (10* sizeof(char));

    fgets(temp, 10, input); // p5 and newline

    int width;
    int height;
    fscanf(input, "%d %d", &width, &height);
    fgets(temp, 10, input); // newline after w and h
    fgets(temp, 10, input); // 255 and newline

    unsigned char* bits = malloc(3*width*height*sizeof(unsigned char));
    fread(bits, sizeof(unsigned char), width*height, input);

    int IndexCounter = 0;

    int prag = atoi(argv[2]);

    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (bits[IndexCounter]<prag){    // red
                bits[IndexCounter]=0;
            }
            else{
                bits[IndexCounter]=255;
            }
            if (bits[IndexCounter+1]<prag){ // green
                bits[IndexCounter+1]=0;
            }
            else{
                bits[IndexCounter+1]=255;
            }
            if (bits[IndexCounter+2]<prag){ // blue
                bits[IndexCounter+2]=0;
            }
            else{
                bits[IndexCounter+2]=255;
            }

            IndexCounter+=3; // go to the next pixel
        }
    }
    fclose(input);
    FILE* output = fopen (argv[3], "wb");

    fprintf(output, "P5\n");
    fprintf(output,"%d %d\n", width, height);
    fprintf(output, "255\n");


    fwrite(bits, sizeof(unsigned char), width*height, output);

    fclose(output);
    return 0;
}

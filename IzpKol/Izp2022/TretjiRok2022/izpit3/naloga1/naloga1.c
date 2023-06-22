
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
    
    FILE* input = fopen(argv[1], "rb");
    int prag = atoi(argv[2]);
    FILE* output = fopen(argv[3], "wb");

    char* temp = malloc(sizeof(char)*10);

    fgets(temp, 10, input);
    int width, height;
    fscanf(input, "%d %d %s", &width, &height, temp);
    fgets(temp, 10, input);

    unsigned char* binary = malloc(width*height*sizeof(unsigned char));

    fread(binary, sizeof(unsigned char), width*height, input);

    for (int i=0; i<width*height; i++){
        if (binary[i]<prag){
            binary[i]=0;
        }
        else{
            binary[i]=255;
        }
    }


    fprintf(output, "P5\n");
    fprintf(output, "%d %d\n", width, height);
    fprintf(output, "255\n");
    fwrite(binary, sizeof(unsigned char), width*height, output);



}
